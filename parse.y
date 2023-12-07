%token NUMBER
%token NAME
%token SEMICOLON

%token IF
%token WHILE
%token RETURN

%token VOID
%token INT
%token FLOAT

%token LE
%token GE
%token EQ
%token NE
%token SHL
%token SHR
%token AND
%token OR
%token ARROW

%left IF ELSE WHILE RETURN
%left '(' ')' '[' ']' '{' '}'
%left ','
%left '='
%left AND OR
%left '<' '>' LE GE EQ NE SHL SHR
%left '^' '&' '|'
%left '+' '-'
%left '*' '/' '%'
%left '~' '!'
%left '.' ARROW

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

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

%start program

%union {
    long long num;
    char* name;
    expr_info value;
}

%nterm <num> constexpr para_list func_call if while_start while_cond stmt
%nterm <name> var_name
%nterm <value> expr
%nterm func_name

%%
program:
    | program stmt
    ;
stmt:
    expr SEMICOLON {}
    | decl {}
    | if stmt { f_stack[f_top]->f->code[$1].op2 = f_stack[f_top]->f->code_num; }
    | while_start while_cond stmt { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_JMP, $1, 0, 0)); f_stack[f_top]->f->code[$2].op2 = f_stack[f_top]->f->code_num; }
    | '{' program '}' {}
    | RETURN expr SEMICOLON { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, $2.ival, 0, 0)); }
    | RETURN SEMICOLON { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, 0, 0, 0)); }
    | SEMICOLON {}
    ;
if:
    IF '(' expr ')' { $$ = f_stack[f_top]->f->code_num; ir_func_add_code(f_stack[f_top]->f, ir_new(IR_JMPNOT, $3.ival, 0, 0)); }
    ;
while_cond:
    '(' expr ')' { $$ = ir_func_add_code(f_stack[f_top]->f, ir_new(IR_JMPNOT, $2.ival, 0, 0)); }
    ;
while_start:
    WHILE { $$ = f_stack[f_top]->f->code_num; }
    ;
decl:
    INT var_name SEMICOLON {
        ir_func_ctx_add_local(f_stack[f_top], $2, 1);
        free($2);
    }
    | INT var_name '=' expr SEMICOLON {
        int id = ir_func_ctx_add_local(f_stack[f_top], $2, 1);
        free($2);
        ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MOV, id, $4.ival, 0));
    }
    | INT var_name '[' constexpr ']' SEMICOLON {
        long long length = $4;
        ir_func_ctx_add_local(f_stack[f_top], $2, length);
        free($2);
    }
    | VOID func_name '(' para_decl ')' '{' program '}' {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, 0, 0, 0));
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, 0, 0, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
    | INT func_name '(' para_decl ')' '{' program '}' {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, 0, 0, 0));
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, 0, 0, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
    ;
var_name:
    NAME {
        printf("Declaration: %s\n", name);
        $$ = strdup(name);
    }
    ;
func_name:
    NAME {
        printf("Function: %s\n", name);
        f_stack[++f_top] = ir_func_ctx_new(ir_func_new(name, 0));
        ir_program_add_func(program, f_stack[f_top]->f);
    }
    ;
expr:
    NUMBER { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, $$.ival, num, 0)); }
    | NAME { $$.ival = ir_func_ctx_get_local(f_stack[f_top], name); }
    | expr '=' expr { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MOV, $1.ival, $3.ival, 0)); }
    | expr '+' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ADD, $$.ival, $1.ival, $3.ival)); }
    | expr '-' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SUB, $$.ival, $1.ival, $3.ival)); }
    | expr '*' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MUL, $$.ival, $1.ival, $3.ival)); }
    | expr '/' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_DIV, $$.ival, $1.ival, $3.ival)); }
    | expr '%' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MOD, $$.ival, $1.ival, $3.ival)); }
    | expr '<' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LT, $$.ival, $1.ival, $3.ival)); }
    | expr '>' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_GT, $$.ival, $1.ival, $3.ival)); }
    | expr LE expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LE, $$.ival, $1.ival, $3.ival)); }
    | expr GE expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_GE, $$.ival, $1.ival, $3.ival)); }
    | expr EQ expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_EQ, $$.ival, $1.ival, $3.ival)); }
    | expr NE expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_NE, $$.ival, $1.ival, $3.ival)); }
    | expr SHL expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SHL, $$.ival, $1.ival, $3.ival)); }
    | expr SHR expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SHR, $$.ival, $1.ival, $3.ival)); }
    | '-' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_NEG, $$.ival, $2.ival, 0)); }
    | '~' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_NOT, $$.ival, $2.ival, 0)); }
    | '!' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LOGIC_NOT, $$.ival, $2.ival, 0)); }
    | expr '&' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_AND, $$.ival, $1.ival, $3.ival)); }
    | expr '|' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_OR, $$.ival, $1.ival, $3.ival)); }
    | expr '^' expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_XOR, $$.ival, $1.ival, $3.ival)); }
    | expr AND expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LOGIC_AND, $$.ival, $1.ival, $3.ival)); }
    | expr OR expr { $$.ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LOGIC_OR, $$.ival, $1.ival, $3.ival)); }
    | '(' expr ')' { $$.ival = $2.ival; }
    | func_call '(' para_list ')' {
        int id = ir_func_ctx_inc_local(f_stack[f_top]);
        ir i = ir_new(IR_CALL, id, 0, 0);
        i.op = f_stack[f_top]->f->code[$1].op;
        f_stack[f_top]->f->code[$1].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
        $$.ival = id;
    }
    ;
constexpr:
    NUMBER { $$ = num; }
    | constexpr '+' constexpr { $$ = $1 + $3; }
    | constexpr '-' constexpr { $$ = $1 - $3; }
    | constexpr '*' constexpr { $$ = $1 * $3; }
    | constexpr '/' constexpr { $$ = $1 / $3; }
    | constexpr '%' constexpr { $$ = $1 % $3; }
    | constexpr '<' constexpr { $$ = $1 < $3; }
    | constexpr '>' constexpr { $$ = $1 > $3; }
    | constexpr LE constexpr { $$ = $1 <= $3; }
    | constexpr GE constexpr { $$ = $1 >= $3; }
    | constexpr EQ constexpr { $$ = $1 == $3; }
    | constexpr NE constexpr { $$ = $1 != $3; }
    | constexpr SHL constexpr { $$ = $1 << $3; }
    | constexpr SHR constexpr { $$ = $1 >> $3; }
    | '-' constexpr { $$ = -$2; }
    | '~' constexpr { $$ = ~$2; }
    | '!' constexpr { $$ = !$2; }
    | constexpr '&' constexpr { $$ = $1 & $3; }
    | constexpr '|' constexpr { $$ = $1 | $3; }
    | constexpr '^' constexpr { $$ = $1 ^ $3; }
    | constexpr AND constexpr { $$ = $1 && $3; }
    | constexpr OR constexpr { $$ = $1 || $3; }
    | '(' constexpr ')' { $$ = $2; }
    ;
func_call:
    NAME {
        printf("Function Call: %s\n", name);
        ir i = ir_new(IR_PARAM, 0, 0, 0);
        i.op = strdup(name);
        $$ = ir_func_add_code(f_stack[f_top]->f, i);
    }
    ;
para_decl:
    INT NAME {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
    | VOID
    | INT NAME {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    } ',' para_decl
    | {}
    ;
para_list:
    expr { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_PASS, $1.ival, 0, 0)); }
    | para_list ',' expr { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_PASS, $3.ival, 0, 0)); }
    | {}
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
    int ret = (int)vm_run(ctx, program, "main");
    printf("Process exited with code %d\n", ret);

    ir_program_free(program);

    return 0;
}