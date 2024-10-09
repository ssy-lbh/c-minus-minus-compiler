#include "vm.h"

#include <math.h>

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

static void vm_native_input(vm_ctx* ctx){
    scanf("%lld", &ctx->vars[0]);
}

static void vm_native_output(vm_ctx* ctx){
    ctx->vars[0] = printf("%lld\n", ctx->vars[0]);
}

static void vm_native_putchar(vm_ctx* ctx){
    ctx->vars[0] = putchar((int)ctx->vars[0]);
}

static void vm_native_print(vm_ctx* ctx){
    ctx->vars[0] = printf("%s", (char*)ctx->vars[0]);
}

static void vm_native_println(vm_ctx* ctx){
    ctx->vars[0] = puts((char*)ctx->vars[0]);
}

static void vm_native_getchar(vm_ctx* ctx){
    ctx->vars[0] = getchar();
}

static void vm_native_malloc(vm_ctx* ctx){
    ctx->vars[0] = (var_t)malloc(ctx->vars[0] * sizeof(var_t));
}

static void vm_native_free(vm_ctx* ctx){
    free((void*)ctx->vars[0]);
}

static void vm_native_exit(vm_ctx* ctx){
    exit(ctx->vars[0]);
}

static void vm_native_printf(vm_ctx* ctx){
    const char* format = (const char*)ctx->vars[0];
    int i = 1;
    ctx->vars[0] = 0;
    while (*format){
        if (*format == '%'){
            format++;
            if (*format == 'd'){
                ctx->vars[0] += printf("%lld", ctx->vars[i++]);
            } else if (*format == 'f'){
                ctx->vars[0] += printf("%f", REAL(ctx->vars[i++]));
            } else if (*format == 's'){
                ctx->vars[0] += printf("%s", (char*)ctx->vars[i++]);
            }
            format++;
        } else {
            putchar(*format);
            ctx->vars[0]++;
            format++;
        }
    }
}

static void vm_native_scanf(vm_ctx* ctx){
    const char* format = (const char*)ctx->vars[0];
    int i = 1;
    while (*format){
        if (*format == '%'){
            format++;
            if (*format == 'd'){
                scanf("%lld", (var_t*)ctx->vars[i++]);
            } else if (*format == 'f'){
                scanf("%lf", (real_t*)ctx->vars[i++]);
            } else if (*format == 's'){
                scanf("%s", (char*)ctx->vars[i++]);
            }
            format++;
        } else {
            format++;
        }
    }
    ctx->vars[0] = i - 1;
}

void vm_add_native(ir_program* prog){
    ir_program_add_func(prog, ir_func_new_native("input", 0, vm_native_input));
    ir_program_add_func(prog, ir_func_new_native("output", 1, vm_native_output));
    ir_program_add_func(prog, ir_func_new_native("putchar", 1, vm_native_putchar));
    ir_program_add_func(prog, ir_func_new_native("print", 1, vm_native_print));
    ir_program_add_func(prog, ir_func_new_native("println", 1, vm_native_println));
    ir_program_add_func(prog, ir_func_new_native("getchar", 0, vm_native_getchar));
    ir_program_add_func(prog, ir_func_new_native("malloc", 1, vm_native_malloc));
    ir_program_add_func(prog, ir_func_new_native("free", 1, vm_native_free));
    ir_program_add_func(prog, ir_func_new_native("exit", 1, vm_native_exit));
    ir_program_add_func(prog, ir_func_new_native("printf", 10, vm_native_printf));
    ir_program_add_func(prog, ir_func_new_native("scanf", 10, vm_native_scanf));
}

static var_t* vm_fetch_ptr(vm_ctx* ctx, expr_info e){
    switch (e.type){
    case EXPR_REF:
        return &ctx->vars[ctx->vars[e.ival]];
    case EXPR_VAR:
        return &ctx->vars[e.ival];
    case EXPR_PTR:
        return (var_t*)ctx->vars[e.ival];
    default:
        return NULL;
    }
}

static var_t vm_fetch_val(vm_ctx* ctx, expr_info e){
    switch (e.type){
    case EXPR_IMM:
        return e.ival;
    case EXPR_REF:
        return ctx->vars[ctx->vars[e.ival]];
    case EXPR_VAR:
        return ctx->vars[e.ival];
    case EXPR_PTR:
        return *(var_t*)ctx->vars[e.ival];
    default:
        puts("vm_fetch_val unknown type");
        return 0;
    }
}

var_t vm_run(vm_ctx* ctx, ir_program* prog, const char* entry){
    ir_func* f = *(ir_func**)dict_get(prog->func_dict, entry);
    vm_ctx* call_ctx = NULL;
    if (!f){
        printf("function %s not found\n", entry);
        return -1;
    }
    if (f->native_func){
        void(*func)(vm_ctx*) = f->native_func;
        func(ctx);
        return ctx->vars[0];
    }
    while (1){
        ir i = f->code[ctx->pc];
        //printf("PC: %d\n", ctx->pc);
        //ir_print(i);

        var_t* op1_ptr = vm_fetch_ptr(ctx, i.op1);
        var_t op2_val = vm_fetch_val(ctx, i.op2);
        var_t op3_val = vm_fetch_val(ctx, i.op3);
        //printf("OP1 %p | %lld\n", op1_ptr, (var_t)(op1_ptr - ctx->vars));
        //printf("OP2 %lld\n", op2_val);
        //printf("OP3 %lld\n", op3_val);

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
                if (i.op2.type == EXPR_REF){
                    *op1_ptr = (ptr_t)(ctx->vars + ctx->vars[i.op2.ival]);
                } else if (i.op2.type == EXPR_VAR) {
                    *op1_ptr = (ptr_t)(ctx->vars + i.op2.ival);
                } else if (i.op2.type == EXPR_PTR){
                    *op1_ptr = (ptr_t)i.op2.ival;
                } else {
                    printf("'&' could not be used on an immediate number\n");
                    return -1;
                }
                break;
            case IR_DEREF:
                *op1_ptr = *(var_t*)op2_val;
                break;
            case IR_LEA:
                *op1_ptr = (var_t)i.op;
                //printf("LEA %p\n", (char*)*op1_ptr);
                break;
            case IR_I2F:
                REAL(*op1_ptr) = (real_t)op2_val;
                break;
            case IR_F2I:
                *op1_ptr = (var_t)REAL(op2_val);
                break;
            case IR_FADD:
                REAL(*op1_ptr) = REAL(op2_val) + REAL(op3_val);
                break;
            case IR_FSUB:
                REAL(*op1_ptr) = REAL(op2_val) - REAL(op3_val);
                break;
            case IR_FMUL:
                REAL(*op1_ptr) = REAL(op2_val) * REAL(op3_val);
                break;
            case IR_FDIV:
                REAL(*op1_ptr) = REAL(op2_val) / REAL(op3_val);
                break;
            case IR_FNEG:
                REAL(*op1_ptr) = -REAL(op2_val);
                break;
            case IR_FLT:
                *op1_ptr = REAL(op2_val) < REAL(op3_val);
                break;
            case IR_FGT:
                *op1_ptr = REAL(op2_val) > REAL(op3_val);
                break;
            case IR_FLE:
                *op1_ptr = REAL(op2_val) <= REAL(op3_val);
                break;
            case IR_FGE:
                *op1_ptr = REAL(op2_val) >= REAL(op3_val);
                break;
            case IR_FEQ:
                *op1_ptr = REAL(op2_val) == REAL(op3_val);
                break;
            case IR_FNE:
                *op1_ptr = REAL(op2_val) != REAL(op3_val);
                break;
            case IR_FMOD:
                REAL(*op1_ptr) = fmod(REAL(op2_val), REAL(op3_val));
                break;
            default:
                printf("unknown instruction: %d at Function %s PC %d\n", i.ins, entry, ctx->pc);
                return -1;
        }
        ctx->pc++;
    }
}
