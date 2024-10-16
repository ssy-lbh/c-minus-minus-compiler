%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

#include "parse.tab.h"
#include "ir.h"

void yyerror(char *s);

int line = 1;

long num;
double real;
char name[1000];

ir_program *program = NULL;

ir_func_ctx *f_stack[0x40];
int f_top = -1;

loop_info *l_stack[0x40];
int l_top = -1;

char translate(char c){
    switch (c){
    case 'n': return '\n';
    case 'r': return '\r';
    case 't': return '\t';
    case 'b': return '\b';
    case '0': return '\0';
    case 'a': return '\a';
    case '\"': return '\"';
    case '\'': return '\'';
    case '\\': return '\\';
    case 'f': return '\f';
    case 'v': return '\v';
    }
    printf("Unknown character '\\%c'\n", c);
    return '\0';
}
%}

line_comment (\/\/.*\n)
block_comment (\/\*.*\*\/)

digit [0-9]
letter [a-zA-Z]
delim [ \r\t\n]
semicolon [\;]

int2 (0[Bb]([0-1])+)
int8 (0([0-7])+)
int10 ([1-9]|[1-9]([0-9])+|0)
int16 (0[xX]([A-Fa-f0-9])+)

real ([0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?|[0-9]+[eE][+-]?[0-9]+)

name ({letter}|_)({letter}|{digit}|_)*
operator \+|-|\*|\/|%|<=|<|==|!=|=|>=|>|<<|>>|&|\^|\||~|&&|\|\||!|\?|:|,|\.|->|\(|\)|\[|\]|\{|\}|\+\+|--|\+=|-=|\*=|\/=|%=|&=|\^=|\|=|<<=|>>=
whitespace {delim}+
str \"([^"]|\\\")*\"
char \'([^']|\\\')*\'
preprocessor #(.|\\\n)*\n
other .

%%
{int2} {
    printf("%d:(Int2, %s)\n", line, yytext);

    num = strtol(yytext + 2, NULL, 2);
    return NUMBER;
}
{int8} {
    printf("%d:(Int8, %s)\n", line, yytext);

    num = strtol(yytext + 1, NULL, 8);
    return NUMBER;
}
{int10} {
    printf("%d:(Int10, %s)\n", line, yytext);

    num = strtol(yytext, NULL, 10);
    return NUMBER;
}
{int16} {
    printf("%d:(Int16, %s)\n", line, yytext);

    num = strtol(yytext + 2, NULL, 16);
    return NUMBER;
}
{real} {
    printf("%d:(Real, %s)\n", line, yytext);

    real = strtod(yytext, NULL);
    return REAL;
}
{name} {
    printf("%d:(Name, %s)\n", line, yytext);
    
    if (!strcmp(yytext, "while")) return WHILE;
    if (!strcmp(yytext, "if")) return IF;
    if (!strcmp(yytext, "else")) return ELSE;
    if (!strcmp(yytext, "for")) return FOR;

    if (!strcmp(yytext, "return")) return RETURN;

    if (!strcmp(yytext, "void")) return VOID;
    if (!strcmp(yytext, "int") || !strcmp(yytext, "char")) return INT;
    if (!strcmp(yytext, "float")) return FLOAT;

    if (!strcmp(yytext, "break")) return BREAK;
    if (!strcmp(yytext, "continue")) return CONTINUE;

    strcpy(name, yytext);

    if (f_top >= 0 && ir_func_ctx_get_flag(f_stack[f_top], yytext)) return FNAME;

    return NAME;
}
{operator} {
    printf("%d:(Operator, %s)\n", line, yytext);
    if (!strcmp(yytext, "<=")) return LE;
    if (!strcmp(yytext, ">=")) return GE;
    if (!strcmp(yytext, "==")) return EQ;
    if (!strcmp(yytext, "!=")) return NE;
    if (!strcmp(yytext, "<<")) return SHL;
    if (!strcmp(yytext, ">>")) return SHR;
    if (!strcmp(yytext, "&&")) return AND;
    if (!strcmp(yytext, "||")) return OR;
    if (!strcmp(yytext, "->")) return ARROW;
    if (!strcmp(yytext, "++")) return INC;
    if (!strcmp(yytext, "--")) return DEC;
    if (!strcmp(yytext, "+=")) return ADD_ASSIGN;
    if (!strcmp(yytext, "-=")) return SUB_ASSIGN;
    if (!strcmp(yytext, "*=")) return MUL_ASSIGN;
    if (!strcmp(yytext, "/=")) return DIV_ASSIGN;
    if (!strcmp(yytext, "%=")) return MOD_ASSIGN;
    if (!strcmp(yytext, "&=")) return AND_ASSIGN;
    if (!strcmp(yytext, "^=")) return XOR_ASSIGN;
    if (!strcmp(yytext, "|=")) return OR_ASSIGN;
    if (!strcmp(yytext, "<<=")) return SHL_ASSIGN;
    if (!strcmp(yytext, ">>=")) return SHR_ASSIGN;
    return *yytext;
}
{whitespace} {
    printf("%d:(Whitespace)\n", line);
    size_t len = strlen(yytext);
    for (size_t i = 0; i < len; i++) {
        if (yytext[i] == '\n') line++;
    }
}
{str} {
    printf("%d:(String, %s)\n", line, yytext);
    size_t len = strlen(yytext);
    size_t p = 0;
    for (size_t i = 1; i < len - 1; i++, p++) {
        if (yytext[i] == '\\'){
            name[p] = translate(yytext[++i]);
            continue;
        }
        name[p] = yytext[i];
    }
    name[p] = '\0';
    return STR;
}
{char} {
    num = yytext[1];
    if (yytext[1] == '\\')
        num = translate(yytext[2]);
    return CHAR;
}
{semicolon} {
    printf("%d:(Semicolon, %s)\n", line, yytext);
    return ';';
}
{line_comment} {
    printf("%d:(Line Comment, %s)\n", line, yytext);
}
{block_comment} {
    printf("%d:(Block Comment, %s)\n", line, yytext);
}
{preprocessor} {
    printf("%d:(Preprocessor, %s)\n", line, yytext);
}
{other} {
    printf("%d:(Other, %s)\n", line, yytext);
    yyerror("Illegal Character!");
}
%%

void yyerror(char *s){
    fprintf(stderr, "Error: %s\n", s);
}

/*
int main(int argc, char **argv){
    if (argc < 2){
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f){
        fprintf(stderr, "Error: Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    yyin = f;
    while (yylex() != 0);
    fclose(f);

    return 0;
}
*/