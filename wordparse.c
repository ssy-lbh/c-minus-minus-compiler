#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>
#include <malloc.h>

typedef unsigned char bool_t;

#define assert(x)

#define SYM_NONE 0
#define SYM_DOT 1
#define SYM_ARROW 2
#define SYM_INCA 3 // after
#define SYM_DECA 4
#define SYM_INCB 5 // before
#define SYM_DECB 6
#define SYM_NEG 7
#define SYM_POINTER 8
#define SYM_ADDR 9
#define SYM_MUL 10
#define SYM_DIV 11
#define SYM_REM 12
#define SYM_ADD 13
#define SYM_SUB 14
#define SYM_AND 15
#define SYM_XOR 16
#define SYM_OR 17
#define SYM_INV 18
#define SYM_SL 19
#define SYM_SR 20
#define SYM_GT 21
#define SYM_LT 22
#define SYM_GE 23
#define SYM_LE 24
#define SYM_EQ 25
#define SYM_NE 26
#define SYM_LAND 27
#define SYM_LOR 28
#define SYM_NOT 29
#define SYM_SEL 30
#define SYM_SEP 31
#define SYM_SET 32
#define SYM_SET_MUL 33
#define SYM_SET_DIV 34
#define SYM_SET_REM 35
#define SYM_SET_ADD 36
#define SYM_SET_SUB 37
#define SYM_SET_AND 38
#define SYM_SET_XOR 39
#define SYM_SET_OR 40
#define SYM_SET_SL 41
#define SYM_SET_SR 42
#define SYM_COMMA 43
#define SYM_SEMI 44

#define SYM_DIFF_SET (SYM_SET_MUL - SYM_MUL)

const char* tbl_sym_name[] = {
    "nop",
    "dot",
    "arrow",
    "inca",
    "deca",
    "incb",
    "decb",
    "neg",
    "pointer",
    "addr",
    "mul",
    "div",
    "rem",
    "add",
    "sub",
    "and",
    "xor",
    "or",
    "not",
    "shl",
    "shr",
    "gt",
    "lt",
    "ge",
    "le",
    "eq",
    "ne",
    "land",
    "lor",
    "not",
    "sel",
    "sep",
    "set",
    "set_mul",
    "set_div",
    "set_rem",
    "set_add",
    "set_sub",
    "set_and",
    "set_xor",
    "set_or",
    "set_shl",
    "set_shr",
    "comma",
    "semi",
};

// 以后属性里面可以有类型要求的信息
typedef struct symattr {
    unsigned char
    ltr     : 1,  // right to left
    binary  : 1,
    before  : 1,
    after   : 1,
    end     : 1,
    // 0 push, 1 pop
    op      : 1,
    type    : 2;
} symattr;

symattr tbl_optype[] = {
    { .ltr = 0, .binary = 0, .before = 0, .after = 0, .end = 1 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 0, .binary = 0, .before = 1, .after = 1, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 0, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
    { .ltr = 1, .binary = 1, .before = 0, .after = 0, .end = 0 },
};

#define PRIO_NUM 30
#define PRIO_KEYWORD 17
#define PRIO_BRAC_BIG 16

// 前面有数字时的操作符
// 计划加入>>>
const char tbl_op1[] = {
    // (sign, 0, prio)
    '.', 0, SYM_DOT, 1,
    '-', '>', 0, SYM_ARROW, 1,
    '+', '+', 0, SYM_INCA, 2,
    '-', '-', 0, SYM_DECA, 2,
    '*', 0, SYM_MUL, 3,
    '/', 0, SYM_DIV, 3,
    '%', 0, SYM_REM, 3,
    '+', 0, SYM_ADD, 4,
    '-', 0, SYM_SUB, 4,
    '<', '<', 0, SYM_SL, 5,
    '>', '>', 0, SYM_SR, 5,
    '>', 0, SYM_GT, 6,
    '<', 0, SYM_LT, 6,
    '>', '=', 0, SYM_GE, 6,
    '<', '=', 0, SYM_LE, 6,
    '=', '=', 0, SYM_EQ, 7,
    '!', '=', 0, SYM_NE, 7,
    '&', 0, SYM_AND, 8,
    '^', 0, SYM_XOR, 9,
    '|', 0, SYM_OR, 10,
    '&', '&', 0, SYM_LAND, 11,
    '|', '|', 0, SYM_LOR, 12,
    // 13 rtl?
    '?', 0, SYM_SEL, 13,
    ':', 0, SYM_SEP, 13,
    // 14 rtl
    '=', 0, SYM_SET, 14,
    '+', '=', 0, SYM_SET_ADD, 14,
    '-', '=', 0, SYM_SET_SUB, 14,
    '*', '=', 0, SYM_SET_MUL, 14,
    '/', '=', 0, SYM_SET_DIV, 14,
    '%', '=', 0, SYM_SET_REM, 14,
    '&', '=', 0, SYM_SET_AND, 14,
    '|', '=', 0, SYM_SET_OR, 14,
    '^', '=', 0, SYM_SET_XOR, 14,
    '<', '<', '=', 0, SYM_SET_SL, 14,
    '>', '>', '=', 0, SYM_SET_SR, 14,
    ',', 0, SYM_COMMA, 15,
    // 尝试，优先级17留给关键字
    ';', 0, SYM_SEMI, 18,
    0
};

// 前面无数字时的操作符
const char tbl_op2[] = {
    // 2 rtl
    '-', 0, SYM_NEG, 2,
    '*', 0, SYM_POINTER, 2,
    '&', 0, SYM_ADDR, 2,
    '~', 0, SYM_INV, 2,
    '!', 0, SYM_NOT, 2,
    '+', '+', 0, SYM_INCB, 2,
    '-', '-', 0, SYM_DECB, 2,
    ';', 0, SYM_SEMI, 17,
    0
};

#define TYPE_INVALID 0
#define TYPE_SPACE 1
#define TYPE_NUMBER 2
#define TYPE_ALPHA 3
#define TYPE_SIGN 4
#define TYPE_PUSH 5
#define TYPE_POP 6

const char* SEQ_SPACE = " \t\r\n";
const char* SEQ_NUMBER = "0123456789";
const char* SEQ_ALPHA = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ$@_";
const char* SEQ_SIGN = "=<>!,.+-*/%^&|~?:;";
const char* SEQ_PUSH = "{([";
const char* SEQ_POP = "})]";
// 括号编号 0. {} 1. () 2. []

// 手动统计的
#define NUM_SIGN 18

#define BRAC_BIG 0
#define BRAC_SMALL 1
#define BRAC_MIDDLE 2

unsigned char tbl_brac_prio[] = { PRIO_BRAC_BIG, 0, 0 };

typedef struct trie_node {
    unsigned char sym;
    unsigned char prio;
    unsigned char child[NUM_SIGN];
} trie_node;

#define NUM_TRIE_NODES 100

trie_node trie_sign1[NUM_TRIE_NODES] = {};
trie_node trie_sign2[NUM_TRIE_NODES] = {};

typedef struct info {
    unsigned char
    type        : 3,
    ext         : 5;
} info;

info ctype[0x100] = {};

void init_info(){
    const char* s = SEQ_SPACE;
    while (*s) ctype[(unsigned char)*s++].type = TYPE_SPACE;
    s = SEQ_NUMBER;
    while (*s) ctype[(unsigned char)*s++].type = TYPE_NUMBER;
    s = SEQ_ALPHA;
    while (*s) ctype[(unsigned char)*s++].type = TYPE_ALPHA;
    s = SEQ_SIGN;
    unsigned char i = 0;
    while (s[i]){
        ctype[(unsigned char)s[i]].type = TYPE_SIGN;
        ctype[(unsigned char)s[i]].ext = i;
        i++;
    }
    s = SEQ_PUSH;
    i = 0;
    while (s[i]){
        ctype[(unsigned char)s[i]].type = TYPE_PUSH;
        ctype[(unsigned char)s[i]].ext = i;
        i++;
    }
    s = SEQ_POP;
    i = 0;
    while (s[i]){
        ctype[(unsigned char)s[i]].type = TYPE_POP;
        ctype[(unsigned char)s[i]].ext = i;
        i++;
    }
}

void build_trie(trie_node* root, const char* table){
    int i = 0, p = 0;
    while (*table){
        int cur = 0;
        do {
            unsigned char* idx = &root[cur].child[ctype[*table].ext];
            if (!*idx)
                *idx = ++p;
            cur = *idx;
        } while (*++table);
        root[cur].sym = *++table;
        root[cur].prio = *++table;
        ++table;
    }
}

#define ELEM_END 0
#define ELEM_VALUE 1
#define ELEM_NAME 2
#define ELEM_OP 3
#define ELEM_KEYWORD 4
#define ELEM_STACK 5

// 以后可以考虑加入行列号信息
typedef struct elem {
    unsigned char type;
    unsigned char sym;
    unsigned char prio;
    symattr attr;
    char* name;
    struct elem* l;
    struct elem* r;
} elem;

#define ELEM_LESS(x, y) (x->prio < y->prio || (y->attr.ltr && (x->prio == y->prio)))

typedef struct entry {
    unsigned int hash;
    char* key;
    void* val;
    struct entry* next;
} entry;

#define DICT_INIT_SIZE 3

typedef struct dict {
    unsigned int mask;
    unsigned int size;
    entry** list;
} dict;

unsigned int elf_hash(char* k){
    unsigned int h = 0;
    unsigned int g;
    while (*k){
        h = (h << 4) + *k++;
        if (!(g = h & 0xF0000000))
            continue;
        h ^= g >> 24;
        h &= ~g;
    }
    return h;
}

void dict_new(dict* d){
    d->list = (entry**)calloc(1, sizeof(entry*) << DICT_INIT_SIZE);
    d->mask = (1 << DICT_INIT_SIZE) - 1;
    d->size = 0;
}

void dict_expand(dict* d){
    entry** nlist;
    int bit = 33 - __builtin_clz(d->mask);
    nlist = (entry**)calloc(1, sizeof(entry*) << bit);
    unsigned int off = (1 << (bit - 1));
    for (unsigned int i = 0; i <= d->mask; i++){
        entry* e = d->list[i];
        while (e){
            int idx = (e->hash & off) | i;
            e->next = nlist[idx];
            nlist[idx] = e;
            e = e->next;
        }
    }
    free(d->list);
    d->list = nlist;
    d->mask = (1 << bit) - 1;
}

void dict_put(dict* d, char* key, void* val){
    if (d->size >= d->mask)
        dict_expand(d);
    entry* e = (entry*)malloc(sizeof(entry));
    e->hash = elf_hash(key);
    unsigned int idx = e->hash & d->mask;
    e->key = key;
    e->val = val;
    e->next = d->list[idx];
    d->list[idx] = e;
}

void* dict_get(dict* d, char* key){
    unsigned int hash = elf_hash(key);
    entry* e = d->list[hash & d->mask];
    while (e){
        // 只判断hash == e->hash属于梭哈行为
        if (strcmp(key, e->key) == 0)
            return e->val;
        e = e->next;
    }
    return NULL;
}

// 可能与dict_get合并
void** dict_getref(dict* d, char* key){
    unsigned int hash = elf_hash(key);
    entry* e = d->list[hash & d->mask];
    while (e){
        // 只判断hash == e->hash属于梭哈行为
        if (strcmp(key, e->key) == 0)
            return &e->val;
        e = e->next;
    }
    return NULL;
}

void dict_free(dict* d){
    free(d->list);
}

void dict_freek(dict* d){
    for (unsigned int i = 0; i <= d->mask; i++){
        entry* e = d->list[i];
        while (e){
            free(e->key);
            e = e->next;
        }
    }
    free(d->list);
}

// 特殊: 类型关键字能直接当tid用
#define KEYWORD_CHAR 0
#define KEYWORD_SHORT 1
#define KEYWORD_INT 2
#define KEYWORD_LONG 3
#define KEYWORD_FLOAT 4
#define KEYWORD_DOUBLE 5
#define KEYWORD_VOID 6
#define KEYWORD_IF 7
#define KEYWORD_ELSE 8
#define KEYWORD_WHILE 9
#define KEYWORD_FOR 10
#define KEYWORD_RETURN 11

#define KEYWORD_IS_TYPE(x) ((x) <= KEYWORD_VOID)
#define KEYWORD_IS_NONVOID_TYPE(x) ((x) <= KEYWORD_DOUBLE)

const char* tbl_types = "csilfdv";

dict keywords;

typedef struct keyword {
    char* name;
    int kid;
} keyword;

keyword tbl_keywords[] = {
    { "char", KEYWORD_CHAR },
    { "short", KEYWORD_SHORT },
    { "int", KEYWORD_INT },
    { "long", KEYWORD_LONG },
    { "float", KEYWORD_FLOAT },
    { "double", KEYWORD_DOUBLE },
    { "void", KEYWORD_VOID },
    { "if", KEYWORD_IF },
    { "else", KEYWORD_ELSE },
    { "while", KEYWORD_WHILE },
    { "for", KEYWORD_FOR },
    { "return", KEYWORD_RETURN },
    { NULL, 0 }
};

void init_keywords(){
    int i = 0;
    dict_new(&keywords);
    while (tbl_keywords[i].name){
        dict_put(&keywords, tbl_keywords[i].name, (void*)(intptr_t)tbl_keywords[i].kid);
        i++;
    }
}

#define ERR_NO 0
#define ERR_INVAL 1
#define ERR_SIGN 2
#define ERR_NUMBER 3

// 分块，归约
int resolve_exp(elem* expr, const char* s){
    static char buf[0x100];
    int i = 0, p = 0;
    unsigned char cur = 0;
    info inf;
    trie_node* trie;
    unsigned char tmp;
    // 4 states
    // 0 space
    // 1 number
    // 2 name
    // 3 op
    unsigned char state = 0;
    s--;
    while (1){
        switch (state){
        case 0:
            inf = ctype[(unsigned char)*++s];
            break;
        case 1:
            buf[i++] = *s;
            inf = ctype[(unsigned char)*++s];
            if (inf.type == TYPE_NUMBER || inf.type == TYPE_ALPHA)
                continue;
            if (*s == '.'){
                if (expr[p].attr.type)
                    return ERR_NUMBER;
                expr[p].attr.type |= 1;
                continue;
            }
            buf[i] = '\0';
            expr[p].prio = 0;
            expr[p++].name = strdup(buf);
            i = 0;
            break;
        case 2:
            buf[i++] = *s;
            inf = ctype[(unsigned char)*++s];
            if (inf.type == TYPE_NUMBER || inf.type == TYPE_ALPHA)
                continue;
            buf[i] = '\0';
            if ((tmp = (intptr_t)dict_get(&keywords, buf))){
                expr[p].type = ELEM_KEYWORD;
                expr[p].prio = PRIO_KEYWORD;
                expr[p++].sym = tmp;
                i = 0;
                break;
            }
            expr[p].prio = 0;
            expr[p++].name = strdup(buf);
            i = 0;
            break;
        case 3:
            // trie lookup
            unsigned char to = trie[cur].child[ctype[(unsigned char)*s].ext];
            if (to == 0){
                if (trie[cur].sym == 0)
                    return ERR_SIGN;
                expr[p].sym = trie[cur].sym;
                expr[p].prio = trie[cur].prio;
                expr[p++].attr = tbl_optype[trie[cur].prio];
                expr[p].type = ELEM_OP;
                trie = trie_sign2;
                to = trie[0].child[ctype[(unsigned char)*s].ext];
                if (to == 0)
                    return ERR_SIGN;
            }
            cur = to;
            inf = ctype[(unsigned char)*++s];
            if (inf.type == TYPE_SIGN)
                continue;
            if (trie[cur].sym == 0)
                return ERR_SIGN;
            expr[p].sym = trie[cur].sym;
            expr[p].prio = trie[cur].prio;
            expr[p++].attr = tbl_optype[trie[cur].prio];
            cur = 0;
            break;
        }
        switch (inf.type){
        case TYPE_SPACE:
            state = 0;
            continue;
        case TYPE_NUMBER:
            expr[p].type = ELEM_VALUE;
            expr[p].attr.type = 0;
            state = 1;
            continue;
        case TYPE_ALPHA:
            expr[p].type = ELEM_NAME;
            state = 2;
            continue;
        case TYPE_SIGN:
            trie = (p && (expr[p-1].type == ELEM_VALUE ||
                        expr[p-1].type == ELEM_NAME ||
                        (expr[p-1].type == ELEM_STACK && expr[p-1].attr.op && expr[p-1].type != BRAC_BIG)))
                    ? trie_sign1 : trie_sign2;
            expr[p].type = ELEM_OP;
            state = 3;
            continue;
        case TYPE_PUSH:
            expr[p].type = ELEM_STACK;
            // expr[p].prio = 0;
            expr[p].attr.op = 0;
            expr[p++].attr.type = inf.ext;
            state = 0;
            continue;
        case TYPE_POP:
            expr[p].type = ELEM_STACK;
            expr[p].prio = tbl_brac_prio[inf.ext];
            expr[p].attr.op = 1;
            expr[p++].attr.type = inf.ext;
            state = 0;
            if (inf.ext == BRAC_BIG){
                expr[p].type = ELEM_OP;
                expr[p].sym = SYM_SEMI;
                expr[p].prio = 18;
                expr[p++].attr = tbl_optype[18];
            }
            continue;
        default: break;
        }
        break;
    }
    if (*s != '\0')
        return ERR_INVAL;
    expr[p].type = ELEM_END;
    return ERR_NO;
}

inline int elem_less(elem* x, elem* y){
    // 优先级相同时方向必相同
    return x->prio < y->prio || (y->attr.ltr && (x->prio == y->prio));
}

elem bottom = { .prio = 0xFF };

// 单调栈构建表达式树
elem* build_tree(elem* e, elem** t){
    elem* h[PRIO_NUM];
    int p = 0;
    elem* c;
    *h = &bottom;
    h[1] = NULL;
    for (; e->type != ELEM_END; e++){
        if (e->type == ELEM_STACK){
            if (e->attr.op){
                *t = e;
                // 补丁
                return (e->l = h[1]);
            }
            unsigned char type = e->attr.type;
            // 注:右括号的左侧为内部表达式，并附在前一个元素的右侧
            // e->l = 有优先级问题，->先于=执行，引用错误
            build_tree(e + 1, &e);
            e->r = NULL;
            if (e->attr.type != type){
                fprintf(stderr, "bracket '%c' error", SEQ_POP[e->attr.type]);
                exit(-1);
            }
            h[p]->r = e;
            h[++p] = e;
            continue;
        }
        c = NULL;
        while (ELEM_LESS(h[p], e))
            c = h[p--];
        h[p]->r = e;
        e->l = c;
        e->r = NULL;
        h[++p] = e;
    }
    return h[1];
}

void dump(elem* e){
    if (e->type == ELEM_STACK){
        printf("(%d ", e->attr.type);
        dump(e->l);
        printf(")%d ", e->attr.type);
        return;
    }
    if (e->l) dump(e->l);
    if (e->r) dump(e->r);
    if (e->type == ELEM_NAME || e->type == ELEM_VALUE)
        printf("%s ", e->name);
    else if (e->type == ELEM_OP)
        printf("X%d ", e->sym);
    else if (e->type == ELEM_KEYWORD)
        printf("K%d", e->sym);
}

void dump_word(elem* e){
    switch (e->type){
    case ELEM_KEYWORD:
        printf("KEYWORD %s,", tbl_keywords[e->sym].name);
        break;
    case ELEM_NAME:
        printf("NAME %s,", e->name);
        break;
    case ELEM_OP:
        printf("OPERATOR %s,", tbl_sym_name[e->sym]);
        break;
    case ELEM_STACK:
        printf("BRACKET %c,", e->attr.op ? SEQ_POP[e->attr.type] : SEQ_PUSH[e->attr.type]);
        break;
    case ELEM_VALUE:
        printf("VALUE %s,", e->name);
        break;
    }
}

void dump2(elem* e, int depth){
    if (e->type == ELEM_STACK){
        printf("%*sBRACKET %c", 0, "", SEQ_PUSH[e->attr.type]);
    } else if (e->type == ELEM_NAME || e->type == ELEM_VALUE){
        printf("%*s%s %s", 0, "", e->type == ELEM_NAME ? "NAME" : "VALUE", e->name);
    } else if (e->type == ELEM_OP){
        printf("%*sOPERATOR %s", 0, "", tbl_sym_name[e->sym]);
    } else if (e->type == ELEM_KEYWORD){
        printf("%*sKEYWORD %s", 0, "", tbl_keywords[e->sym].name);
    }
    if (!e->l && !e->r){
        return;
    }
    printf("%*s{", 0, "");
    if (e->l) dump2(e->l, depth + 1);
    //printf("%*s--\n", depth * 2, "");
    putchar('|');
    if (e->r) dump2(e->r, depth + 1);
    printf("%*s}", 0, "");
}

// 类型特性 void => 0
#define PRIM_CHAR 0
#define PRIM_SHORT 1
#define PRIM_INT 2
#define PRIM_LONG 3
#define PRIM_FLOAT 4
#define PRIM_DOUBLE 5
#define PRIM_VOID 6

// 不是原始类型的以后加上，比如struct中嵌套类型等
// 只支持基本类型、结构与其指针
typedef struct type {
    unsigned short
    constexp    : 1,
    lvalue      : 1,
    pointer     : 1,
    prim        : 1,
    tid         : 12;
} type;

unsigned char tbl_prim_size[] = { 1, 2, 4, 4, 4, 8, 1 };

type type_void = { .constexp = 0, .lvalue = 0, .pointer = 0, .prim = 1, .tid = PRIM_VOID };

#define TYPE_EQUAL(x, y) (*(short*)&x == *(short*)&y)
#define TYPE_NOT_EQUAL(x, y) (*(short*)&x != *(short*)&y)
#define TYPE_VOID(t) TYPE_EQUAL(t, type_void)
#define TYPE_NONVOID(t) TYPE_NOT_EQUAL(t, type_void)

#define TYPE_IS_INT(t) (t.prim && t.tid < PRIM_FLOAT)
#define PRIM_IS_INT(x) ((x) < PRIM_FLOAT)

// 结构体id从PRIM_STRUCT_START开始分配
typedef struct struc {

} struc;

unsigned char type_getsize(type t){
    if (t.prim)
        return tbl_prim_size[t.tid];
    fputs("unimplemented type_getsize(struct type)", stderr);
    exit(-1);
}

// IEEE-754中精确的标准浮点数
typedef struct bits_float {
    union {
        float f;
        unsigned int ui;
        unsigned int
        frac        : 23,
        exp         : 8,
        sign        : 1;
    };
} bits_float;

typedef struct bits_double {
    union {
        double d;
        unsigned long long ull;
        unsigned long long
        frac        : 52,
        exp         : 11,
        sign        : 1;
    };
} bits_double;

typedef unsigned short vid_t;

typedef struct var {
    type t;
    vid_t id;
} var;

// 规定要么t.constexp == 1要么id有效
// constexpr情况下一律按unsigned long/long/double计算
typedef struct value {
    union {
        // 用于var相关函数
        var v;
        struct {
            type t;
            vid_t id;
        };
    };
    union {
        long l;
        unsigned long ul;
        double d;
        var* vp;
    };
} value;

void resolve_int_radix2(const char* s, value* v){
    v->ul = 0;
    while (*s){
        unsigned char x = *s++ - '0';
        if (x >= 2){
            fprintf(stderr, "invalid redix2 number '%c'\n", x);
            exit(-1);
        }
        v->ul = (v->ul << 1) | x;
    }
}

void resolve_int_radix8(const char* s, value* v){
    v->ul = 0;
    while (*s){
        unsigned char x = *s++ - '0';
        if (x >= 8){
            fprintf(stderr, "invalid redix8 number '%c'\n", x);
            exit(-1);
        }
        v->ul = (v->ul << 3) | x;
    }
}

void resolve_int_radix10(const char* s, value* v){
    v->ul = 0;
    while (*s){
        unsigned char x = *s++ - '0';
        if (x >= 10){
            fprintf(stderr, "invalid redix10 number '%c'\n", x);
            exit(-1);
        }
        // 编译器lea优化，指令为add r,r; lea r,[r+r*4];
        // 不必(x << 3) + (x << 1)
        v->ul = v->ul * 10 + x;
    }
}

void resolve_int_radix16(const char* s, value* v){
    v->ul = 0;
    while (*s){
        unsigned char x = *s - '0';
        if (x >= 10){
            x = *s -'a';
            if (x >= 6){
                x = *s - 'A';
                if (x >= 6){
                    fprintf(stderr, "invalid redix16 number '%c'\n", x);
                    exit(-1);
                }
            }
            x += 10;
        }
        v->ul = (v->ul << 4) | x;
        s++;
    }
}

double shift_float_left(double x, int ns){
    bits_double bits;
    bits.d = x;
    bits.exp += ns;
    return bits.d;
}

// 不支持首位为'.'且'-'总为操作符
// s为[0-9][0-9a-zA-Z$_@\.]*
// 等待实现
void resolve_value(elem* e, value* v){
    // 应当做好字面量的类型转换，避免运行时转换
    // 为降低复杂性，取消后缀
    // 格式种类
    // 0[Bb][01]*
    // 0[Xx][0-9a-fA-F]*
    // 0[0-7]*
    // [0-9]*\.[0-9]*(e-?[0-9]*)?
    assert(e->type == ELEM_VALUE);
    const char* s = e->name;
    // 注: 位域赋值尽量放一起，不要分开赋值
    v->t.constexp = 1;
    v->t.lvalue = 0;
    v->t.pointer = 0;
    v->t.prim = 1;
    if (e->attr.type){
        char* end;
        v->t.tid = PRIM_DOUBLE;
        v->d = strtod(s, &end);
        if (*end){
            fprintf(stderr, "invalid double number '%s'\n", s);
            exit(-1);
        }
        return;
    }
    v->t.tid = PRIM_LONG;
    if (s[0] == '0'){
        if (s[1] == 'x' || s[1] == 'X'){
            resolve_int_radix16(s + 2, v);
            return;
        }
        if (s[1] == 'b' || s[1] == 'B'){
            resolve_int_radix2(s + 2, v);
            return;
        }
        resolve_int_radix8(s + 1, v);
        return;
    }
    resolve_int_radix10(s, v);
}

// id为0时无效
// 一个域内可以有变量、函数、结构体定义
typedef struct field {
    dict d;
    vid_t insid;
} field;

// 第0个应该一开始初始化，作为全局变量表
// 内部存储的是命名对象信息，id为-1(0xFFFFFFFF)代表未初始化，0代表不存在
field fields[10];
int layer;

void fields_init(){
    dict_new(&fields[0].d);
    fields[0].insid = 0;
    layer = 0;
}

// prev为NULL时代表为最顶层field(global)
void field_new(field* f, field* prev){
    dict_new(&f->d);
    f->insid = prev->insid;
}

void field_push(){
    field_new(fields + layer + 1, fields + layer);
    layer++;
}

void field_pop(){
    dict_free(&fields[layer].d);
    layer--;
}

vid_t var_newid(){
    return ++fields[layer].insid;
}

// 每个元素的名称都是单独申请
// 保证不重复申请内存，元素被释放的时间应较晚
vid_t var_new_named(char* name, type t){
    var v;
    v.t = t;
    v.id = ++fields[layer].insid;
    dict_put(&fields[layer].d, name, (void*)(*(intptr_t*)&v));
    return v.id;
}

void var_getref(var** v, char* name){
    for (int i = layer; i >= 0; i--){
        void** va = dict_getref(&fields[i].d, name);
        if (va){
            *v = (var*)va;
            return;
        }
    }
    fprintf(stderr, "undefined variable '%s'\n", name);
    exit(-1);
}

// 以后提供更详细的信息
// id_t改为value，提供内存、寄存器、立即数的类别
// 最后交给相应平台指令选择器，选出并给出SSA指令
// 然后寄存器分配算法
void emit_ins(vid_t oid, vid_t aid, vid_t bid, unsigned char sym){
    printf("%s %hu,%hu,%hu\n", tbl_sym_name[sym], oid, aid, bid);
}

void emit_movl(vid_t oid, long imm){
    printf("movl %hu,$%ld\n", oid, imm);
}

void emit_movd(vid_t oid, double imm){
    printf("movd %hu,$%lf\n", oid, imm);
}

void emit_assign(vid_t oid, vid_t iid){
    printf("store %hu,%hu\n", oid, iid);
}

void emit_fetch(vid_t oid, vid_t iid){
    printf("load %hu,%hu\n", oid, iid);
}

long value_calc_ll(long a, long b, unsigned char sym){
    switch (sym){
    case SYM_ADD:
        return a + b;
    case SYM_SUB:
        return a - b;
    case SYM_MUL:
        return a * b;
    case SYM_DIV:
        return a / b;
    case SYM_REM:
        return a % b;
    case SYM_AND:
        return a & b;
    case SYM_OR:
        return a | b;
    case SYM_XOR:
        return a ^ b;
    case SYM_NOT:
        return ~a;
    case SYM_SL:
        return a << b;
    case SYM_SR:
        return a >> b;
    }
    fputs("unsupported operator between long and long", stderr);
    exit(-1);
}

double value_calc_dd(double a, double b, unsigned char sym){
    switch (sym){
    case SYM_ADD:
        return a + b;
    case SYM_SUB:
        return a - b;
    case SYM_MUL:
        return a * b;
    case SYM_DIV:
        return a / b;
    }
    fputs("unsupported operator between double and double", stderr);
    exit(-1);
}

void value_cast_constexp(vid_t oid, value* i, type t){
    if (PRIM_IS_INT(t.tid)){
        emit_movl(oid, PRIM_IS_INT(i->t.tid) ? i->l : i->d);
    } else {
        emit_movd(oid, PRIM_IS_INT(i->t.tid) ? i->l : i->d);
    }
}

// no constexpr type
void value_try_cast(value* o, value* i, type t){
    assert(!i->t.constexp);
    assert(i->t.prim && t.prim);
    if (i->t.tid == t.tid){
        o->v = i->v;
        return;
    }
    o->id = var_newid();
    o->t = t;
    printf("%c2%c %hu,%hu\n", tbl_types[i->t.tid], tbl_types[t.tid], o->id, i->id);
}

void value_basic_cast(value* o, value* i, vid_t tid){
    if (i->t.constexp){
        type t = { .constexp = 1, .lvalue = 0, .pointer = 0, .prim = 1, .tid = tid };
        o->id = var_newid();
        o->t = t;
        value_cast_constexp(o->id, i, t);
        return;
    }
    type t = { .constexp = 0, .lvalue = 0, .pointer = 0, .prim = 1, .tid = tid };
    value_try_cast(o, i, t);
}

// pt 要求 prim, pid, 即基本类型, lvalue = 0, pointer = 1
void value_cast_intptr(value* o, value* i, type pt){
    assert(i->t.prim && PRIM_IS_INT(i->t.tid));
    if (i->t.constexp){
        o->t = pt;
        o->t.constexp = 1;
        o->l = i->l;
        return;
    }
    // tid视32位或64位而定
    type intptr_type = { .constexp = 0, .lvalue = 0, .pointer = 0, .prim = 1, .tid = PRIM_INT };
    value_try_cast(o, i, intptr_type);
}

inline bool_t elem_is_func_decl(elem* e){
    return e->type == ELEM_NAME
        && e->r && e->r->type == ELEM_STACK
        && e->r->attr.type == BRAC_SMALL
        && e->r->r && e->r->r->type == ELEM_STACK
        && e->r->r->attr.type == BRAC_BIG;
}

inline vid_t var_def_single(type t, elem* e){
    if (e->type != ELEM_NAME){
        fputs("define variable error", stderr);
        exit(-1);
    }
    if(e->l || e->r){
        if (elem_is_func_decl(e)){
            // 函数定义
            printf("define function %s\n", e->name);
            return 0;
        }
        fputs("define variable error", stderr);
        exit(-1);
    }
    if (t.prim && t.tid == PRIM_VOID){
        fputs("define void variable", stderr);
        exit(-1);
    }
    vid_t id = var_new_named(e->name, t);
    if (t.tid < sizeof(tbl_types) - 1){
        printf("alloca %hu,%c,%s\n", id, tbl_types[t.tid], e->name);
        return id;
    }
    printf("alloca %hu,%hu,%s\n", id, t.tid, e->name);
    return id;
}

void var_def(vid_t tid, elem* e){
    type t = { .constexp = 0, .lvalue = 1, .pointer = 0, .prim = 1, .tid = tid };
    while (e){
        if (e->type == ELEM_OP && e->sym == SYM_COMMA){
            if (!e->l){
                fputs("define variable error", stderr);
                exit(-1);
            }
            var_def_single(t, e->l);
            e = e->r;
            continue;
        }
        var_def_single(t, e);
        return;
    }
}

// 单目运算符有效数字放第一个
void value_calc(value* o, value* x, value* y, unsigned char sym){
    // 指针加偏移
    if (x->t.pointer && y->t.prim && PRIM_IS_INT(y->t.tid)){
        fputs("pointer arithmetic", stderr);
        return;
    }
    // 常表达式
    if (x->t.constexp && y->t.constexp){
        assert(x->t.prim && y->t.prim);
        o->t = x->t;
        if (PRIM_IS_INT(x->t.tid)){
            if (PRIM_IS_INT(y->t.tid)){
                o->l = value_calc_ll(x->l, y->l, sym);
                o->t.constexp = 1;
                o->t.lvalue = 0;
                o->t.pointer = 0;
                o->t.prim = 1;
                o->t.tid = PRIM_INT;
                return;
            }
            o->d = value_calc_dd(x->l, y->d, sym);
            o->t.constexp = 1;
            o->t.lvalue = 0;
            o->t.pointer = 0;
            o->t.prim = 1;
            o->t.tid = PRIM_DOUBLE;
            return;
        } else {
            o->d = value_calc_dd(x->d, PRIM_IS_INT(y->t.tid) ? y->l : y->d, sym);
            o->t.constexp = 1;
            o->t.lvalue = 0;
            o->t.pointer = 0;
            o->t.prim = 1;
            o->t.tid = PRIM_DOUBLE;
            return;
        }
    }
    // 常量到寄存器
    value tmp;
    if (x->t.constexp){
        tmp.t = y->t;
        tmp.id = var_newid();
        value_cast_constexp(tmp.id, x, y->t);
        o->t = y->t;
        x = &tmp;
    } else if (y->t.constexp) {
        tmp.t = x->t;
        tmp.id = var_newid();
        value_cast_constexp(tmp.id, y, x->t);
        o->t = x->t;
        y = &tmp;
    } else if (x->t.tid != y->t.tid){
        // 不支持隐式转换，强类型
        fputs("unsupported operation between different types", stderr);
        exit(-1);
    } else {
        o->t = x->t;
    }
    o->id = var_newid();
    emit_ins(o->id, x->id, y->id, sym);
}

void dump_ins(elem* e, value* v){
    if (!e){
        v->t = type_void;
        return;
    }
    value v1;
    value v2;
    // 改成函数指针表或跳转表
    switch (e->type){
    case ELEM_VALUE:
        resolve_value(e, v);
        return;
    case ELEM_NAME:
        // 右侧小括号 => 调用
        // 右侧中括号 => 下标
        // 右侧大括号/其他 => 报错
        assert(!e->l);
        if (e->r){
            elem* er = e->r;
            if (er->type == ELEM_STACK){
                switch (er->attr.type){
                case BRAC_SMALL:
                    // call
                    return;
                case BRAC_MIDDLE:
                    // index
                    return;
                }
            }
            fputs("expected ';' between two expressions", stderr);
            exit(-1);
        }
        var_getref(&v->vp, e->name);
        v->v = *v->vp;
        return;
    case ELEM_OP:
        switch (e->sym){
        case SYM_COMMA:
            dump_ins(e->l, &v1);
            dump_ins(e->r, v);
            return;
        case SYM_SEMI:
            dump_ins(e->l, &v1);
            dump_ins(e->r, &v2);
            v->t = type_void;
            return;
        case SYM_ADD:
        case SYM_SUB:
        case SYM_MUL:
        case SYM_DIV:
        case SYM_REM:
        case SYM_AND:
        case SYM_OR:
        case SYM_XOR:
        case SYM_SL:
        case SYM_SR:
            dump_ins(e->l, &v1);
            dump_ins(e->r, &v2);
            if (TYPE_VOID(v1.t) || TYPE_VOID(v2.t)){
                fputs("binary operator has non-enough operands", stderr);
                exit(-1);
            }
            value_calc(v, &v1, &v2, e->sym);
            return;
        case SYM_NOT:
            dump_ins(e->r, &v1);
            if (e->l || TYPE_VOID(v1.t)){
                fputs("unary operator has non-correct operands", stderr);
                exit(-1);
            }
            value_calc(v, &v1, &v2, e->sym);
            return;
        case SYM_SET_ADD:
        case SYM_SET_SUB:
        case SYM_SET_MUL:
        case SYM_SET_DIV:
        case SYM_SET_REM:
        case SYM_SET_AND:
        case SYM_SET_OR:
        case SYM_SET_XOR:
        case SYM_SET_SL:
        case SYM_SET_SR:
            dump_ins(e->l, &v1);
            dump_ins(e->r, &v2);
            if (TYPE_VOID(v1.t) || TYPE_VOID(v2.t)){
                fputs("binary operator has non-enough operands", stderr);
                exit(-1);
            }
            if (!v1.t.lvalue){
                fputs("lvalue required as left operand of assignment", stderr);
                exit(-1);
            }
            value_calc(v, &v1, &v2, e->sym - SYM_DIFF_SET);
            v1.vp->id = v->id;
            return;
        case SYM_SET:
            dump_ins(e->l, &v1);
            dump_ins(e->r, &v2);
            if (TYPE_VOID(v1.t) || TYPE_VOID(v2.t)){
                fputs("binary operator has non-enough operands", stderr);
                exit(-1);
            }
            if (!v1.t.lvalue){
                fputs("lvalue required as left operand of assignment", stderr);
                exit(-1);
            }
            v1.vp->id = v->id = var_newid();
            v->t = v1.t;
            if (v2.t.constexp){
                value_cast_constexp(v->id, &v2, v1.t);
                return;
            }
            emit_assign(v->id, v2.id);
            return;
        default:
            fprintf(stderr, "invalid operator '%hhu'\n", e->sym);
            exit(-1);
        }
        return;
    case ELEM_KEYWORD:
        switch (e->sym){
        case KEYWORD_CHAR:
        case KEYWORD_SHORT:
        case KEYWORD_INT:
        case KEYWORD_LONG:
        case KEYWORD_FLOAT:
        case KEYWORD_DOUBLE:
            if (e->l){
                fputs("unexpected words before variable definition", stderr);
                exit(-1);
            }
            var_def(e->sym, e->r);
            v->t = type_void;
            break;
        case KEYWORD_IF:

            break;
        case KEYWORD_ELSE:
            break;
        case KEYWORD_WHILE:
            break;
        case KEYWORD_FOR:
            break;
        default:
            fprintf(stderr, "unsupported keyword type '%hhu'\n", e->sym);
            exit(-1);
        }
        return;
    case ELEM_STACK:
        // 三种操作
        // 大括号(代码域) => 整体代码块
        // 中括号(索引) => 结合内部执行索引操作
        // 小括号(优先) => 直接返回内部表达式结果
        // 注: 括号右侧可能也会有子元素
        switch (e->attr.type){
        case BRAC_BIG:
            break;
        case BRAC_MIDDLE:
            break;
        case BRAC_SMALL:
            if (!e->l){
                fprintf(stderr, "empty small bracket not allowed\n");
                exit(-1);
            }
            if (e->l->type == ELEM_KEYWORD){
                if (KEYWORD_IS_NONVOID_TYPE(e->l->sym) && e->r && !e->l->l && !e->l->r){
                    dump_ins(e->r, &v2);
                    value_basic_cast(v, &v2, e->l->sym);
                    break;
                }
                fprintf(stderr, "expected primary-expression in small bracket\n");
                exit(-1);
            }
            dump_ins(e->l, v);
            break;
        default:
            fprintf(stderr, "unknown bracket type '%hhu'\n", e->attr.type);
            exit(-1);
        }
        return;
    }
}

void remove_comment(const char* input, char* output){
    int state = 0;
    while (*input){
        switch (state){
        case 0:
            if (*input == '/'){
                state = 1;
            } else {
                *output++ = *input;
            }
            break;
        case 1:
            if (*input == '/'){
                state = 2;
            } else if (*input == '*'){
                state = 3;
            } else {
                *output++ = '/';
                *output++ = *input;
                state = 0;
            }
            break;
        case 2:
            if (*input == '\n'){
                state = 0;
            }
            break;
        case 3:
            if (*input == '*'){
                state = 4;
            }
            break;
        case 4:
            if (*input == '/'){
                state = 0;
            } else {
                state = 3;
            }
            break;
        }
        input++;
    }
    *output = '\0';
}

#define NUM_ELEMENTS 0x400

elem expr[NUM_ELEMENTS];

char buf[0x1000], code[0x1000];

int main(int argc, char** argv){
    // 尝试的编译
    // 1. 将字符分块，变为名称、字面量、关键字、操作符，操作符按左到右顺序合并，运用Trie字典树，同时处理预处理命令、三种括号的栈"{}()[]"
    // 2. 将符号列表构建为笛卡尔树(我可能思路清奇了)，运用单调栈，参与比较的信息有优先级、是否为右至左操作符
    // 3. 后序遍历，每一个新结果分配一个新索引，生成一串运算操作，类似于LLVM IR
    // 4. 树上哈希，寻找重复的子树，从而引用之前的中间结果，可能需要与步骤3同时进行
    // 5. 基于SSA分配寄存器，pbqp、线性扫描算法、整数线性规划算法
    // 6. 指令选择器分配汇编指令
    // 7. 序列化为可执行文件
    init_info();
    build_trie(trie_sign1, tbl_op1);
    build_trie(trie_sign2, tbl_op2);
    init_keywords();
    
    // 计划规定语法 func [type] [name]; 规定函数返回值，然后直接按[name]链接符号，参数强类型
    /*
    const char* code =
        "int a, b;"
        "float c;"
        "a = 1;"
        "c = 1.2;"
        "a += a * a + 2 * 3 * 5;"
        "b = (b - a) * 10;"
        "a *= (int)c;";
    */

   if (argc < 2){
       fputs("no input file", stderr);
       return -1;
   }

   FILE* f = fopen(argv[1], "r");
   fseek(f, 0, SEEK_END);
   int len = ftell(f);
   fseek(f, 0, SEEK_SET);
   fread(buf, 1, len, f);
   fclose(f);

   remove_comment(buf, code);

    // C++声明 [register|static|extern|auto](存储类型) {[struct|union|enum] <type> 括号内任意位置可选[const]} [*[const]]* [&|&&] [[<class>::][<variable>|operator[...]]] [(<T类型>... args) [const(class内部)]|[大小]*] [{初始化列表...|函数体...}|=[构造器|表达式=>非explicit构造]|[()构造器]]
    // 状态: 各种作用域，特别的有命名空间、类、函数、全局、if、else、for、while、do...while、switch，访问修饰

    resolve_exp(expr, code);

    for (int i = 0; expr[i].type != ELEM_END; i++){
        dump_word(expr + i);
    }
    //putchar('\n');

    // elem* top = build_tree(expr, NULL);

    // dump2(top, 0);
    // putchar('\n');

    // fields_init();
    // value v;
    // dump_ins(top, &v);

    return 0;
}