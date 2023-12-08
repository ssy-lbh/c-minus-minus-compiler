#include "ir.h"

expr_info ir_expr(){
    expr_info e;
    e.type = EXPR_VAR;
    return e;
}

char ir_expr_type(expr_info e){
    switch (e.type){
    case EXPR_IMM:
        return 'i';
    case EXPR_REF:
        return 'r';
    case EXPR_VAR:
        return 'v';
    case EXPR_PTR:
        return 'p';
    default:
        return '?';
    }
}

expr_info ir_expr_imm(var_t ival){
    expr_info e;
    e.type = EXPR_IMM;
    e.ival = ival;
    return e;
}

expr_info ir_expr_var(var_t id){
    expr_info e;
    e.type = EXPR_VAR;
    e.ival = id;
    return e;
}

expr_info ir_expr_ref(var_t id){
    expr_info e;
    e.type = EXPR_REF;
    e.ival = id;
    return e;
}

expr_info ir_expr_ptr(var_t id){
    expr_info e;
    e.type = EXPR_PTR;
    e.ival = id;
    return e;
}

ir_program *ir_program_new(){
    ir_program *p = (ir_program *)malloc(sizeof(ir_program));
    p->func_dict = dict_new(DEFAULT_DICT_SIZE);
    return p;
}

ir_func *ir_func_new(const char *name, int param_num){
    ir_func *f = (ir_func *)malloc(sizeof(ir_func));
    f->name = strdup(name);
    f->param_num = param_num;
    f->code_num = 0;
    f->native_func = NULL;
    f->next = NULL;
    return f;
}

ir_func *ir_func_new_native(const char *name, int param_num, void *native_func){
    ir_func *f = ir_func_new(name, param_num);
    f->native_func = native_func;
    return f;
}

ir_func_ctx *ir_func_ctx_new(ir_func *f){
    ir_func_ctx *ctx = (ir_func_ctx *)malloc(sizeof(ir_func_ctx));
    ctx->f = f;
    ctx->local_vars = dict_new(DEFAULT_DICT_SIZE);
    return ctx;
}

ir ir_new0(ir_code ins){
    ir i;
    i.ins = ins;
    i.op1 = ir_expr_imm(0);
    i.op2 = ir_expr_imm(0);
    i.op3 = ir_expr_imm(0);
    return i;
}

ir ir_new1(ir_code ins, expr_info op1){
    ir i;
    i.ins = ins;
    i.op1 = op1;
    i.op2 = ir_expr_imm(0);
    i.op3 = ir_expr_imm(0);
    return i;
}

ir ir_new2(ir_code ins, expr_info op1, expr_info op2){
    ir i;
    i.ins = ins;
    i.op1 = op1;
    i.op2 = op2;
    i.op3 = ir_expr_imm(0);
    return i;
}

ir ir_new3(ir_code ins, expr_info op1, expr_info op2, expr_info op3){
    ir i;
    i.ins = ins;
    i.op1 = op1;
    i.op2 = op2;
    i.op3 = op3;
    return i;
}

ir ir_imm1(ir_code ins, var_t ival){
    ir i;
    i.ins = ins;
    i.op1 = ir_expr_imm(0);
    i.op2 = ir_expr_imm(ival);
    i.op3 = ir_expr_imm(0);
    return i;
}

ir ir_var1(ir_code ins, expr_info op2){
    ir i;
    i.ins = ins;
    i.op1 = ir_expr_imm(0);
    i.op2 = op2;
    i.op3 = ir_expr_imm(0);
    return i;

}

ir ir_call(char *func_name, var_t retid){
    ir i;
    i.ins = IR_CALL;
    i.op = strdup(func_name);
    i.op1.ival = retid;
    i.op1.type = EXPR_VAR;
    i.op2 = ir_expr_imm(0);
    i.op3 = ir_expr_imm(0);
    return i;
}

ir ir_lea(expr_info op1, char *str){
    ir i;
    i.ins = IR_LEA;
    i.op = strdup(str);
    i.op1 = op1;
    i.op2 = ir_expr_imm(0);
    i.op3 = ir_expr_imm(0);
    return i;
}

void ir_program_add_func(ir_program *p, ir_func *f){
    dict_set(p->func_dict, f->name, f);
}

int ir_func_add_code(ir_func *f, ir i){
    f->code[f->code_num] = i;
    return f->code_num++;
}

int ir_func_ctx_inc_local(ir_func_ctx *ctx){
    return ctx->f->param_num++;
}

int ir_func_ctx_add_local(ir_func_ctx *ctx, char *name, int size){
    dict_set(ctx->local_vars, name, (void*)(long)ctx->f->param_num);
    int ret = ctx->f->param_num;
    ctx->f->param_num += size;
    return ret;
}

int ir_func_ctx_get_local(ir_func_ctx *ctx, char *name){
    void **value = dict_get(ctx->local_vars, name);
    if(value == NULL){
        return -1;
    }else{
        return (int)(long)*value;
    }
}

void ir_func_ctx_free(ir_func_ctx *ctx){
    dict_free(ctx->local_vars);
    free(ctx);
}

void ir_program_free(ir_program *p){
    dict_free(p->func_dict);
    free(p);
}

void ir_func_free(ir_func *f){
    free(f->name);
    free(f);
}

void ir_free(ir i){
    if(i.ins == IR_CALL || i.ins == IR_LEA){
        free(i.op);
    }
}

void ir_print(ir i){
    static const char* ir_code_str[] = {
        "IR_NOP",
        "IR_ADD",
        "IR_SUB",
        "IR_MUL",
        "IR_DIV",
        "IR_MOD",
        "IR_LT",
        "IR_GT",
        "IR_LE",
        "IR_GE",
        "IR_EQ",
        "IR_NE",
        "IR_SHL",
        "IR_SHR",
        "IR_NEG",
        "IR_MOV",
        "IR_JMP",
        "IR_JMPIF",
        "IR_JMPNOT",
        "IR_CALL",
        "IR_RET",
        "IR_PARAM",
        "IR_PASS",
        "IR_AND",
        "IR_OR",
        "IR_XOR",
        "IR_NOT",
        "IR_LOGIC_AND",
        "IR_LOGIC_OR",
        "IR_LOGIC_NOT",
        "IR_ADDR",
        "IR_DEREF",
        "IR_LEA",
    };
    if (i.ins == IR_CALL){
        printf("[%s] (%s %c%lld)\n", ir_code_str[i.ins], i.op, ir_expr_type(i.op1), i.op1.ival);
    } else if (i.ins == IR_LEA){
        printf("[%s] (%c%lld %s)\n", ir_code_str[i.ins], ir_expr_type(i.op1), i.op1.ival, i.op);
    } else {
        printf("[%s] (%c%lld %c%lld %c%lld)\n", ir_code_str[i.ins],
            ir_expr_type(i.op1), i.op1.ival,
            ir_expr_type(i.op2), i.op2.ival,
            ir_expr_type(i.op3), i.op3.ival);
    }
}