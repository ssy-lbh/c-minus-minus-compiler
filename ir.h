#ifndef _IR_H_
#define _IR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

#include "dict.h"
#include "vm.h"

typedef enum _ir_code {
    IR_NOP,
    IR_ADD,
    IR_SUB,
    IR_MUL,
    IR_DIV,
    IR_MOD,
    IR_LT,
    IR_GT,
    IR_LE,
    IR_GE,
    IR_EQ,
    IR_NE,
    IR_SHL,
    IR_SHR,
    IR_NEG,
    IR_MOV,
    IR_JMP,
    IR_JMPIF,
    IR_JMPNOT,
    IR_CALL,
    IR_RET,
    IR_PARAM,
    IR_PASS,
    IR_AND,
    IR_OR,
    IR_XOR,
    IR_NOT,
    IR_LOGIC_AND,
    IR_LOGIC_OR,
    IR_LOGIC_NOT,
    IR_ADDR,
    IR_DEREF,
    IR_LEA,
} ir_code;

// JMPX [addr] [cond]

typedef struct _ir {
    ir_code ins;
    expr_info op1;
    expr_info op2;
    expr_info op3;
    char *op;
} ir;

#define IR_FUNC_CODE_MAX 0x400

typedef struct _ir_func {
    char *name;
    int param_num;
    ir code[IR_FUNC_CODE_MAX];
    int code_num;
    void *native_func;
    struct _ir_func *next;
} ir_func;

typedef struct _ir_func_ctx {
    ir_func *f;
    dict *local_vars;
} ir_func_ctx;

typedef struct _ir_program {
    dict *func_dict;
} ir_program;

expr_info ir_expr();
char ir_expr_type(expr_info e);
expr_info ir_expr_imm(var_t ival);
expr_info ir_expr_var(var_t id);
expr_info ir_expr_ref(var_t id);
expr_info ir_expr_ptr(var_t id);

ir_program *ir_program_new();
ir_func *ir_func_new(const char *name, int param_num);
ir_func *ir_func_new_native(const char *name, int param_num, void *native_func);
ir_func_ctx *ir_func_ctx_new(ir_func *f);
ir ir_new0(ir_code ins);
ir ir_new1(ir_code ins, expr_info op1);
ir ir_new2(ir_code ins, expr_info op1, expr_info op2);
ir ir_new3(ir_code ins, expr_info op1, expr_info op2, expr_info op3);
ir ir_imm1(ir_code ins, var_t ival);
ir ir_var1(ir_code ins, expr_info op2);
ir ir_call(char *func_name, var_t retid);
ir ir_lea(expr_info op1, char *str);

void ir_program_add_func(ir_program *p, ir_func *f);
int ir_func_add_code(ir_func *f, ir i);
int ir_func_ctx_inc_local(ir_func_ctx *ctx);
int ir_func_ctx_add_local(ir_func_ctx *ctx, char *name, int size);
int ir_func_ctx_get_local(ir_func_ctx *ctx, char *name);

void ir_func_ctx_free(ir_func_ctx *ctx);
void ir_program_free(ir_program *p);
void ir_func_free(ir_func *f);
void ir_free(ir i);

void ir_print(ir i);

#endif