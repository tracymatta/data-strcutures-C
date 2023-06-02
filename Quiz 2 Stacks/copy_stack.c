#include <stdio.h>
#include "../Implementations/Stacks/Static/Stack.h"

// Write an iterative program that copies the content of stack s1 int s2
// Resulting stacks should have same elements in the same order 

void printStack(stack s) {
    element e;
    while(!isEmptyStack(s)) {
        Top(s, &e);
        printf("%d ", e);
        Pop(&s);
    }
    printf("\n");
}

void copy_stack(stack *s1, stack *s2) {
    stack s3 = CreateStack();
    element e;
    while(isEmptyStack(*s1) == 0) {
        Top(*s1, &e);
        Pop(s1);
        Push(&s3, e);
    }
    while(isEmptyStack(s3) == 0) {
        Top(s3, &e);
        Pop(&s3);
        Push(s1, e);
        Push(s2, e);
    }
}

void main() {
    stack s1 = CreateStack();
    stack s2 = CreateStack();
    Push(&s1, 5);
    Push(&s1, 4);
    Push(&s1, 3);
    Push(&s1, 2);
    Push(&s1, 1);
    printStack(s1);
    copy_stack(&s1, &s2);
    printStack(s1);
    printStack(s2);
}