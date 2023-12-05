%token NUMBER
%token NAME
%token SEMICOLON

%token IF
%token WHILE
%token RETURN

%token INT
%token VOID

%token LE
%token GE
%token EQ
%token NE
%token SHL
%token SHR
%token SAR

%left IF ELSE WHILE RETURN
%left '(' ')' '[' ']' '{' '}'
%left ','
%left '='
%left '<' '>' LE GE EQ NE SHL SHR SAR
%left '+' '-'
%left '*' '/'

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"
#include "ir.h"
#include "vm.h"

int yylex();
void yyerror(char *s);

ir_program *program = NULL;

ir_func_ctx *f_stack[0x40];
int f_top = -1;

extern long num;
extern char name[0x400];
extern FILE* yyin;
%}

%%
program:
    | program stmt
    ;
stmt:
    expr SEMICOLON
    | decl
    | if stmt { f_stack[f_top]->f->code[$1].op2 = f_stack[f_top]->f->code_num; }
    | while_start while_cond stmt { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_JMP, $1, 0, 0)); f_stack[f_top]->f->code[$2].op2 = f_stack[f_top]->f->code_num; }
    | '{' program '}'
    | RETURN expr SEMICOLON { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, $2, 0, 0)); }
    | RETURN SEMICOLON { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, 0, 0, 0)); }
    | SEMICOLON
    ;
if:
    IF '(' expr ')' { $$ = f_stack[f_top]->f->code_num; ir_func_add_code(f_stack[f_top]->f, ir_new(IR_JMPNOT, $3, 0, 0)); }
    ;
while_cond:
    '(' expr ')' { $$ = ir_func_add_code(f_stack[f_top]->f, ir_new(IR_JMPNOT, $2, 0, 0)); }
    ;
while_start:
    WHILE { $$ = f_stack[f_top]->f->code_num; }
    ;
decl:
    INT NAME {
        printf("Declaration: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name);
    } SEMICOLON
    | INT NAME {
        printf("Declaration: %s = %ld\n", name, num);
        int id = ir_func_ctx_add_local(f_stack[f_top], name);
        ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, id, num, 0));
    } '=' expr SEMICOLON
    | VOID NAME {
        printf("Function %s\n", name);
        f_stack[++f_top] = ir_func_ctx_new(ir_func_new(name, 0));
        ir_program_add_func(program, f_stack[f_top]->f);
    } '(' para_decl ')' '{' program '}' {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, 0, 0, 0));
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, 0, 0, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
    | INT NAME {
        printf("Function %s\n", name);
        f_stack[++f_top] = ir_func_ctx_new(ir_func_new(name, 0));
        ir_program_add_func(program, f_stack[f_top]->f);
    } '(' para_decl ')' '{' program '}' {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, 0, 0, 0));
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, 0, 0, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
    ;
expr:
    NUMBER { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, $$, num, 0)); }
    | NAME { $$ = ir_func_ctx_get_local(f_stack[f_top], name); }
    | expr '=' expr { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MOV, $1, $3, 0)); }
    | expr '+' expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ADD, $$, $1, $3)); }
    | expr '-' expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SUB, $$, $1, $3)); }
    | expr '*' expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MUL, $$, $1, $3)); }
    | expr '/' expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_DIV, $$, $1, $3)); }
    | expr '<' expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LT, $$, $1, $3)); }
    | expr '>' expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_GT, $$, $1, $3)); }
    | expr LE expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LE, $$, $1, $3)); }
    | expr GE expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_GE, $$, $1, $3)); }
    | expr EQ expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_EQ, $$, $1, $3)); }
    | expr NE expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_NE, $$, $1, $3)); }
    | expr SHL expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SHL, $$, $1, $3)); }
    | expr SHR expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SHR, $$, $1, $3)); }
    | expr SAR expr { $$ = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SAR, $$, $1, $3)); }
    | '(' expr ')' { $$ = $2; }
    | function '(' para_list ')' {
        int id = ir_func_ctx_inc_local(f_stack[f_top]);
        ir i = ir_new(IR_CALL, 0, 0, id);
        i.op = f_stack[f_top]->f->code[$1].op;
        f_stack[f_top]->f->code[$1].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
        $$ = id;
    }
    ;
function:
    NAME {
        printf("Function Call: %s\n", name);
        ir i = ir_new(IR_PARAM, 0, 0, 0);
        int len = strlen(name);
        i.op = (char*)malloc(len + 1);
        strcpy(i.op, name);
        $$ = ir_func_add_code(f_stack[f_top]->f, i);
    }
    ;
para_decl:
    INT NAME {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name);
    }
    | VOID
    | INT NAME {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name);
    } ',' para_decl
    |
    ;
para_list:
    expr { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_PASS, $1, 0, 0)); }
    | expr ',' para_list { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_PASS, $1, 0, 0)); }
    |
    ;
%%

void func_foreach(char* name, void* value){
    printf("Function: %s\n", name);
    ir_func* f = (ir_func*)value;
    for (int i = 0; i < f->code_num; i++){
        ir_print(f->code[i]);
    }
}

int main(int argc, char** argv){
    if (argc > 1){
        yyin = fopen(argv[1], "r");
        if (!yyin){
            printf("Cannot open file %s\n", argv[1]);
            return 1;
        }
        printf("Parsing %s...\n", argv[1]);
    } else {
        printf("Parsing from stdin...\n");
    }

    program = ir_program_new();

    //yydebug = 1;
    yyparse();

    printf("\nParsing finished.\n");
    dict_foreach(program->func_dict, func_foreach);

    vm_add_native(program);
    vm_ctx* ctx = vm_ctx_new();
    int ret = vm_run(ctx, program, "main");
    printf("Process exited with code %d\n", ret);

    ir_program_free(program);

    return 0;
}