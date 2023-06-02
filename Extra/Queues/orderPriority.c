#include <stdio.h>
#include <string.h>

#define N 10

typedef struct {
    int id;
    int priority;
} element;

typedef struct {
    element data[N];
    int top;
} stack; 

typedef struct {
    element data[N];
    int front, rear;
} queue;

stack CreateStack() {
    stack p;
    p.top = -1;
    return p;
}

int isEmptyStack(stack p) {
    return p.top == -1;
}

int isFullStack(stack p) {
    return p.top == N-1;
}

int Push(stack *p, element e) {
    if(isFullStack(*p)) return 0;
    p->data[++p->top] = e;
    return 1;
}

int Pop(stack *p) {
    if(isEmptyStack(*p)) return 0;
    p->top--;
    return 1;
}

int Top(stack p, element *e) {
    if(isEmptyStack(p)) return 0;
    *e = p.data[p.top];
    return 1;
}

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
        printf("%d,%d  ", e.id, e.priority);
        Dequeue(&q);
    }
    printf("\n");
}

void orderPriority(queue *q) {
    stack S[N];
    for(int i = 0; i < N; i++) {
        S[i] = CreateStack();
    }
    element e;
    while(!isEmptyQueue(*q)) {
        Front(*q, &e);
        Push(&S[e.priority], e);
        Dequeue(q);
    }
    for(int i = 0; i < N; i++) {
        while(!isEmptyStack(S[i])) {
            Top(S[i], &e);
            EnQueue(q, e);
            Pop(&S[i]);
        }
    }
}

void main() {
    queue q = CreateQueue();
    EnQueue(&q, (element){1, 5});
    EnQueue(&q, (element){2, 3});
    EnQueue(&q, (element){3, 1});
    EnQueue(&q, (element){4, 3});
    EnQueue(&q, (element){5, 3});
    EnQueue(&q, (element){6, 5});
    EnQueue(&q, (element){7, 2});
    EnQueue(&q, (element){8, 1});
    printQueue(q);
    orderPriority(&q);
    printQueue(q);
}