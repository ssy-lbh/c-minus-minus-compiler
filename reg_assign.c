#include "reg_assign.h"

void reg_assign(int reg_num, ir_func_ctx* ctx, char* out){
    // EXPR_REF 引用栈区域的第几个变量
    // EXPR_VAR 变量
    // EXPR_PTR 指针
    // EXPR_IMM 立即数

    // 线性扫描分配
    // 1. 遍历所有的IR指令，找到所有的变量
    // 2. 为每个变量分配一个寄存器和栈位置
    // 3. 为每个变量的每个引用点生成LOAD和STORE指令

    int var_num = ctx->f->param_num;
    int* reg_state = (int*)malloc(sizeof(int) * reg_num);

    char* ins_buffer = (char*)malloc(sizeof(char) * 1024);
    int ins_buffer_len = 0;
    int ins_buffer_cap = 1024;

    for(int i = 0; i < reg_num; i++){
        reg_state[i] = -1;
    }

    for(int i = 0; i < ctx->f->code_num; i++){
        const ir* instr = ctx->f->code + i;
        switch (instr->ins)
        {
        case IR_NOP:
            break;
        case IR_ADD:
        case IR_SUB: {
            struct {
                unsigned int
                    op: 4,
                    rd: 4,
                    rs1: 4,
                    rs2: 4;
            } *code = ins_buffer + ins_buffer_len;
            code->op = instr->op == IR_ADD ? 0 : 1;
            code->rd = reg_state[instr->op1.ival];
            code->rs1 = reg_state[instr->op2.ival];
            code->rs2 = instr->op3.type == EXPR_IMM ? 0 : reg_state[instr->op3.ival];
            }
        }
    }
}