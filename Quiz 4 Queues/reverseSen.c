#include <stdio.h>
#include <string.h>

#define N 10

typedef char element; 

typedef struct {
    element data[N];
    int front, rear;
} queue;

typedef struct {
    queue data[N];
    int top;
} stack;

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
    while(!isEmptyQueue) {
        Front(q, &e);
        printf("%d ", e);
        Dequeue(&q);
    }
    printf("\n");
}

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

int Push(stack *p, queue e) {
    if(isFullStack(*p)) return 0;
    p->data[++p->top] = e;
    return 1;
}

int Pop(stack *p) {
    if(isEmptyStack(*p)) return 0;
    p->top--;
    return 1;
}

int Top(stack p, queue *e) {
    if(isEmptyStack(p)) return 0;
    *e = p.data[p.top];
    return 1;
}

int reverseOrder(char *str) {
    stack words = CreateStack();
    char *start = str;
    while(*str != '\0') {
        queue word = CreateQueue();
        while(*str != ' ' && *str != '\0') {
            EnQueue(&word, *str);
            if(isFullQueue(word)) return 0;
            str += 1;
        }
        if(!isEmptyQueue(word)) Push(&words, word);
        if(isFullStack(words)) return 0;
        if(*str != '\0') str += 1;
    }
    queue currWord = CreateQueue();
    element currChar;
    while(Top(words, &currWord)) {
        while(Front(currWord, &currChar)) {
            *start = currChar;
            start += 1;
            Dequeue(&currWord);
        }
        Pop(&words);
        if(!isEmptyStack(words)) {
            *start = ' ';
            start += 1;
        }
    }
    *start = '\0';
    return 1;
}

void main() {
    char str[] = "My dog is happy";
    printf("%s\n", str);
    reverseOrder(str);
    printf("%s\n", str);
}