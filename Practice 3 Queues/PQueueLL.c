#include <stdio.h>
#include <stdlib.h>
#include "../Implementations/Priority Queues/Dynamic/PQueueLL.h"

pqueue CreatePQueue() {
    pqueue p;
    p.front = NULL;
    return p;
}

int isEmptyPQueue(pqueue p) {
    return p.front == NULL;
}

int EnQueuePQueue(pqueue *p, element e, int priority) {
    node **toUpdate = &(p->front);
    while((*toUpdate) != NULL && (*toUpdate)->priority <= priority) {
        toUpdate = &((*toUpdate)->next);
    }
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = e;
    newNode->priority = priority;
    newNode->next = (*toUpdate);
    (*toUpdate) = newNode;
    return 1;
}

int Front(pqueue p, element *e) {
    if(isEmptyPQueue(p)) return 0;
    *e = p.front->data;
    return 1;
}

int DeQueuePQueue(pqueue *p) {
    if(isEmptyPQueue(*p)) return 0;
    node *toFree = p->front;
    p->front = p->front->next;
    free(toFree);
    return 1;
}

int DeleteValue(pqueue *p, element e) {
    node **toUpdate = &(p->front);
    while((*toUpdate) != NULL && (*toUpdate)->data != e) {
        toUpdate = &((*toUpdate)->next);
    }
    if((*toUpdate) == NULL) return 0;
    node *toFree = (*toUpdate);
    (*toUpdate) = (*toUpdate)->next;
    free(toFree);
    return 1;
}

void UpdatePriority(pqueue *p, element e, int priority) {
    if(DeleteValue(p, e)) EnQueuePQueue(p, e, priority);
}

void printPQueue(pqueue p) {
    node *toPrint = p.front;
    while(toPrint != NULL) {
        printf("(%d,%d)  ", toPrint->data, toPrint->priority);
        toPrint = toPrint->next;
    }
    printf("\n");
}

void main() {
    pqueue q = CreatePQueue();
    EnQueuePQueue(&q, 10, 2);
    UpdatePriority(&q, 11, 4);
    EnQueuePQueue(&q, 12, 3);
    EnQueuePQueue(&q, 122, 3);
    UpdatePriority(&q, 122, 2);
    printPQueue(q);
}