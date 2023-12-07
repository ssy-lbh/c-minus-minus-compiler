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
char name[1000];
%}

line_comment (\/\/.*\n)
block_comment (\/\*.*\*\/)

digit [0-9]
letter [a-zA-Z]
delim [ \r\t\n]
semicolon [\;]

number {digit}+
name ({letter}|_)({letter}|{digit}|_)*
operator \+|-|\*|\/|%|<=|<|==|=|>=|>|<<|>>|&|\^|\||~|&&|\|\||!|\?|:|,|\.|->|\(|\)|\[|\]|\{|\}
whitespace {delim}+
str \"[^"]*\"
preprocessor #(.|\\\n)*\n
other .

%%
{number} {
    //printf("%d:(Number, %s)\n", line, yytext);

    num = strtol(yytext, NULL, 10);
    return NUMBER;
}
{name} {
    //printf("%d:(Name, %s)\n", line, yytext);
    
    if (!strcmp(yytext, "while")) return WHILE;
    if (!strcmp(yytext, "if")) return IF;

    if (!strcmp(yytext, "return")) return RETURN;

    if (!strcmp(yytext, "void")) return VOID;
    if (!strcmp(yytext, "int")) return INT;
    if (!strcmp(yytext, "float")) return FLOAT;

    strcpy(name, yytext);
    return NAME;
}
{operator} {
    //printf("%d:(Operator, %s)\n", line, yytext);
    if (!strcmp(yytext, "<=")) return LE;
    if (!strcmp(yytext, ">=")) return GE;
    if (!strcmp(yytext, "==")) return EQ;
    if (!strcmp(yytext, "!=")) return NE;
    if (!strcmp(yytext, "<<")) return SHL;
    if (!strcmp(yytext, ">>")) return SHR;
    if (!strcmp(yytext, "&&")) return AND;
    if (!strcmp(yytext, "||")) return OR;
    if (!strcmp(yytext, "->")) return ARROW;
    return *yytext;
}
{whitespace} {
    //printf("%d:(Whitespace)\n", line);
    int len = strlen(yytext);
    for (int i = 0; i < len; i++) {
        if (yytext[i] == '\n') line++;
    }
}
{str} {
    //printf("%d:(String, %s)\n", line, yytext);
}
{semicolon} {
    //printf("%d:(Semicolon, %s)\n", line, yytext);
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