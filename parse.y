%token NUMBER
%token REAL
%token NAME
%token FNAME

%token IF
%token ELSE
%token WHILE
%token FOR
%token RETURN

%token BREAK
%token CONTINUE

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
#include "type.h"

int yylex();
void yyerror(char *s);

extern ir_program *program;

extern ir_func_ctx *f_stack[0x40];
extern int f_top;

extern loop_info *l_stack[0x40];
extern int l_top;

extern long num;
extern double real;
extern char name[0x400];
extern FILE* yyin;
%}

%start program

%union {
    long long num;
    char* name;
    expr_info value;
}

%nterm <num> constexpr para_list func_call ffunc_call if else while_start while_cond stmt stmt_no_if for for_var_decl for_cond for_inc
%nterm <name> var_name
%nterm <value> expr fexpr
%nterm func_name var_decl func_decl

%%
program:
    | program stmt
    ;
stmt:
    expr ';' {}
    | fexpr ';' {}
    | decl {}
    | if stmt {
        f_stack[f_top]->f->code[$1].op1.ival = f_stack[f_top]->f->code_num;
    }
    | if stmt_no_if else stmt {
        f_stack[f_top]->f->code[$1].op1.ival = $3 + 1;
        f_stack[f_top]->f->code[$3].op2.ival = f_stack[f_top]->f->code_num;
    }
    | while_start while_cond stmt {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, $1));
        f_stack[f_top]->f->code[$2].op1.ival = f_stack[f_top]->f->code_num;
        ir_loop_info_apply_and_pop(f_stack[f_top]->f->code_num, $1);
    }
    | for stmt {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, $1));
        f_stack[f_top]->f->code[$1 - 2].op2.ival = f_stack[f_top]->f->code_num;
        ir_loop_info_apply_and_pop(f_stack[f_top]->f->code_num, $1);
    }
    | '{' program '}' {}
    | RETURN expr ';' {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, $2));
    }
    | RETURN ';' {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
    }
    | BREAK ';' {
        ir_loop_info_add(LOOP_BREAK, f_stack[f_top]->f->code_num);
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
    | CONTINUE ';' {
        ir_loop_info_add(LOOP_CONTINUE, f_stack[f_top]->f->code_num);
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
    | ';' {}
    ;
stmt_no_if:
    expr ';' {}
    | fexpr ';' {}
    | decl {}
    | if stmt_no_if else stmt_no_if {
        f_stack[f_top]->f->code[$1].op1.ival = $3 + 1;
        f_stack[f_top]->f->code[$3].op2.ival = f_stack[f_top]->f->code_num;
    }
    | while_start while_cond stmt_no_if {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, $1));
        f_stack[f_top]->f->code[$2].op1.ival = f_stack[f_top]->f->code_num;
        ir_loop_info_apply_and_pop(f_stack[f_top]->f->code_num, $1);
    }
    | for stmt_no_if {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, $1));
        f_stack[f_top]->f->code[$1 - 2].op2.ival = f_stack[f_top]->f->code_num;
        ir_loop_info_apply_and_pop(f_stack[f_top]->f->code_num, $1);
    }
    | '{' program '}' {}
    | RETURN expr ';' {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, $2));
    }
    | RETURN ';' {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
    }
    | BREAK ';' {
        ir_loop_info_add(LOOP_BREAK, f_stack[f_top]->f->code_num);
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
    | CONTINUE ';' {
        ir_loop_info_add(LOOP_CONTINUE, f_stack[f_top]->f->code_num);
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
    | ';' {}
    ;
if:
    IF '(' expr ')' {
        $$ = f_stack[f_top]->f->code_num;
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, $3));
    }
    ;
else:
    ELSE {
        $$ = f_stack[f_top]->f->code_num;
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
    ;
for:
    FOR '(' for_var_decl for_cond ';' for_inc ')' {
        f_stack[f_top]->f->code[$4 - 1].op1.ival = f_stack[f_top]->f->code_num;
        f_stack[f_top]->f->code[$6 - 1].op1.ival = $3;
        $$ = $4;
        ir_loop_info_push();
    }
    ;
for_var_decl:
    var_decl {
        $$ = f_stack[f_top]->f->code_num;
    }
    ;
for_cond:
    expr {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, $1));
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
        $$ = f_stack[f_top]->f->code_num;
    }
    ;
for_inc:
    expr {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMP, $1));
        $$ = f_stack[f_top]->f->code_num;
    }
    ;
while_cond:
    '(' expr ')' {
        $$ = ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, $2));
    }
    ;
while_start:
    WHILE {
        $$ = f_stack[f_top]->f->code_num;
        ir_loop_info_push();
    }
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
    | '&' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ($2.type == EXPR_IMM){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, $$, $2)); }
    | '*' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, $$, $2)); $$.type = EXPR_PTR; }
    | expr '[' expr ']' { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, $$, ir_expr_imm($1.ival), $3)); $$ = ir_expr_ref($$.ival); }
    | func_call '(' para_list ')' {
        $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top]));
        ir i = ir_new1(IR_CALL, $$);
        i.op = f_stack[f_top]->f->code[$1].op;
        f_stack[f_top]->f->code[$1].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
    }
    | INT '(' fexpr ')' { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_F2I, $$, $3)); }
    | CHAR '(' fexpr ')' { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_F2I, $$, $3)); }
    ;
fexpr:
    REAL { $$ = ir_expr_fimm(real); }
    | FNAME { $$ = ir_expr_var(ir_func_ctx_get_local(f_stack[f_top], name)); }
    | '-' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_FNEG, $$, $2)); }
    | '+' fexpr { $$ = $2; }
    | '(' fexpr ')' { $$ = $2; }

    | fexpr '+' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, $$, $1, $3)); }
    | fexpr '+' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $3)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, $$, $1, $$)); }
    | expr '+' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $1)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, $$, $$, $3)); }
    
    | fexpr '-' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, $$, $1, $3)); }
    | fexpr '-' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $3)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, $$, $1, $$)); }
    | expr '-' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $1)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, $$, $$, $3)); }

    | fexpr '*' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, $$, $1, $3)); }
    | fexpr '*' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $3)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, $$, $1, $$)); }
    | expr '*' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $1)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, $$, $$, $3)); }

    | fexpr '/' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, $$, $1, $3)); }
    | fexpr '/' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $3)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, $$, $1, $$)); }
    | expr '/' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $1)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, $$, $$, $3)); }

    | fexpr '%' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMOD, $$, $1, $3)); }
    | fexpr '%' expr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $3)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMOD, $$, $1, $$)); }
    | expr '%' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $$, $1)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMOD, $$, $$, $3)); }

    | fexpr '<' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FLT, $$, $1, $3)); }
    | fexpr '>' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FGT, $$, $1, $3)); }
    | fexpr LE fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FLE, $$, $1, $3)); }

    | fexpr GE fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FGE, $$, $1, $3)); }
    | fexpr EQ fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FEQ, $$, $1, $3)); }
    | fexpr NE fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FNE, $$, $1, $3)); }

    | fexpr ADD_ASSIGN fexpr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, $1, $1, $3)); $$ = $1; }
    | fexpr ADD_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $1, $3)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, $1, $1, $1)); $$ = $1; }

    | fexpr SUB_ASSIGN fexpr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, $1, $1, $3)); $$ = $1; }
    | fexpr SUB_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $1, $3)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, $1, $1, $1)); $$ = $1; }

    | fexpr MUL_ASSIGN fexpr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, $1, $1, $3)); $$ = $1; }
    | fexpr MUL_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $1, $3)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, $1, $1, $1)); $$ = $1; }

    | fexpr DIV_ASSIGN fexpr { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, $1, $1, $3)); $$ = $1; }
    | fexpr DIV_ASSIGN expr { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, $1, $3)); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, $1, $1, $1)); $$ = $1; }

    | '&' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ($2.type == EXPR_IMM){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, $$, $2)); }
    | '*' fexpr { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, $$, $2)); $$.type = EXPR_PTR; }
    | fexpr '[' expr ']' { $$ = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, $$, ir_expr_imm($1.ival), $3)); $$ = ir_expr_ref($$.ival); }

    | ffunc_call '(' para_list ')' {
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
    | '+' constexpr { $$ = $2; }
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
ffunc_call:
    FNAME {
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
ftype_name:
    FLOAT
    | ftype_name '*'
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
    | ftype_name var_name ';' {
        ir_func_ctx_add_flocal(f_stack[f_top], $2, 1);
        free($2);
    }
    | ftype_name var_name '=' fexpr ';' {
        expr_info id = ir_expr_var(ir_func_ctx_add_flocal(f_stack[f_top], $2, 1));
        free($2);
        ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, id, $4));
    }
    | ftype_name var_name '[' constexpr ']' ';' {
        int length = (int)$4;
        ir_func_ctx_add_flocal(f_stack[f_top], $2, length);
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
    | ftype_name NAME {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_flocal(f_stack[f_top], name, 1);
    }
    | ftype_name NAME {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_flocal(f_stack[f_top], name, 1);
    } ',' para_decl
    | {}
    ;
para_list:
    expr { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, $1)); }
    | fexpr { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, $1)); }
    | para_list ',' expr { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, $3)); }
    | para_list ',' fexpr { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, $3)); }
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