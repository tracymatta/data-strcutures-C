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

int add(stack s) {
    element sum = 0, top;
    while(!isEmptyStack(s)) {
        Top(s, &top);
        Pop(&s);
        sum += top;
    }
    return sum;
}

void main() {
    stack s = CreateStack();
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 5);
    printStack(s);
    printf("%d\n", add(s));
    printStack(s);
}