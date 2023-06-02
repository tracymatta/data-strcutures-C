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

int insert(stack *s, element e, int k) {
    if(isFullStack(*s)) return 0;
    stack p = CreateStack();
    element t;
    while(k > 1 && !isEmptyStack(*s)) {
        Top(*s, &t);
        Push(&p, t);
        Pop(s);
        k--;
    }
    Push(s, e);
    while(!isEmptyStack(p)) {
        Top(p, &t);
        Push(s, t);
        Pop(&p);
    }
    return 1;
}

void main() {
    stack s = CreateStack();
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 5);
    printStack(s);
    printf("%d inserted at position: %d\n", 1, 4);
    insert(&s, 1, 4);
    printStack(s);
}