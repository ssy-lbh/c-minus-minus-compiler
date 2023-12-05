#ifndef _VM_H_
#define _VM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"
#include "ir.h"

#define CONTEXT_SIZE 0x100

typedef struct _ir_program ir_program;

typedef struct _vm_ctx {
    int pc;
    int lr;
    int vars[CONTEXT_SIZE];
} vm_ctx;

vm_ctx* vm_ctx_new();
void vm_ctx_free(vm_ctx* ctx);
void vm_add_native(ir_program* prog);
int vm_run(vm_ctx* ctx, ir_program* prog, const char* entry);

#endif