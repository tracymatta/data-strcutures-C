#include <stdio.h>
#include "../Implementations/Queues/Static/Queue.h"
#include "../Implementations/Stacks/Static/Stack.h"

void reverts(queue *q) {
    stack s = CreateStack();
    element e;
    while(!isEmptyQueue(*q)) {
        Front(*q, &e);
        Push(&s, e);
        Dequeue(q);
    }
    while(!isEmptyStack(s)) {
        Top(s, &e);
        EnQueue(q, e);
        Pop(&s);
    }
}

void main() {
    queue toRevert = CreateQueue();
    EnQueue(&toRevert, 2);
    EnQueue(&toRevert, 5);
    EnQueue(&toRevert, 8);
    EnQueue(&toRevert, 3);
    EnQueue(&toRevert, 9);
    EnQueue(&toRevert, 6);
    EnQueue(&toRevert, 4);
    EnQueue(&toRevert, 1);
    EnQueue(&toRevert, 7);
    printQueue(toRevert);
    reverts(&toRevert);
    printQueue(toRevert);
}