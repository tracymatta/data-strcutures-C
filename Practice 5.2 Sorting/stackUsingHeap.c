#include <stdio.h>
#include "Heap.h"

typedef struct {
    Heap H;
    int counter;
} stack;

stack CreateStack() {
    stack s;
    s.H = CreateHeap(N, 1);
    s.counter = 0;
    return s;
}

int isEmptyStack(stack s) {
    return isEmptyHeap(s.H);
}

int isFullStack(stack s) {
    return isFullHeap(s.H);
}

void Push(stack *s, int number) {
    if(isFullHeap(s->H)) return;
    Insert(&(s->H), (element) {s->counter + 1, number});
    s->counter += 1;
}

int Pop(stack *s) {
    if(isEmptyHeap(s->H)) return 0;
    DeleteMax(&(s->H));
    s->counter -= 1;
    return 1;
}

int Top(stack s, int *nb) {
    if(isEmptyHeap(s.H)) return 0;
    element e;
    GetMaximum(s.H, &e);
    *nb = e.data;
    return 1;
}

void print(stack s) {
    int e;
    while(Top(s, &e)) {
        Pop(&s);
        printf("%d\n", e);
    }
    printf("\n");
}

void main() {
    stack s = CreateStack();
    for(int i = 0; i < 10; i++) Push(&s, i);
    print(s);
}