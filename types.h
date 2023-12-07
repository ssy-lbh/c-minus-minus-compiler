#ifndef _TYPES_H
#define _TYPES_H

typedef long long var_t;
typedef unsigned long long ptr_t;
typedef unsigned char enum_t;

typedef struct _expr_info {
    long long ival;
    unsigned char   is_ref : 1,
                    is_imm : 1;
} expr_info;

#endif