#ifndef _DICT_H_
#define _DICT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 0x100
#define DEFAULT_DICT_SIZE 8

typedef struct _dict_item {
    char word[MAX_WORD_LEN];
    void* value;
    struct _dict_item *next;
} dict_item;

typedef struct _dict {
    dict_item **items;
    int capacity;
    int mask;
} dict;

dict *dict_new(int bit);
void dict_free(dict *d);
void dict_set(dict *d, char *word, void* value);
void **dict_get(dict *d, const char *word);
void dict_clear(dict *d);
void dict_print(dict *d);
void dict_foreach(dict *d, void (*func)(char *, void*));

#endif