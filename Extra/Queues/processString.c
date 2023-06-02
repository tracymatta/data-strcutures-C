#include <stdio.h>

#define N 10

typedef char element;

typedef struct {
    element data[N];
    int front, rear;
} queue; 

queue CreateQueue() {
    queue q;
    q.front = 1;
    q.rear = 0;
    return q;
}

int isEmptyQueue(queue q) {
    return (q.front == (q.rear + 1) % N);
}

int isFullQueue(queue q) {
    return (q.front == (q.rear + 2) % N);
}

int EnQueue(queue *q, element e) {
    if(isFullQueue(*q)) return 0;
    q->rear = (q->rear + 1) % N;
    q->data[q->rear] = e;
    return 1; 
}

int Dequeue(queue *q) {
    if(isEmptyQueue(*q)) return 0;
    q->front = (q->front + 1) % N;
    return 1;
}

int Front(queue q, element *e) {
    if(isEmptyQueue(q)) return 0;
    *e = q.data[q.front];
    return 1;
}

void printQueue(queue q) {
    element e;
    while(!isEmptyQueue(q)) {
        Front(q, &e);
        printf("%d ", e);
        Dequeue(&q);
    }
    printf("\n");
}

char processString(char *str) {
    queue firstHalf = CreateQueue();
    while(*str != '\0' && *str != ':') {
        EnQueue(&firstHalf, *str);
        str = str + 1;
    }
    if(*str == '\0') return 'N';
    element e;
    int flag = 0;
    str = str + 1;
    while(*str != '\0') {
        if(isEmptyQueue(firstHalf)) return 'R';
        Front(firstHalf, &e);
        Dequeue(&firstHalf);
        if(e != *str) flag = 1;
        str = str + 1;
    }
    if(!isEmptyQueue(firstHalf)) return 'L';
    else if(flag == 1) return 'D';
    return 'S';
}

void main() {
    printf("%c", processString("hello:hello"));
}