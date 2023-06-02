#include <stdio.h>
#define N 20

typedef int element;

typedef struct {
    element root;
    int leftSubtree, rightSubtree;
} node;

typedef struct {
    node data[N];
    int rootIndex;
} Btree;

typedef struct {
    Btree tree;
    int level;
    int root;
} elementQ;

typedef struct {
    elementQ data[N];
    int front, rear;
} queue;

void CreateBTree(Btree *B) {   
    B->rootIndex = 1;
    for(int i = 0; i < N; i++) B->data[i].leftSubtree = -1;
}

int addLeftChild(Btree *B, element parent, element leftChild) {
    int i;
    for(i = 0; i < N && (B->data[i].root != parent || B->data[i].leftSubtree == -1); i++);
    if(i == N) return 0; // parent doesn't exist
    if(B->data[i].leftSubtree != 0) return 0; // parent already has a left subtree 
    int j;
    for(j = 0; j < N && (B->data[j].root != leftChild || B->data[j].leftSubtree == -1); j++);
    if(j < N) return 0; // if the child is already in the tree
    for(j = 1; j < N && B->data[j].leftSubtree != -1; j++);
    if (j == N) return 0;
    B->data[j].root = leftChild;
    B->data[j].rightSubtree = 0;
    B->data[j].leftSubtree = 0;
    B->data[i].leftSubtree = j;
    return 1;
}

int addRightChild(Btree *B, element parent, element rightChild) {
    int i;
    for(i = 0; i < N && (B->data[i].root != parent || B->data[i].leftSubtree == -1); i++);
    if(i == N) return 0; // parent doesn't exist
    if(B->data[i].rightSubtree != 0) return 0; // parent already has a left subtree 
    int j;
    for(j = 0; j < N && (B->data[j].root != rightChild || B->data[j].leftSubtree == -1); j++);
    if(j < N) return 0; // if the child is already in the tree
    for(j = 1; j < N && B->data[j].leftSubtree != -1; j++);
    if (j == N) return 0;
    B->data[j].root = rightChild;
    B->data[j].rightSubtree = 0;
    B->data[j].leftSubtree = 0;
    B->data[i].rightSubtree = j;
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

int EnQueue(queue *q, elementQ e) {
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

int Front(queue q, elementQ *e) {
    if(isEmptyQueue(q)) return 0;
    *e = q.data[q.front];
    return 1;
}

int width(Btree B) {
    if(B.data[B.rootIndex].leftSubtree == -1) return 0;
    queue q = CreateQueue();
    elementQ frontBtree;
    int currentLevel = 1, currentCount = 0, maxWidth = 0;
    int root = B.rootIndex;
    EnQueue(&q, (elementQ){B, 1, root});
    while(Front(q, &frontBtree)) {
        DeQueue(&q);
        if(frontBtree.level == currentLevel) currentCount += 1;
        else {
            if(currentCount > maxWidth) maxWidth = currentCount;
            currentCount = 1;
            currentLevel = frontBtree.level;
        }
        if(frontBtree.tree.data[frontBtree.root].leftSubtree != 0) EnQueue(&q, (elementQ){B, frontBtree.level + 1, frontBtree.tree.data[frontBtree.root].leftSubtree});
        if(frontBtree.tree.data[frontBtree.root].rightSubtree != 0) EnQueue(&q, (elementQ){B, frontBtree.level + 1, frontBtree.tree.data[frontBtree.root].rightSubtree});
    }
    if(currentCount > maxWidth) maxWidth = currentCount;
    return maxWidth;
}

void main() {
    Btree B;
    CreateBTree(&B);
    B.data[1].root = 1;
    B.data[1].leftSubtree = 0;
    B.data[1].rightSubtree = 0;
    addLeftChild(&B, 1, 2);
    addRightChild(&B, 1, 3);
    addLeftChild(&B, 2, 4);
    addRightChild(&B, 2, 5);
    addLeftChild(&B, 3, 6);
    addRightChild(&B, 3, 7);
    printf("%d", width(B));
}