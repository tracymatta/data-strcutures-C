#include <stdio.h>
#include "../Implementations/Stacks/Static/Stack.h"

// Write a recursive function that keeps only unique elements in a stack

void uniqueHelper(stack *s, int data, int *flag) {
    if(isEmptyStack(*s)) return;
    element e;
    Top(*s, &e);
    Pop(s);
    uniqueHelper(s, data, flag);
    if(e != data) Push(s, e);
    else *flag = 1;
}

void unique(stack *s) {
    if(isEmptyStack(*s)) return;
    element e;
    int flag = 0;
    Top(*s, &e);
    Pop(s);
    uniqueHelper(s, e, &flag);
    unique(s);
    if(flag == 0) Push(s, e);
}

void main() {
    stack s = CreateStack();
    Push(&s, 5);
    Push(&s, 5);
    Push(&s, 6);
    Push(&s, 3);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 2);
    printStack(s);
    unique(&s);
    printStack(s);
}