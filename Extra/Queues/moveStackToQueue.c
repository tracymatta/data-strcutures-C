#include <stdio.h>
#include "Queue.h"
#include "../../Implementations/Stacks/Static/Stack.h"

void stackToQueue(queue *q, stack s) {
    element e;
    while(!isEmptyStack(s)) {
        Top(s, &e);
        Pop(&s);
        EnQueue(q, e);
    }
}

void main() {
    queue q = CreateQueue();
    EnQueue(&q, 2);
    EnQueue(&q, 5);
    EnQueue(&q, 8);
    EnQueue(&q, 3);
    EnQueue(&q, 9);
    stack s = CreateStack();
    Push(&s, 7);
    Push(&s, 1);
    Push(&s, 4);
    Push(&s, 6);
    printQueue(q);
    stackToQueue(&q, s);
    printQueue(q);
}