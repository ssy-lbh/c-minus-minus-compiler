#ifndef _TYPES_H
#define _TYPES_H

typedef long long var_t;
typedef unsigned long long ptr_t;
typedef unsigned char enum_t;

#define EXPR_REF 0
#define EXPR_IMM 1
#define EXPR_VAR 2
#define EXPR_PTR 3

typedef struct _expr_info {
    var_t ival;
    unsigned char type;
} expr_info;

#endif