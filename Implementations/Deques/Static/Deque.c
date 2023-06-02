#include <stdio.h>
#include "Deque.h"

deque CreateDeque() {
    deque d;
    d.front = 1;
    d.rear = 0;
    return d;
}

int isEmptyDeque(deque d) {
    return (d.front == (d.rear + 1) % N);
}

int isFullDeque(deque d) {
    return (d.front == (d.rear + 2) % N);
}

int EnqueueFront(deque *d, element e) {
    if(isFullDeque(*d)) return 0;
    d->front = (d->front - 1 + N) % N;
    d->data[d->front] = e;
    return 1;
}

int DequeueFront(deque *d) {
    if(isEmptyDeque(*d)) return 0;
    d->front = (d->front + 1) % N;
    return 1;
}

int Front(deque d, element *e) {
    if(isEmptyDeque(d)) return 0;
    *e = d.data[d.front];
    return 1;
}

int EnqueueRear(deque *d, element e) {
    if(isFullDeque(*d)) return 0;
    d->rear = (d->rear + 1) % N;
    d->data[d->rear] = e;
    return 1;
}

int DequeueRear(deque *d) {
    if(isEmptyDeque(*d)) return 0;
    d->rear = (d->rear - 1 + N) % N;
    return 1;
}

int Rear(deque d, element *e) {
    if(isEmptyDeque(d)) return 0;
    *e = d.data[d.rear];
    return 1;
}

void printDeque(deque d) {
    element e;
    while(!isEmptyDeque(d)) {
        Front(d, &e);
        printf("%d ", e);
        DequeueFront(&d);
    }
    printf("\n");
}