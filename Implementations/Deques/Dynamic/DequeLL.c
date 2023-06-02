#include <stdio.h>
#include <stdlib.h>
#include "DequeLL.h"

deque CreateDeque() {
    deque d;
    d.front = NULL;
    d.rear = NULL;
    return d;
}

int isEmptyDeque(deque d) {
    return d.front == NULL;
}

int EnqueueFront(deque *d, element e) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = e;
    newNode->next = d->front;
    if(isEmptyDeque(*d)) d->rear = newNode;
    d->front = newNode;
    return 1;
}

int DequeueFront(deque *d) {
    if(isEmptyDeque(*d)) return 0;
    node *toFree = d->front;
    d->front = d->front->next;
    if(isEmptyDeque(*d)) d->rear = NULL;
    free(toFree);
    return 1;
}

int Front(deque d, element *e) {
    if(isEmptyDeque(d)) return 0;
    *e = d.front->data;
    return 1;
}

int EnqueueRear(deque *d, element e) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = e;
    newNode->next = NULL;
    if(isEmptyDeque(*d)){
        d->front = d->rear = newNode;
    } 
    else {
        d->rear->next = newNode;
        d->rear = d->rear->next;
    }
    return 1;
}

int DequeueRear(deque *d) {
    if(isEmptyDeque(*d)) return 0;
    if(d->front == d->rear) {
        free(d->front);
        d->front = d->rear = NULL;
    }
    else {
        node *toFind = d->front;
        while(toFind->next != d->rear) {
            toFind = toFind->next;
        }
        toFind->next = NULL;
        free(d->rear);
        d->rear = toFind;
    }
    return 1;
}

int Rear(deque d, element *e) {
    if(isEmptyDeque(d)) return 0;
    *e = d.rear->data;
    return 1;
}

void printDeque(deque d) {
    element e;
    deque q = CreateDeque();
    while(!isEmptyDeque(d)) {
        Front(d, &e);
        printf("%d ", e);
        DequeueFront(&d);
        EnqueueRear(&q, e);
    }
    while(!isEmptyDeque(q)) {
        Front(q, &e);
        DequeueFront(&q);
        EnqueueRear(&d, e);
    }
    printf("\n");
}
