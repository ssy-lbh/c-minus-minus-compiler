%token NUMBER
%token NAME

%token IF
%token WHILE
%token RETURN

%token VOID
%token INT
%token FLOAT

%token STR
%token CHAR

%token LE
%token GE
%token EQ
%token NE
%token SHL
%token SHR
%token AND
%token OR
%token ARROW
%token INC
%token DEC
%token ADD_ASSIGN
%token SUB_ASSIGN
%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token SHL_ASSIGN
%token SHR_ASSIGN
%token AND_ASSIGN
%token XOR_ASSIGN
%token OR_ASSIGN

%left ';'
%left IF ELSE WHILE RETURN
%left '(' ')' '[' ']' '{' '}'
%left ','
%right '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN SHL_ASSIGN SHR_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%left AND OR
%left '<' '>' LE GE EQ NE SHL SHR
%left '^' '&' '|'
%left '+' '-'
%left '*' '/' '%'
%left '~' '!' INC DEC
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
%nterm func_name var_decl func_decl

%%
program:
    | program stmt
    ;
stmt:
    expr ';' {}
    | decl {}
    | if stmt { f_stack[f_top]->f->code[$1].op1.ival = f_stack[f_top]->f->code_num; }
    | while_start while_cond stmt { ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, $1)); f_stack[f_top]->f->code[$2].op1.ival = f_stack[f_top]->f->code_num; }
    | '{' program '}' {}
    | RETURN expr ';' { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, $2)); }
    | RETURN ';' { ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0)); }
    | ';' {}
    ;
if:
    IF '(' expr ')' { $$ = f_stack[f_top]->f->code_num; ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, $3)); }
    ;
while_cond:
    '(' expr ')' { $$ = ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, $2)); }
    ;
while_start:
    WHILE { $$ = f_stack[f_top]->f->code_num; }
    ;
decl:
    var_decl
    | func_decl
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
    NUMBER { $$ = ir_expr_imm(num); }
    | CHAR { $$ = ir_expr_imm(num); }
    | NAME { $$ = ir_expr_var(ir_func_ctx_get_local(f_stack[f_top], name)); }
    | STR { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_lea($$, name)); }
    | expr '=' expr { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, $1, $3)); $$ = $1; }
    | expr '+' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, $$, $1, $3)); }
    | expr '-' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, $$, $1, $3)); }
    | expr '*' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, $$, $1, $3)); }
    | expr '/' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, $$, $1, $3)); }
    | expr '%' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, $$, $1, $3)); }
    | expr '<' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LT, $$, $1, $3)); }
    | expr '>' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GT, $$, $1, $3)); }
    | expr LE expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LE, $$, $1, $3)); }
    | expr GE expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GE, $$, $1, $3)); }
    | expr EQ expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_EQ, $$, $1, $3)); }
    | expr NE expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_NE, $$, $1, $3)); }
    | expr SHL expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, $$, $1, $3)); }
    | expr SHR expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, $$, $1, $3)); }
    | '-' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NEG, $$, $2)); }
    | '+' expr { $$ = $2; }
    | '~' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NOT, $$, $2)); }
    | '!' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_LOGIC_NOT, $$, $2)); }
    | expr '&' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, $$, $1, $3)); }
    | expr '|' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, $$, $1, $3)); }
    | expr '^' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, $$, $1, $3)); }
    | expr AND expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_AND, $$, $1, $3)); }
    | expr OR expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_OR, $$, $1, $3)); }
    | expr INC { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, $1, $1, ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, $$, $1)); }
    | expr DEC { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, $1, $1, ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, $$, $1)); }
    | INC expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, $2, $2, ir_expr_imm(1))); $$ = $2; }
    | DEC expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, $2, $2, ir_expr_imm(1))); $$ = $2; }
    | expr ADD_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, $1, $1, $3)); $$ = $1; }
    | expr SUB_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, $1, $1, $3)); $$ = $1; }
    | expr MUL_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, $1, $1, $3)); $$ = $1; }
    | expr DIV_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, $1, $1, $3)); $$ = $1; }
    | expr MOD_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, $1, $1, $3)); $$ = $1; }
    | expr SHL_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, $1, $1, $3)); $$ = $1; }
    | expr SHR_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, $1, $1, $3)); $$ = $1; }
    | expr AND_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, $1, $1, $3)); $$ = $1; }
    | expr XOR_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, $1, $1, $3)); $$ = $1; }
    | expr OR_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, $1, $1, $3)); $$ = $1; }
    | '(' expr ')' { $$ = $2; }
    | '&' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ($2.is_imm){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, $$, $2)); }
    | '*' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_DEREF, $$, $2)); }
    | expr '[' expr ']' { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, $$, ir_expr_imm($1.ival), $3)); $$ = ir_expr_ref($$.ival); }
    | func_call '(' para_list ')' {
        $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top]));
        ir i = ir_new1(IR_CALL, $$);
        i.op = f_stack[f_top]->f->code[$1].op;
        f_stack[f_top]->f->code[$1].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
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
        ir i = ir_new0(IR_PARAM);
        i.op = strdup(name);
        $$ = ir_func_add_code(f_stack[f_top]->f, i);
    }
    ;
type_name:
    INT
    | VOID
    | type_name '*'
    ;
var_decl:
    type_name var_name ';' {
        ir_func_ctx_add_local(f_stack[f_top], $2, 1);
        free($2);
    }
    | type_name var_name '=' expr ';' {
        expr_info id = ir_expr_var(ir_func_ctx_add_local(f_stack[f_top], $2, 1));
        free($2);
        ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, id, $4));
    }
    | type_name var_name '[' constexpr ']' ';' {
        int length = (int)$4;
        ir_func_ctx_add_local(f_stack[f_top], $2, length);
        free($2);
    }
func_decl:
    type_name func_name '(' para_decl ')' '{' program '}' {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
para_decl:
    type_name NAME {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
    | VOID
    | type_name NAME {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    } ',' para_decl
    | {}
    ;
para_list:
    expr { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, $1)); }
    | para_list ',' expr { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, $3)); }
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