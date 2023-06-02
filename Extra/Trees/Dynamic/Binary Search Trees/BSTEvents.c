#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct interval {
    int start, end;
} interval;

typedef struct {
    char *title, *location;
    interval period;
} Event;

typedef struct Btree {
    Event data;
    struct Btree *left, *right;
} *Btree;

typedef struct {
    Btree data[N];
    int top;
} stack; 

typedef struct {
    Btree data[N];
    int front, rear;
} queue;

Btree CreateBtree() {
    return NULL;
}

int isEmptyBtree(Btree B) {
    return B == NULL;
}

Btree Construct(Event e, Btree L, Btree R) {
    Btree created = (Btree)malloc(sizeof(Btree));
    if(!created) return 0;
    created->data = e;
    created->left = L;
    created->right = R;
    return created;
}

int Root(Btree B, Event *e) {
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
        printf("%d ", e->data);
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
        printf("%d ", e->data);
        DeQueue(&q);
    }
    printf("\n");
}

void insertBST(Btree *B, Event e) {
    if(*B == NULL) {
        *B = Construct(e, NULL, NULL);
        return;
    }
    else if((*B)->data.period.start >= e.period.start)  return insertBST(&((*B)->left), e);
    return insertBST(&((*B)->right), e);
}

int contains(Btree B, int year) {
    if(B == NULL) return 0;
    if(year < B->data.period.start) return contains(B->right, year);
    else if(year >= B->data.period.start && year <= B->data.period.end) return 1 + contains(B->left, year) + contains(B->right, year);
    return contains(B->left, year) + contains(B->right, year);
}

interval minInterval(Btree B) {
    stack s = CreateStack();
    interval i = {0, 0};
    while(1) {
        while(B != NULL) {
            Push(&s, B);
            B = B->left;
        }
        if(!isEmptyStack(s)) {
            Top(s, &B);
            if(i.start == 0) i.start = B->data.period.start;
            if(i.end < B->data.period.end) i.end = B->data.period.end;
            Pop(&s);
            B = B->right;
        }
        else break;
    }
    return i;
}

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int maxBST(Btree B) {
    if(B == NULL) return 0;
    return max(B->data.period.start, 
           max(maxBST(B->left), maxBST(B->right)));
}

int minBST(Btree B) {
    if(B == NULL) return 5000;
    return min(B->data.period.start, 
           min(minBST(B->left), minBST(B->right)));
}

int isBtreeE(Btree B) {
    if(B == NULL) return 1;
    return B->data.period.start <= B->data.period.end 
        && B->data.period.start >= maxBST(B->left)
        && B->data.period.start < minBST(B->right)
        && isBtreeE(B->left) 
        && isBtreeE(B->right);
}

int same(Event E, Event F) {
    if(strcmp(E.location, F.location) == 0 
    && strcmp(E.title, F.title) == 0 
    && E.period.start == F.period.start
    && E.period.end == F.period.end) return 1;
    return 0;
}

int longestInterval(Btree B, Event E) {
    stack s = CreateStack();
    int i = 0;
    int j;
    while(1) {
        while(B != NULL) {
            Push(&s, B);
            B = B->left;
        }
        if(!isEmptyStack(s)) {
            Top(s, &B);
            if(E.period.start > B->data.period.end || E.period.end < B->data.period.start) j = 0;
            else j = min(E.period.end, B->data.period.end) - max(E.period.start, B->data.period.start);
            if(j > i && same(E, B->data) == 0) i = j;
            Pop(&s);
            B = B->right;
        }
        else break;
    }
    return i;
}

int maxLong(Btree S) {
    stack s = CreateStack();
    int i = 0;
    int j;
    Btree B = S;
    while(1) {
        while(B != NULL) {
            Push(&s, B);
            B = B->left;
        }
        if(!isEmptyStack(s)) {
            Top(s, &B);
            j = longestInterval(S, B->data);
            if(j > i) i = j;
            Pop(&s);
            B = B->right;
        }
        else break;
    }
    return i;
}

void main() {
    Btree B = Construct((Event){"T1", "L1", (interval){1939, 1945}}, NULL, NULL);
    insertBST(&B, (Event){"T2", "L2", (interval){1870, 1954}});
    insertBST(&B, (Event){"T3", "L3", (interval){1943, 1943}});
    insertBST(&B, (Event){"T4", "L4", (interval){1210, 1255}});
    insertBST(&B, (Event){"T5", "L5", (interval){1930, 1985}});
    insertBST(&B, (Event){"T6", "L6", (interval){1965, 1970}});
    insertBST(&B, (Event){"T7", "L7", (interval){1930, 1931}});
    printf("contains year 1943: %d\n", contains(B, 1943));
    interval i = minInterval(B);
    printf("minimum interval: [%d, %d]\n", i.start, i.end);
    printf("isBtree? %d\n", isBtreeE(B));
    printf("longest interval: %d\n", longestInterval(B, (Event){"T8", "L8", (interval){1923, 1960}}));
    printf("max interval: %d\n", maxLong(B));
}