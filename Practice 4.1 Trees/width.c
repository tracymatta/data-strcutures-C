#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int element;

typedef struct Btree {
    element data;
    struct Btree *left, *right;
} *Btree;

typedef struct {
    Btree tree;
    int level;
} elementq;

typedef struct {
    elementq data[N];
    int top;
} stack; 

typedef struct {
    elementq data[N];
    int front, rear;
} queue;

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

int Push(stack *p, elementq e) {
    if(isFullStack(*p)) return 0;
    p->data[++p->top] = e;
    return 1;
}

int Pop(stack *p) {
    if(isEmptyStack(*p)) return 0;
    p->top--;
    return 1;
}

int Top(stack p, elementq *e) {
    if(isEmptyStack(p)) return 0;
    *e = p.data[p.top];
    return 1;
}

void printStack(stack p) {
    elementq e;
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

int EnQueue(queue *q, elementq e) {
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

int Front(queue q, elementq *e) {
    if(isEmptyQueue(q)) return 0;
    *e = q.data[q.front];
    return 1;
}

void printQueue(queue q) {
    elementq e;
    while(!isEmptyQueue(q)) {
        Front(q, &e);
        printf("%d ", e);
        DeQueue(&q);
    }
    printf("\n");
}

int width(Btree B) {
    if(B == NULL) return 0;
    queue q = CreateQueue();
    elementq frontBtree;
    int currentLevel = 1, currentCount = 0, maxWidth = 0;
    EnQueue(&q, (elementq){B, 1});
    while(Front(q, &frontBtree)) {
        DeQueue(&q);
        if(frontBtree.level == currentLevel) currentCount += 1;
        else {
            if(currentCount > maxWidth) maxWidth = currentCount;
            currentCount = 1;
            currentLevel = frontBtree.level;
        }
        if((frontBtree.tree)->left != NULL) EnQueue(&q, (elementq){(frontBtree.tree)->left, frontBtree.level + 1});
        if((frontBtree.tree)->right != NULL) EnQueue(&q, (elementq){(frontBtree.tree)->right, frontBtree.level + 1});
    }
    if(currentCount > maxWidth) maxWidth = currentCount;
    return maxWidth;
}

void main() {
    Btree Lleft = Construct(4, NULL, NULL);
    Btree Rleft = Construct(5, NULL, NULL);
    Btree Bleft = Construct(2, Lleft, Rleft);
    Btree Lright = Construct(6, NULL, NULL);
    Btree Rright = Construct(7, NULL, NULL);
    Btree Bright = Construct(3, Lright, Rright);
    Btree B = Construct(1, Bleft, Bright);
    printf("%d\n", width(B));
}