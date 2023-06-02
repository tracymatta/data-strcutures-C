#include <stdio.h>
#include "../Implementations/Queues/Static/Queue.h"
#include "../Implementations/Stacks/Static/Stack.h"

void reverse(stack *s) {
    element e;
    queue q = CreateQueue();
    while(!isEmptyStack(*s)) {
        Top(*s, &e);
        Pop(s);
        EnQueue(&q, e);
    }
    while(!isEmptyQueue(q)) {
        Front(q, &e);
        Dequeue(&q);
        Push(s, e);
    }
}

void main() {
    stack s = CreateStack();
    Push(&s, 2);
    Push(&s, 5);
    Push(&s, 8);
    Push(&s, 3);
    Push(&s, 9);
    Push(&s, 6);
    Push(&s, 4);
    Push(&s, 1);
    Push(&s, 7);
    printStack(s);
    reverse(&s);
    printStack(s);
}