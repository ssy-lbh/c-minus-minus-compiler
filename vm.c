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
    scanf("%d", &ctx->vars[0]);
}

void _vm_native_output(vm_ctx* ctx){
    printf("output: %d\n", ctx->vars[0]);
}

void vm_add_native(ir_program* prog){
    ir_func* input = ir_func_new_native("input", 0, _vm_native_input);
    ir_func* output = ir_func_new_native("output", 1, _vm_native_output);
    ir_program_add_func(prog, input);
    ir_program_add_func(prog, output);
}

int vm_run(vm_ctx* ctx, ir_program* prog, const char* entry){
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
        switch (i.ins){
            case IR_JMP:
                ctx->pc = i.op1;
                continue;
            case IR_JMPIF:
                if (ctx->vars[i.op1]){
                    ctx->pc = i.op2;
                    continue;
                }
                break;
            case IR_JMPNOT:
                if (!ctx->vars[i.op1]){
                    ctx->pc = i.op2;
                    continue;
                }
                break;
            case IR_CALL: {
                int ret = vm_run(call_ctx, prog, i.op);
                vm_ctx_free(call_ctx);
                call_ctx = NULL;
                ctx->vars[i.op3] = ret;
            }
                break;
            case IR_RET:
                return ctx->vars[i.op1];
            case IR_PARAM:
                call_ctx = vm_ctx_new();
                call_ctx->lr = 0;
                break;
            case IR_PASS:
                call_ctx->vars[call_ctx->lr++] = ctx->vars[i.op1];
                break;
            case IR_ADD:
                ctx->vars[i.op1] = ctx->vars[i.op2] + ctx->vars[i.op3];
                break;
            case IR_SUB:
                ctx->vars[i.op1] = ctx->vars[i.op2] - ctx->vars[i.op3];
                break;
            case IR_MUL:
                ctx->vars[i.op1] = ctx->vars[i.op2] * ctx->vars[i.op3];
                break;
            case IR_DIV:
                ctx->vars[i.op1] = ctx->vars[i.op2] / ctx->vars[i.op3];
                break;
            case IR_MOD:
                ctx->vars[i.op1] = ctx->vars[i.op2] % ctx->vars[i.op3];
                break;
            case IR_EQ:
                ctx->vars[i.op1] = ctx->vars[i.op2] == ctx->vars[i.op3];
                break;
            case IR_NE:
                ctx->vars[i.op1] = ctx->vars[i.op2] != ctx->vars[i.op3];
                break;
            case IR_LT:
                ctx->vars[i.op1] = ctx->vars[i.op2] < ctx->vars[i.op3];
                break;
            case IR_GT:
                ctx->vars[i.op1] = ctx->vars[i.op2] > ctx->vars[i.op3];
                break;
            case IR_LE:
                ctx->vars[i.op1] = ctx->vars[i.op2] <= ctx->vars[i.op3];
                break;
            case IR_GE:
                ctx->vars[i.op1] = ctx->vars[i.op2] >= ctx->vars[i.op3];
                break;
            case IR_SHL:
                ctx->vars[i.op1] = ctx->vars[i.op2] << ctx->vars[i.op3];
                break;
            case IR_SHR:
                ctx->vars[i.op1] = ctx->vars[i.op2] >> ctx->vars[i.op3];
                break;
            case IR_SAR:
                ctx->vars[i.op1] = ctx->vars[i.op2] >> ctx->vars[i.op3];
                break;
            case IR_NEG:
                ctx->vars[i.op1] = -ctx->vars[i.op2];
                break;
            case IR_MOV:
                ctx->vars[i.op1] = ctx->vars[i.op2];
                break;
            case IR_ASSIGN:
                ctx->vars[i.op1] = i.op2;
                break;
            default:
                printf("unknown instruction: %d\n", i.ins);
                return -1;
        }
        ctx->pc++;
    }
}
