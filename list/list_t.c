#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct listNodeValue {
    int fd;
} nodeValue;

void printList(list* l) {
    if (NULL == l) {
        printf("empty list\n");
        return;
    }
    listNode* p = l->head;
    while (p) {
        printf("%d", ((nodeValue*)(p->value))->fd);
        p = p->next;
        if (p) {
            printf(" -> ");
        }
    }
    printf("\n");
}

nodeValue* createNodeValue(int i) {
    nodeValue* v = (nodeValue*)malloc(sizeof(*v));
    v->fd = i;
    return v;
}

#define NODE_NUM 10
int main(int argc, char** argv) {
    list* l = listCreate();
    if (NULL == l) {
        printf("fail to create list\n");
        return -1;
    }
    nodeValue *value = NULL;
    nodeValue* valueList[NODE_NUM] = {NULL};
    int i;
    for (i=0; i<NODE_NUM; i++) {
        value = createNodeValue(i);
        valueList[i] = value;
        if (listAdd(l, value)) {
            printf("add %d to list ok, len=%lu\n", value->fd, listLength(l));
        }
    }
    printList(l);
    i = 9;
    while (i > 0) {
        listNode* node = listSearch(l, valueList[i]);
        printf("%dth node:fd=%d\n", i+1, ((nodeValue*)(node->value))->fd);
        i = i/2;
    }
    i = 0;
    while (i < NODE_NUM) {
        if (0 == listDelete(l, valueList[i])) {
            printf("delete %dth node:", i+1);
            printList(l);
        }
        if (valueList[i]) free(valueList[i]);
        i += 3;
    }
    listRelease(l, free);
    return 0;
}
