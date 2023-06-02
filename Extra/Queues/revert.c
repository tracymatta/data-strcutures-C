#include <stdio.h>
#include "../../Implementations/Stacks/Static/Stack.h"
#include "../../Implementations/Queues/Static/Queue.h"

void revert(queue *q) {
    if(isEmptyQueue(*q)) return;
    element e;
    Front(*q, &e);
    Dequeue(q);
    revert(q);
    EnQueue(q, e);
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
    revert(&toRevert);
    printQueue(toRevert);
}