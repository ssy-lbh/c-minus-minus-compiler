#ifndef _TYPE_H
#define _TYPE_H

typedef unsigned long long cmm_id_t;
typedef unsigned long long cmm_size_t;
typedef unsigned char cmm_bool_t;
typedef struct _type_t type_t;

typedef struct _type_item_t {
    type_t *type;
    struct _type_item_t *next;
} type_item_t;

typedef struct _type_list_t {
    type_item_t *head;
    type_item_t *tail;
} type_list_t;

typedef enum _access_enum {
    ACC_PUBLIC,
    ACC_PRIVATE,
    ACC_PROTECTED
} access_enum;

typedef struct _member_t {
    char *name;
    type_t *type;
    cmm_size_t offset;
    struct _member_t *next;
} member_t;

typedef struct _record_t {
    char *name;
    member_t *head;
    member_t *tail;
    cmm_size_t size;
    cmm_size_t alignment;
} record_t;

typedef enum _kind_enum {
    KIND_PRIMITIVE,
    KIND_ARRAY,
    KIND_POINTER,
    KIND_RECORD,
    KIND_FUNCTION
} kind_enum;

typedef enum _primitive_enum {
    PRIM_VOID,
    PRIM_CHAR,
    PRIM_SHORT,
    PRIM_INT,
    PRIM_LONG,
    PRIM_FLOAT,
    PRIM_DOUBLE
} primitive_enum;

typedef struct _type_t {
    kind_enum kind;
    union {
        unsigned char   is_const : 1,
                        is_volatile : 1,
                        is_signed : 1;
        unsigned char   flags;
    };
    union {
        primitive_enum prim;
        struct {
            type_t *type;
            cmm_size_t size;
        } array;
        struct {
            type_t *type;
        } pointer;
        struct {
            // don't free this pointer
            record_t *record;
        } record;
        struct {
            type_t *return_type;
            type_list_t *param_types;
        } function;
    };
} type_t;

typedef enum _alloc_enum {
    ALLOC_AUTO,
    ALLOC_REGISTER,
    ALLOC_STATIC,
    ALLOC_EXTERN
} alloc_enum;

typedef struct _declvar_t {
    char *name;
    type_t *type;
    alloc_enum alloc;
} declvar_t;

typedef union _value_t {
    long long l;
    long double d;
    cmm_id_t id;
} value_t;

typedef struct _expr_result_t {
    type_t *type;
    value_t value;
    cmm_bool_t is_constexpr;
} expr_result_t;

#define MACHINE_WORD_SIZE 8

cmm_size_t primitive_size(primitive_enum prim);
cmm_size_t primitive_alignment(primitive_enum prim);
cmm_size_t type_size(type_t *type);
cmm_size_t type_alignment(type_t *type);
type_t *type_copy(type_t *type);
type_t *type_primitive(primitive_enum prim);
type_t *type_array(type_t *type, cmm_size_t size);
type_t *type_pointer(type_t *type);
type_t *type_record(record_t *record);
type_t *type_function(type_t *return_type, type_list_t *param_types);
void type_free(type_t *type);
type_list_t *type_list_new();
void type_list_append(type_list_t *list, type_t *type);
type_list_t *type_list_copy(type_list_t *list);
void type_list_free(type_list_t *list);
record_t *record_new(char *name);
void record_add_member(record_t *record, char *name, type_t *type);
void record_free(record_t *record);

#endif