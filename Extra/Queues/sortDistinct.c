#include <stdio.h>
#include "../../Implementations/Queues/Static/Queue.h"

void switchQueues(queue *q, queue *p) {
    if(isEmptyQueue(*p)) return;
    element e;
    Front(*p, &e);
    Dequeue(p);
    EnQueue(q, e);
    switchQueues(q, p);
}

void sortDistinctHelper(queue *q, queue *p) {
    if(isEmptyQueue(*q)) return;
    element e;
    Front(*q, &e);
    Dequeue(q);
    if(e % 2 == 0) EnQueue(p, e);
    sortDistinctHelper(q, p);
    if(e % 2 == 1) EnQueue(p, e); 
}

void sortDistinct(queue *q) {
    queue helpQueue = CreateQueue();
    sortDistinctHelper(q, &helpQueue);
    switchQueues(q, &helpQueue);
}

void main() {
    queue toSortQueue = CreateQueue();
    EnQueue(&toSortQueue, 2);
    EnQueue(&toSortQueue, 5);
    EnQueue(&toSortQueue, 8);
    EnQueue(&toSortQueue, 3);
    EnQueue(&toSortQueue, 9);
    EnQueue(&toSortQueue, 6);
    EnQueue(&toSortQueue, 4);
    EnQueue(&toSortQueue, 1);
    EnQueue(&toSortQueue, 7);
    printQueue(toSortQueue);
    sortDistinct(&toSortQueue);
    printQueue(toSortQueue);
}