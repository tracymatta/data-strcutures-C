#include <stdio.h>
#include <string.h>

#define N 10

typedef struct {
    int id;
    char *color;
} element;

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
        printf("%d,%s  ", e.id, e.color);
        Dequeue(&q);
    }
    printf("\n");
}

void sort(queue *q) {
    queue blue = CreateQueue();
    queue white = CreateQueue();
    queue red = CreateQueue();
    element e;
    while(!isEmptyQueue(*q)) {
        Front(*q, &e);
        if(strcmp(e.color, "blue") == 0) EnQueue(&blue, e);
        else if(strcmp(e.color, "white") == 0) EnQueue(&white, e);
        else if(strcmp(e.color, "red") == 0) EnQueue(&red, e);
        Dequeue(q);
    }
    while(!isEmptyQueue(blue)) {
        Front(blue, &e);
        EnQueue(q, e);
        Dequeue(&blue);
    }
    while(!isEmptyQueue(white)) {
        Front(white, &e);
        EnQueue(q, e);
        Dequeue(&white);
    }
    while(!isEmptyQueue(red)) {
        Front(red, &e);
        EnQueue(q, e);
        Dequeue(&red);
    }

}

void main() {
    queue q = CreateQueue();
    EnQueue(&q, (element){3, "red"});
    EnQueue(&q, (element){5, "blue"});
    EnQueue(&q, (element){2, "red"});
    EnQueue(&q, (element){6, "white"});
    EnQueue(&q, (element){11, "white"});
    EnQueue(&q, (element){9, "blue"});
    EnQueue(&q, (element){1, "white"});
    EnQueue(&q, (element){4, "red"});
    printQueue(q);
    sort(&q);
    printQueue(q);
}