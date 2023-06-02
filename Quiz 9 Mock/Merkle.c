#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

typedef char element;

typedef struct node {
    element data;
    int hash;
    struct node *left, *right;
} node;

typedef node* Btree;

typedef struct {
    Btree B;
    int nbNodes;
    int nbLevels;
} Merkle;

typedef struct {
    Btree data[N];
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

int hf(element e) {
    return e - 65;
}

int nb_levels(int nbNodes) {
    if(nbNodes <=0) return 0;
    int i = floor(log2(nbNodes)) + 1;
    return i;
}

Btree createNode(element data) {
    Btree newB = (Btree) malloc(sizeof(struct node));
    if(!newB) return NULL;
    newB->left = NULL;
    newB->right = NULL;
    newB->hash = hf(data);
    newB->data = data;
    return newB;
}

void insertComplete(Btree *B, element e) {
    Btree newB = createNode(e);
    if((*B) == NULL) (*B) = newB;
    else {
        queue q = CreateQueue();
        EnQueue(&q, (*B));
        Btree frontBtree;
        while(Front(q, &frontBtree)) {
            DeQueue(&q);
            if(frontBtree->left == NULL) {
                frontBtree->left = newB;
                return;
            }
            else EnQueue(&q, frontBtree->left);
            if(frontBtree->right == NULL) {
                frontBtree->right = newB;
                return;
            }
            else EnQueue(&q, frontBtree->right);
        }
    }
}

Btree createComplete(int height) {
    if(height <= 0) return NULL;
    Btree B = createNode('A');
    B->left = createComplete(height - 1);
    B->right = createComplete(height - 1);
    return B;
}

void updateH(Btree B, int levels, int nodes) {
    if(B->right == NULL && B->left == NULL) return;
    int nbNonLeaf = pow(2, levels - 1) - 1;
    int nbLeaf = nodes - nbNonLeaf;
    int hypNbLeaf = pow(2, levels) - 1 - nbNonLeaf;
    if(nbLeaf <= hypNbLeaf / 2) {
        updateH(B->left, levels - 1, pow(2, levels - 2) - 1 + nbLeaf);
        if(B->right == NULL) B->hash = B->left->hash;
        else B->hash = B->left->hash + B->right->hash;
    }
    else {
        updateH(B->right, levels - 1, pow(2, levels - 2) - 1 - hypNbLeaf/2 + nbLeaf);
        B->hash = B->left->hash + B->right->hash;
    }
    // while updating, B->hash should be hf(B->left->hash + B->right->hash) 
    // but I omitted doing the hashing function for the sake of having a clear output
}

void update(Merkle *M) {
    updateH(M->B, M->nbLevels, M->nbNodes);
}

void insert(Merkle *M, element e) {
    if(M->B == NULL) {
        M->B = createNode(e);
        M->nbLevels = M->nbNodes = 1;
        return;
    }
    else if(M->nbNodes + 1 <= pow(2, M->nbLevels) - 1) {
        insertComplete(&(M->B), e);
        M->nbNodes += 1;
    }
    else {
        Btree empty = createComplete(M->nbLevels - 1);
        insertComplete(&empty, e);
        Btree head = createNode('A');
        head->left = M->B;
        head->right = empty;
        M->B = head;
        M->nbNodes += pow(2, M->nbLevels - 1) + 1;
        M->nbLevels += 1;
    }
    update(M);
}

void print(Btree B) {
    if(B) {
        printf("{data: %c, hash: %d} ", B->data, B->hash);
        print(B->left);
        print(B->right);
    }
}

void main() {
    Merkle M;
    M.B = NULL;
    M.nbLevels = M.nbNodes = 0;
    for(int i = 0; i < 7; i++) {
        insertComplete(&(M.B), i + 'A');
        M.nbNodes += 1;
        if(i == 0 || i == 1 || i == 3) M.nbLevels += 1;
        update(&M);
    }
    insert(&M, 'H');
    print(M.B);
}