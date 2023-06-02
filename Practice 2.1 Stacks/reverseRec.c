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

void insertAtBottom(stack *s, element e) {
    if(isEmptyStack(*s)) {
        Push(s, e);
        return;
    }
    element o;
    Top(*s, &o);
    Pop(s);
    insertAtBottom(s, e);
    Push(s, o);
}

void reverseStack(stack *s) {
    if(isEmptyStack(*s)) return;
    element e;
    Top(*s, &e);
    Pop(s);
    reverseStack(s);
    insertAtBottom(s, e);
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
    reverseStack(&s);
    printStack(s);
}