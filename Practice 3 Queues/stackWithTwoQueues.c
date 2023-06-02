#include <stdio.h>
#include "../Implementations/Queues/Static/Queue.h"

typedef struct {
    queue L, R;
} stack;

stack CreateStack() {
    stack s;
    s.L = CreateQueue();
    s.R = CreateQueue();
    return s;
}

int isEmptyStack(stack s) {
    return isEmptyQueue(s.L);
}

int isFullStack(stack s) {
    return isFullQueue(s.L);
}

int Push(stack *s, element e) {
    if(isFullStack(*s)) return 0;
	EnQueue(&(s->L), e) ;
	return 1;
}

int Pop(stack *s) {
    if(isEmptyStack(*s)) return 0;
    element e;
    while(1) {
        Front(s->L, &e);
        Dequeue(&(s->L));
        if(isEmptyQueue(s->L)) break;
        EnQueue(&(s->R), e);
    }
    while(!isEmptyQueue(s->R)) {
        Front(s->R, &e);
        EnQueue(&(s->L), e);
        Dequeue(&(s->R));
    }
    return 1;
}

int Top(stack s, element *p) {
    if(isEmptyStack(s)) return 0;
    element e;
    while(1) {
        Front(s.L, &e);
        Dequeue(&(s.L));
        if(isEmptyQueue(s.L)) {
            *p = e;
            break;
        } 
        EnQueue(&(s.R), e);
    }
    return 1;
}

void printStack(stack s) {
    element e;
    while(!isEmptyStack(s)) {
        Top(s, &e);
        printf("%d ", e);
        Pop(&s);
    }
    printf("\n");
}

void main() {
    stack s = CreateStack();
    Push(&s, 5);
    Push(&s, 4);
    Push(&s, 3);
    Push(&s, 2);
    Push(&s, 1);
    printStack(s);
}