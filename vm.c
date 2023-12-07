#include "vm.h"

vm_ctx* vm_ctx_new(){
    vm_ctx* ctx = (vm_ctx*)malloc(sizeof(vm_ctx));
    ctx->pc = 0;
    ctx->lr = 0;
    memset(ctx->vars, 0, sizeof(int) * CONTEXT_SIZE);
    return ctx;
}

void vm_ctx_free(vm_ctx* ctx){
    free(ctx);
}

void _vm_native_input(vm_ctx* ctx){
    printf("input: ");
    scanf("%lld", &ctx->vars[0]);
}

void _vm_native_output(vm_ctx* ctx){
    printf("output: %lld\n", ctx->vars[0]);
}

void vm_add_native(ir_program* prog){
    ir_func* input = ir_func_new_native("input", 0, _vm_native_input);
    ir_func* output = ir_func_new_native("output", 1, _vm_native_output);
    ir_program_add_func(prog, input);
    ir_program_add_func(prog, output);
}

var_t vm_run(vm_ctx* ctx, ir_program* prog, const char* entry){
    ir_func* f = *(ir_func**)dict_get(prog->func_dict, entry);
    vm_ctx* call_ctx = NULL;
    if (f->native_func){
        void(*func)(vm_ctx*) = f->native_func;
        func(ctx);
        return ctx->vars[0];
    }
    while (1){
        //printf("PC: %d\n", ctx->pc);
        ir i = f->code[ctx->pc];

        var_t* op1_ptr;
        var_t op2_val;
        var_t op3_val;

        if (i.op1.is_ref){
            op1_ptr = &ctx->vars[ctx->vars[i.op1.ival]];
        } else {
            op1_ptr = &ctx->vars[i.op1.ival];
        }

        if (i.op2.is_imm){
            op2_val = i.op2.ival;
        } else if (i.op2.is_ref){
            op2_val = ctx->vars[ctx->vars[i.op2.ival]];
        } else {
            op2_val = ctx->vars[i.op2.ival];
        }

        if (i.op3.is_imm){
            op3_val = i.op3.ival;
        } else if (i.op3.is_ref){
            op3_val = ctx->vars[ctx->vars[i.op3.ival]];
        } else {
            op3_val = ctx->vars[i.op3.ival];
        }

        switch (i.ins){
            case IR_JMP:
                ctx->pc = op2_val;
                continue;
            case IR_JMPIF:
                if (op2_val){
                    ctx->pc = i.op1.ival;
                    continue;
                }
                break;
            case IR_JMPNOT:
                if (!op2_val){
                    ctx->pc = i.op1.ival;
                    continue;
                }
                break;
            case IR_CALL: {
                var_t ret = vm_run(call_ctx, prog, i.op);
                vm_ctx_free(call_ctx);
                call_ctx = NULL;
                *op1_ptr = ret;
            }
                break;
            case IR_RET:
                return op2_val;
            case IR_PARAM:
                call_ctx = vm_ctx_new();
                call_ctx->lr = 0;
                break;
            case IR_PASS:
                call_ctx->vars[call_ctx->lr++] = op2_val;
                break;
            case IR_ADD:
                *op1_ptr = op2_val + op3_val;
                break;
            case IR_SUB:
                *op1_ptr = op2_val - op3_val;
                break;
            case IR_MUL:
                *op1_ptr = op2_val * op3_val;
                break;
            case IR_DIV:
                *op1_ptr = op2_val / op3_val;
                break;
            case IR_MOD:
                *op1_ptr = op2_val % op3_val;
                break;
            case IR_EQ:
                *op1_ptr = op2_val == op3_val;
                break;
            case IR_NE:
                *op1_ptr = op2_val != op3_val;
                break;
            case IR_LT:
                *op1_ptr = op2_val < op3_val;
                break;
            case IR_GT:
                *op1_ptr = op2_val > op3_val;
                break;
            case IR_LE:
                *op1_ptr = op2_val <= op3_val;
                break;
            case IR_GE:
                *op1_ptr = op2_val >= op3_val;
                break;
            case IR_SHL:
                *op1_ptr = op2_val << op3_val;
                break;
            case IR_SHR:
                *op1_ptr = op2_val >> op3_val;
                break;
            case IR_NEG:
                *op1_ptr = -op2_val;
                break;
            case IR_MOV:
                *op1_ptr = op2_val;
                break;
            case IR_AND:
                *op1_ptr = op2_val & op3_val;
                break;
            case IR_OR:
                *op1_ptr = op2_val | op3_val;
                break;
            case IR_XOR:
                *op1_ptr = op2_val ^ op3_val;
                break;
            case IR_NOT:
                *op1_ptr = ~op2_val;
                break;
            case IR_LOGIC_AND:
                *op1_ptr = op2_val && op3_val;
                break;
            case IR_LOGIC_OR:
                *op1_ptr = op2_val || op3_val;
                break;
            case IR_LOGIC_NOT:
                *op1_ptr = !op2_val;
                break;
            case IR_ADDR:
                if (i.op2.is_ref){
                    *op1_ptr = (ptr_t)(ctx->vars + ctx->vars[i.op2.ival]);
                } else if (!i.op2.is_imm) {
                    *op1_ptr = (ptr_t)(ctx->vars + i.op2.ival);
                } else {
                    printf("'&' could not be used on an immediate number\n");
                    return -1;
                }
                break;
            case IR_DEREF:
                *op1_ptr = *(var_t*)op2_val;
                break;
            default:
                printf("unknown instruction: %d\n", i.ins);
                return -1;
        }
        ctx->pc++;
    }
}
