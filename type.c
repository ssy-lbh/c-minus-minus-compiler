#include "type.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

cmm_size_t primitive_size(primitive_enum prim){
    switch(prim){
        case PRIM_VOID:
            return 0;
        case PRIM_CHAR:
            return 1;
        case PRIM_SHORT:
            return 2;
        case PRIM_INT:
            return 4;
        case PRIM_LONG:
            return 8;
        case PRIM_FLOAT:
            return 4;
        case PRIM_DOUBLE:
            return 8;
        default:
            printf("Unknown primitive type: %d\n", prim);
            return 0;
    }
}

cmm_size_t primitive_alignment(primitive_enum prim){
    switch(prim){
        case PRIM_VOID:
            return 0;
        case PRIM_CHAR:
            return 1;
        case PRIM_SHORT:
            return 2;
        case PRIM_INT:
            return 4;
        case PRIM_LONG:
            return 8;
        case PRIM_FLOAT:
            return 4;
        case PRIM_DOUBLE:
            return 8;
        default:
            printf("Unknown primitive type: %d\n", prim);
            return 0;
    }
}

cmm_size_t type_size(type_t *type){
    switch(type->kind){
        case KIND_PRIMITIVE:
            return primitive_size(type->prim);
        case KIND_ARRAY:
            return type->array.size * type_size(type->array.type);
        case KIND_POINTER:
            return MACHINE_WORD_SIZE;
        case KIND_RECORD:
            return type->record.record->size;
        case KIND_FUNCTION:
            return MACHINE_WORD_SIZE;
        default:
            printf("Unknown type kind: %d\n", type->kind);
            return 0;
    }
}

cmm_size_t type_alignment(type_t *type){
    switch(type->kind){
        case KIND_PRIMITIVE:
            return primitive_alignment(type->prim);
        case KIND_ARRAY:
            return type_alignment(type->array.type);
        case KIND_POINTER:
            return MACHINE_WORD_SIZE;
        case KIND_RECORD:
            return type->record.record->alignment;
        case KIND_FUNCTION:
            return MACHINE_WORD_SIZE;
        default:
            printf("Unknown type kind: %d\n", type->kind);
            return 0;
    }
}

type_t *type_copy(type_t *type){
    type_t *new_type = (type_t *)malloc(sizeof(type_t));
    memcpy(new_type, type, sizeof(type_t));
    switch(type->kind){
        case KIND_PRIMITIVE:
            break;
        case KIND_ARRAY:
            new_type->array.type = type_copy(type->array.type);
            break;
        case KIND_POINTER:
            new_type->pointer.type = type_copy(type->pointer.type);
            break;
        case KIND_RECORD:
            new_type->record.record = type->record.record;
            break;
        case KIND_FUNCTION:
            new_type->function.return_type = type_copy(type->function.return_type);
            new_type->function.param_types = type_list_copy(type->function.param_types);
            break;
        default:
            printf("Unknown type kind: %d\n", type->kind);
            break;
    }
    return new_type;
}

type_t *type_primitive(primitive_enum prim){
    type_t *type = (type_t *)malloc(sizeof(type_t));
    type->kind = KIND_PRIMITIVE;
    type->prim = prim;
    type->flags = 0;
    return type;
}

type_t *type_array(type_t *type, cmm_size_t size){
    type_t *new_type = (type_t *)malloc(sizeof(type_t));
    new_type->kind = KIND_ARRAY;
    new_type->array.type = type;
    new_type->array.size = size;
    new_type->flags = 0;
    return new_type;
}

type_t *type_pointer(type_t *type){
    type_t *new_type = (type_t *)malloc(sizeof(type_t));
    new_type->kind = KIND_POINTER;
    new_type->pointer.type = type;
    new_type->flags = 0;
    return new_type;
}

type_t *type_record(record_t *record){
    type_t *new_type = (type_t *)malloc(sizeof(type_t));
    new_type->kind = KIND_RECORD;
    new_type->record.record = record;
    new_type->flags = 0;
    return new_type;
}

type_t *type_function(type_t *return_type, type_list_t *param_types){
    type_t *new_type = (type_t *)malloc(sizeof(type_t));
    new_type->kind = KIND_FUNCTION;
    new_type->function.return_type = return_type;
    new_type->function.param_types = param_types;
    new_type->flags = 0;
    return new_type;
}

void type_free(type_t *type){
    switch(type->kind){
        case KIND_PRIMITIVE:
            break;
        case KIND_ARRAY:
            type_free(type->array.type);
            break;
        case KIND_POINTER:
            type_free(type->pointer.type);
            break;
        case KIND_RECORD:
            break;
        case KIND_FUNCTION:
            type_free(type->function.return_type);
            type_list_free(type->function.param_types);
            break;
        default:
            printf("Unknown type kind: %d\n", type->kind);
            break;
    }
    free(type);
}

type_list_t *type_list_new(){
    type_list_t *list = (type_list_t *)malloc(sizeof(type_list_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void type_list_append(type_list_t *list, type_t *type){
    type_item_t *node = (type_item_t *)malloc(sizeof(type_item_t));
    node->type = type;
    node->next = NULL;
    if (list->head == NULL){
        list->head = node;
        list->tail = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }
}

type_list_t *type_list_copy(type_list_t *list){
    type_list_t *new_list = type_list_new();
    type_item_t *node = list->head;
    while(node != NULL){
        type_list_append(new_list, type_copy(node->type));
        node = node->next;
    }
    return new_list;
}

void type_list_free(type_list_t *list){
    type_item_t *node = list->head;
    while(node != NULL){
        type_item_t *next = node->next;
        type_free(node->type);
        free(node);
        node = next;
    }
    free(list);
}

record_t *record_new(char *name){
    record_t *record = (record_t *)malloc(sizeof(record_t));
    record->name = strdup(name);
    record->head = NULL;
    record->tail = NULL;
    record->size = 0;
    record->alignment = 0;
    return record;
}

static void upper_align(cmm_size_t *size, cmm_size_t alignment){
    if ((*size & (alignment - 1)) != 0){
        *size += alignment - (*size & (alignment - 1));
    }
}

void record_add_member(record_t *record, char *name, type_t *type){
    cmm_size_t alignment = type_alignment(type);
    // record size must be aligned
    if (record->alignment < alignment){
        record->alignment = alignment;
    }
    upper_align(&record->size, alignment);

    member_t *member = (member_t *)malloc(sizeof(member_t));
    member->name = strdup(name);
    member->type = type;
    member->offset = record->size;
    member->next = NULL;

    if (record->head == NULL){
        record->head = member;
        record->tail = member;
    }else{
        record->tail->next = member;
        record->tail = member;
    }
}

void record_free(record_t *record){
    member_t *member = record->head;
    while(member != NULL){
        member_t *next = member->next;
        free(member->name);
        type_free(member->type);
        free(member);
        member = next;
    }
    free(record->name);
    free(record);
}