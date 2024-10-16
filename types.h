#ifndef _TYPES_H
#define _TYPES_H

typedef long long var_t;
typedef double real_t;
typedef unsigned long long ptr_t;
typedef unsigned char enum_t;

#define EXPR_REF 0
#define EXPR_IMM 1
#define EXPR_VAR 2
#define EXPR_PTR 3

typedef struct _expr_info {
    union {
        var_t ival;
        real_t rval;
    };
    unsigned char type;
} expr_info;

#define LOOP_BREAK 0
#define LOOP_CONTINUE 1

typedef struct _loop_info {
    struct _loop_info *next;
    unsigned char type;
    int label;
} loop_info;

#define REAL(x) (*(real_t*)&(x))

#endif