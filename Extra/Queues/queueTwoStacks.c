#include <stdio.h>
#include "../../Implementations/Stacks/Static/Stack.h"

#define N 10

typedef struct {
    stack L, R;
} queue;

queue CreateQueue() {
    queue q;
    q.L = CreateStack();
    q.R = CreateStack();
    return q;
}

int isEmptyQueue(queue q) {
    return isEmptyStack(q.L);
}

int isFullQueue(queue q) {
    return isFullStack(q.L);
}

int EnQueue(queue *q, element p) {
    if(isFullQueue(*q)) return 0;
    element e;
    while(!isEmptyQueue(*q)) {
        Top(q->L, &e);
        Pop(&(q->L));
        Push(&(q->R), e);
    }
    Push(&(q->L), p);
    while(!isEmptyStack(q->R)) {
        Top(q->R, &e);
        Push(&(q->L), e);
        Pop(&(q->R));
    }
    return 1;
}

int DeQueue(queue *q) {
    return Pop(&(q->L));
}

int Front(queue q, element *e) {
    return Top(q.L, e);
}

void printQueue(queue q) {
    element e;
    while(!isEmptyQueue(q)) {
        Front(q, &e);
        printf("%d ", e);
        DeQueue(&q);
    }
    printf("\n");
}

void main() {
    queue q = CreateQueue();
    EnQueue(&q, 1);
    EnQueue(&q, 2);
    EnQueue(&q, 3);
    EnQueue(&q, 4);
    EnQueue(&q, 5);
    printQueue(q);
}