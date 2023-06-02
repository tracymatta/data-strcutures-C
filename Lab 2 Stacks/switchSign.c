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

void switchSign(stack *s) {
    if(isEmptyStack(*s)) return;
    element e;
    Top(*s, &e);
    Pop(s);
    switchSign(s);
    Push(s, -e);
}

void main() {
    stack s = CreateStack();
    Push(&s, 33);
    Push(&s, 21);
    Push(&s, -48);
    Push(&s, 34);
    printStack(s);
    switchSign(&s);
    printStack(s);
}