#include "dict.h"

#include <stdio.h>
#include <stdlib.h>

// This is a hash function that takes a string and returns an integer.
// It is used to convert a string into an array index.
// It is not a very good hash function, but it is simple.
int hash(const char *s){
    int h = 0;
    for(int i = 0; s[i] != '\0'; i++){
        h = h * 31 + s[i];
    }
    return h;
}

dict *dict_new(int bit){
    dict *d = malloc(sizeof(dict));
    d->capacity = 1 << bit;
    d->mask = d->capacity - 1;
    d->items = malloc(sizeof(dict_item*) * d->capacity);
    for (int i = 0; i < d->capacity; i++){
        d->items[i] = NULL;
    }
    return d;
}

void dict_free(dict *d){
    for (int i = 0; i < d->capacity; i++){
        dict_item *item = d->items[i];
        while (item != NULL){
            dict_item *next = item->next;
            free(item);
            item = next;
        }
    }
    free(d->items);
    free(d);
}

void dict_set(dict *d, char *word, void *value){
    int h = hash(word);
    int index = h & d->mask;
    dict_item *item = d->items[index];
    while (item != NULL){
        if (strcmp(item->word, word) == 0){
            item->value = value;
            return;
        }
        item = item->next;
    }
    item = malloc(sizeof(dict_item));
    strcpy(item->word, word);
    item->value = value;
    item->next = d->items[index];
    d->items[index] = item;
}

void **dict_get(dict *d, const char *word){
    int h = hash(word);
    int index = h & d->mask;
    dict_item *item = d->items[index];
    while (item != NULL){
        if (strcmp(item->word, word) == 0){
            return &item->value;
        }
        item = item->next;
    }
    return NULL;
}

void dict_clear(dict *d){
    for (int i = 0; i < d->capacity; i++){
        dict_item *item = d->items[i];
        while (item != NULL){
            dict_item *next = item->next;
            free(item);
            item = next;
        }
        d->items[i] = NULL;
    }
}

void dict_print(dict *d){
    for (int i = 0; i < d->capacity; i++){
        dict_item *item = d->items[i];
        while (item != NULL){
            printf("%s: %ld\n", item->word, (long)item->value);
            item = item->next;
        }
    }
}

void dict_foreach(dict *d, void (*func)(char *, void*)){
    for (int i = 0; i < d->capacity; i++){
        dict_item *item = d->items[i];
        while (item != NULL){
            func(item->word, item->value);
            item = item->next;
        }
    }
}