#include <stdio.h>
#include "../Implementations/Stacks/Static/Stack.h"

void printStack(stack s) {
    int e;
    while(!isEmptyStack(s)) {
        Top(s, &e);
        printf("%d ", e);
        Pop(&s);
    }
    printf("\n");
}

void reverse(stack *s) {
    stack p = CreateStack(), q = CreateStack();
    element e;
    while(!isEmptyStack(*s)) {
        Top(*s, &e);
        Push(&p, e);
        Pop(s);
    }
    while(!isEmptyStack(p)) {
        Top(p, &e);
        Push(&q, e);
        Pop(&p);
    }
    while(!isEmptyStack(q)) {
        Top(q, &e);
        Push(s, e);
        Pop(&q);
    }
}

void main() {
    stack s = CreateStack();
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 5);
    Push(&s, 6);
    printStack(s);
    reverse(&s);
    printStack(s);
}