#include <stdio.h>
#include <stdlib.h>

typedef struct interval {
    int lowerBound;
    int upperBound;
} interval;

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    interval bound;
    node *LL;
} element;

typedef struct Btree {
    element data;
    struct Btree *left, *right;
} *Btree;

Btree Construct(element e, Btree L, Btree R) {
    Btree B = (Btree)malloc(sizeof(struct Btree));
    B->data = e;
    B->left = L;
    B->right = R;
    return B;
}

Btree searchLL(Btree B, int v) {
    if(B == NULL) return NULL;
    node *toIter = B->data.LL;
    while(toIter != NULL) {
        if(toIter->data == v) return B;
        toIter = toIter->next;
    }
    return NULL;
}

Btree search(Btree B, int v) {
    while(B != NULL) {
        if(B->data.bound.lowerBound <= v && B->data.bound.upperBound >= v) return searchLL(B, v);
        if(v < B->data.bound.lowerBound) B = B->left;
        else B = B->right;
    }
    return NULL;
}

void printLL(node *toPrint) {
    if(toPrint == NULL) printf("\n");
    else {
        printf("%d ", toPrint->data);
        printLL(toPrint->next);
    }
}

void inorderBtree(Btree B) {
    if(B == NULL) return;
    inorderBtree(B->left);
    printf("in interval [%d, %d] we have: ", B->data.bound.lowerBound, B->data.bound.upperBound);
    printLL(B->data.LL);
    inorderBtree(B->right);
}

void insertLL(node **headref, int v) {
    if((*headref) == NULL) {
        (*headref) = (node*)malloc(sizeof(node));
        (*headref)->data = v;
        (*headref)->next = NULL;
    }
    else insertLL(&((*headref)->next), v);
}

void insert(Btree *B, int v, int lower, int upper) {
    if((*B) == NULL) {
        (*B) = Construct((element){(interval){lower, upper}, NULL}, NULL, NULL);
        insertLL(&((*B)->data.LL), v);
    }
    else if((*B)->data.bound.lowerBound <= v && (*B)->data.bound.upperBound >= v) insertLL(&((*B)->data.LL), v);
    else if(v < (*B)->data.bound.lowerBound) insert(&((*B)->left), v, lower, upper);
    else insert(&((*B)->right), v, lower, upper);
}

void main() {
    Btree B = NULL;
    insert(&B, -2, -10, 10);
    insert(&B, 0, -10, 10);
    insert(&B, 5, -10, 10);
    insert(&B, 2, -10, 10);
    insert(&B, -125, -150, -50);
    insert(&B, -50, -150, -50);
    insert(&B, -65, -150, -50);
    insert(&B, 20, 20, 130);
    insert(&B, 50, 20, 130);
    insert(&B, 65, 20, 130);
    insert(&B, -1250, -1200, -200);
    insert(&B, -340, -1200, -200);
    insert(&B, -459, -1200, -200);
    insert(&B, -20, -23, -11);
    insert(&B, -16, -23, -11);
    insert(&B, 250, 200, 1000);
    insert(&B, 500, 200, 1000);
    insert(&B, 654, 200, 1000);
    inorderBtree(B);
}