#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    int a, b;
} element;

typedef struct {
    element data[N];
    int top;
} stack; 

stack CreateStack() {
    stack p;
    p.top = -1;
    return p;
}

int isEmptyStack(stack p) {
    return p.top == -1;
}

int isFullStack(stack p) {
    return p.top == N-1;
}

int Push(stack *p, element e) {
    if(isFullStack(*p)) return 0;
    p->data[++p->top] = e;
    return 1;
}

int Pop(stack *p) {
    if(isEmptyStack(*p)) return 0;
    p->top--;
    return 1;
}

int Top(stack p, element *e) {
    if(isEmptyStack(p)) return 0;
    *e = p.data[p.top];
    return 1;
}

void printStack(stack s) {
    element e;
    while(!isEmptyStack(s)) {
        Top(s, &e);
        printf("%d %d ", e.a, e.b);
        Pop(&s);
    }
    printf("\n");
}

int egyptian_it(int a, int b) {
    if(a == 1) return b;
    int result = 0;
    element e;
    stack s = CreateStack();
    while(a != 1) {
        e.a = a;
        e.b = b;
        Push(&s, e);
        a = a / 2;
        b = b + b;
    }
    result = b;
    while(!isEmptyStack(s)) {
        Top(s, &e);
        if(e.a % 2 == 1) {
            result += e.b;
        }
        Pop(&s);
    }
    return result;
}

void main() {
    printf("%d\n", egyptian_it(12, 3));
}