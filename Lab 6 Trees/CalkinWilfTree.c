#include <stdio.h>
#include <stdlib.h>
#include "CalkinWilfTree.h"

Btree CreateBtree() {
    return NULL;
}

int isEmptyBtree(Btree B) {
    return B == NULL;
}

Btree Construct(element e, Btree L, Btree R) {
    Btree created = (Btree)malloc(sizeof(Btree));
    if(!created) return 0;
    created->data = e;
    created->left = L;
    created->right = R;
    return created;
}

int Root(Btree B, element *e) {
    if(isEmptyBtree(B)) return 0;
    *e = B->data;
    return 1;
}

int Right(Btree B, Btree *R) {
    if(isEmptyBtree(B)) return 0;
    *R = B->right;
    return 1;
}

int Left(Btree B, Btree *L) {
    if(isEmptyBtree(B)) return 0;
    *L = B->left;
    return 1;
}

void CreateCalkinWilfTreeHelper(Btree *B, int num, int denum, int height) {
    if(height <= 0) return;
    (*B) = Construct((element) {num, denum}, NULL, NULL);
    CreateCalkinWilfTreeHelper(&((*B)->left), num, num + denum, height - 1);
    CreateCalkinWilfTreeHelper(&((*B)->right), num + denum, denum, height - 1);
}

Btree CreateCalkinWilfTree(int height) {
    Btree B = NULL;
    CreateCalkinWilfTreeHelper(&B, 1, 1, height);
    return B;
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

int Push(stack *p, Btree e) {
    if(isFullStack(*p)) return 0;
    p->data[++p->top] = e;
    return 1;
}

int Pop(stack *p) {
    if(isEmptyStack(*p)) return 0;
    p->top--;
    return 1;
}

int Top(stack p, Btree *e) {
    if(isEmptyStack(p)) return 0;
    *e = p.data[p.top];
    return 1;
}

void printStack(stack p) {
    Btree e;
    while(!isEmptyStack(p)) {
        Top(p, &e);
        printf("%d ", e);
        Pop(&p);
    }
    printf("\n");
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

int EnQueue(queue *q, Btree e) {
    if(isFullQueue(*q)) return 0;
    q->rear = (q->rear + 1) % N;
    q->data[q->rear] = e;
    return 1; 
}

int DeQueue(queue *q) {
    if(isEmptyQueue(*q)) return 0;
    q->front = (q->front + 1) % N;
    return 1;
}

int Front(queue q, Btree *e) {
    if(isEmptyQueue(q)) return 0;
    *e = q.data[q.front];
    return 1;
}

void printQueue(queue q) {
    Btree e;
    while(!isEmptyQueue(q)) {
        Front(q, &e);
        printf("%d ", e);
        DeQueue(&q);
    }
    printf("\n");
}