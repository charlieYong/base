#include <stdlib.h>
#include "list.h"

list*  listCreate(void) {
    list* l = (list*)malloc(sizeof(*l));
    if (NULL == l) return NULL;
    l->head = NULL;
    l->tail = l->head;
    l->len = 0;
    return l;
}

void listRelease(list* l, freeValueProc* freeProc) {
    if (NULL == l) return;
    listNode *p = l->head, *next = NULL;
    while (p) {
        next = p->next;
        if (freeProc) freeProc(p->value);
        free(p);
        p = next;
    }
    free(l);
    l = NULL;
}

listNode* listAdd(list* l, void* value) {
    if (NULL == value || NULL == l) return NULL;
    listNode* node = (listNode*)malloc(sizeof(*node));
    if (NULL == node) return;
    node->next = NULL;
    node->value = value;
    if (l->tail) {
        l->tail->next = node;
        l->tail = node;
    } else {
        l->tail = l->head = node;
    }
    l->len ++;
    return node;
}

listNode* listSearch(list* l, void* value) {
    if (NULL == value || NULL == l) return NULL;
    listNode* p = l->head;
    while (p && p->value != value) {
        p = p->next;
    }
    return p;
}

int listDelete(list* l, void* value) {
    if (NULL == value || NULL == l) return -1;
    listNode** pp = &(l->head);
    listNode* prev = NULL;
    while (*pp && (*pp)->value != value) {
        prev = *pp;
        pp = &((*pp)->next);
    }
    if (NULL == *pp) // not found
        return -1;
    listNode* node = *pp;
    if (node == l->tail) // update list->tail
        l->tail = prev;
    *pp = node->next;
    free(node);
    return 0;
}
