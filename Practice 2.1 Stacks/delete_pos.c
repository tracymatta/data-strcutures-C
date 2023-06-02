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

int delete_pos(stack *s, int k) {
    if(k < 1) return 0;
    stack p = CreateStack();
    element t;
    int flag = 1;
    while(k > 1 && !isEmptyStack(*s)) {
        Top(*s, &t);
        Push(&p, t);
        Pop(s);
        k--;
    }
    if(k > 1) flag = 0;
    else Pop(s);
    while(!isEmptyStack(p)) {
        Top(p, &t);
        Push(s, t);
        Pop(&p);
    }
    return flag;
}

void main() {
    stack s = CreateStack();
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 5);
    printStack(s);
    printf("Element deleted at position: %d\n", 4);
    delete_pos(&s, 4);
    printStack(s);
}