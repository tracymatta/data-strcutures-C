#include <stdio.h>
#include "../../Implementations/Queues/Static/Queue.h"
#include "../../Implementations/Stacks/Static/Stack.h"

void queueToStack(stack *s, queue q) {
    element e;
    while(!isEmptyQueue(q)) {
        Front(q, &e);
        Dequeue(&q);
        Push(s, e);
    }
}

void main() {
    stack s = CreateStack();
    Push(&s, 7);
    Push(&s, 1);
    Push(&s, 4);
    Push(&s, 6);
    queue q = CreateQueue();
    EnQueue(&q, 9);
    EnQueue(&q, 3);
    EnQueue(&q, 8);
    EnQueue(&q, 5);
    EnQueue(&q, 2);
    printStack(s);
    queueToStack(&s, q);
    printStack(s);
}