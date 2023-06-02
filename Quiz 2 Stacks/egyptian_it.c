#include <stdio.h>
#include <stdlib.h>

// Dating back to ancient Egyt, the Egyptian multiplication method does not require memorization of all multiplication tables
// It relies only on the ability to add and to divide by 2
// Recursive function implementng the mentioned method

/*int egyptian_rec(int a, int b) {
    int res;
    if(a == 1) {
        return b;
    }
    res = egyptian_rec(half(a), b + b);
    if(odd(a)) {
        res += b;
    }
    return res;
}*/

// You are asked to derecursivate this function using a stack.
// To do that, first start by drawing its memory state, what happens during the winding and unwinding,
//  then translare it to a code using a stack

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