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

void interchange(stack *s) {
    if(isEmptyStack(*s)) return;
    element first, second;
    Top(*s, &first);
    Pop(s);
    if(isEmptyStack(*s)) {
        Push(s, first);
        return;
    }
    Top(*s, &second);
    Pop(s);
    Push(s, first);
    Push(s, second);
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
    interchange(&s);
    printStack(s);
}