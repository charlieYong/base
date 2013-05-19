#ifndef __BASELIB_LIST_H__
#define __BASELIB_LIST_H__

typedef struct listNode {
    struct listNode* next;
    void* value;
} listNode;

typedef struct list {
    struct listNode* head;
    struct listNode* tail;
    unsigned long len;
} list;

typedef void freeValueProc(void* value);

#define listLength(l) ((l)->len)

list* listCreate(void);
void listRelease(list* l, freeValueProc* free);
listNode* listAdd(list* l, void* value);
listNode* listSearch(list* l, void* value);
int listDelete(list* l, void* value);

#endif
