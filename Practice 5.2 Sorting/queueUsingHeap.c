#include <stdio.h>
#include "Heap.h"

typedef struct {
    Heap H;
    int counter;
} queue;

queue CreateQueue() {
    queue q;
    q.H = CreateHeap(N, 1);
    q.counter = 0;
    return q;
}

int isEmptyQueue(queue q) {
    return isEmptyHeap(q.H);
}

int isFullQueue(queue q) {
    return isFullHeap(q.H);
}

void EnQueue(queue *q, int number) {
    if(isFullHeap(q->H)) return;
    Insert(&(q->H), (element) {q->counter - 1, number});
    q->counter -= 1;
}

int DeQueue(queue *q) {
    if(isEmptyHeap(q->H)) return 0;
    DeleteMax(&(q->H));
    q->counter += 1;
    return 1;
}

int Front(queue q, int *nb) {
    if(isEmptyHeap(q.H)) return 0;
    element e;
    GetMaximum(q.H, &e);
    *nb = e.data;
    return 1;
}

void print(queue q) {
    int e;
    while(Front(q, &e)) {
        DeQueue(&q);
        printf("%d ", e);
    }
    printf("\n");
}

void main() {
    queue q = CreateQueue();
    for(int i = 0; i < 10; i++) EnQueue(&q, i);
    print(q);
}