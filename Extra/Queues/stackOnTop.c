#include <stdio.h>
#include "../../Implementations/Stacks/Static/Stack.h"
#include "../../Implementations/Queues/Static/Queue.h"

void stackOnTop(stack *s, stack p) {
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
    while(!isEmptyStack(p)) {
        Top(p, &e);
        Pop(&p);
        Push(s, e);
    }
}

void main() {
    stack s = CreateStack();
    Push(&s, 6);
    Push(&s, 4);
    Push(&s, 1);
    Push(&s, 7);
    stack p = CreateStack();
    Push(&p, 2);
    Push(&p, 5);
    Push(&p, 8);
    Push(&p, 3);
    Push(&p, 9);
    printStack(s);
    stackOnTop(&s, p);
    printStack(s);
}