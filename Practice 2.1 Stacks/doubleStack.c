#include <stdio.h>

#define N 10

typedef int element;

typedef struct {
    element data[N];
    int top1, top2;
} stack; 

stack CreateStack() {
    stack p;
    p.top1 = -1;
    p.top2 = N;
    return p;
}

int isEmptyStack(stack p, int flag) {
    if (flag == 1) return p.top1 == -1;
    return p.top2 == N;
}

int isFullStack(stack p) {
    return p.top1 == p.top2 - 1;
}

int Push(stack *p, element e, int flag) {
    if(isFullStack(*p)) return 0;
    if(flag == 1) {
        p->data[++p->top1] = e;
        return 1;
    }
    p->data[--p->top2] = e;
    return 1;
}

int Pop(stack *p, int flag) {
    if(flag == 1){
        if(isEmptyStack(*p, 1)) return 0;
        p->top1--;
        return 1;
    }
    if(isEmptyStack(*p, 2)) return 0;
    p->top2++;
    return 1;
}

int Top(stack p, element *e, int flag) {
    if(flag == 1){
        if(isEmptyStack(p, 1)) return 0;
        *e = p.data[p.top1];
        return 1;
    }
    if(isEmptyStack(p, 2)) return 0;
    *e = p.data[p.top2];
    return 1;
}

void printStack(stack s, int flag) {
    int e;
    while(!isEmptyStack(s, flag)) {
        Top(s, &e, flag);
        printf("%d ", e);
        Pop(&s, flag);
    }
    printf("\n");
}

void main() {
    stack s = CreateStack();
    Push(&s, 4, 1);
    Push(&s, -5, 1);
    Pop(&s, 2);
    Pop(&s, 2);
    Push(&s, 6, 2);
    Push(&s, 2, 2);
    Push(&s, 1, 1);
    Pop(&s, 1);
    printf("S1: ");
    printStack(s, 1);
    printf("S2: ");
    printStack(s, 2);
}