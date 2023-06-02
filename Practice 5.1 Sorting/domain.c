#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int element;

typedef struct node {
    element data;
    struct node *left, *right;
} *Heap;

Heap Construct(element data, Heap L, Heap R) {
    Heap h = (Heap) malloc(sizeof(struct node));
    h->data = data;
    h->left = L;
    h->right = R;
    return h;
}

int GetMinimum(Heap h) {
    if(h == NULL) return -1;
    return h->data;
}

void PercolateDown(Heap *h) {
    if((*h) == NULL) return;
    Heap *max = h;
    int temp;
    if((*h)->left != NULL && (*h)->left->data > (*max)->data) max = &((*h)->left);
    if((*h)->right != NULL && (*h)->right->data > (*max)->data) max = &((*h)->right);
    if(max != h) {
        temp = (*h)->data;
        (*h)->data = (*max)->data;
        (*max)->data= temp;
        PercolateDown(max);
    }
}

int nb_levels(int nbNodes) {
    if(nbNodes <=0) return 0;
    int i = floor(log2(nbNodes)) + 1;
    return i;
}

int count(Heap h) {
    if(h == NULL) return 0;
    return 1 + count(h->left) + count(h->right);
}

Heap* find(Heap *h, int levels, int nodes) {
    if((*h)->right == NULL && (*h)->left == NULL) return h;
    int nbNonLeaf = pow(2, levels - 1) - 1;
    int nbLeaf = nodes - nbNonLeaf;
    int hypNbLeaf = pow(2, levels) - 1 - nbNonLeaf;
    if(nbLeaf <= hypNbLeaf / 2) return find(&((*h)->left), levels - 1, pow(2, levels - 2) - 1 + nbLeaf);
    else return find(&((*h)->right), levels - 1, pow(2, levels - 2) - 1 - hypNbLeaf/2 + nbLeaf);
}

int DeleteMax(Heap *h) {
    int data;
    if((*h) == NULL) return -1;
    data = (*h)->data;
    int nodes = count(*h);
    Heap *found = find(h, nb_levels(nodes), nodes);
    if(h != found) (*h)->data = (*found)->data;
    else *h = NULL;
    free(*found);
    (*found) = NULL;
    PercolateDown(h);
    return data;
}

void InsertHelper(Heap *h, element data, int levels, int nodes) {
    if((*h) == NULL) {
        (*h) = Construct(data, NULL, NULL);
        return;
    }
    int nbNonLeaf = pow(2, levels - 1) - 1;
    int nbLeaf = nodes - nbNonLeaf;
    int hypNbLeaf = pow(2, levels) - 1 - nbNonLeaf;
    if(nbLeaf <= hypNbLeaf / 2) {
        InsertHelper(&((*h)->left), data, levels - 1, pow(2, levels - 2) - 1 + nbLeaf);
        if(data < (*h)->data) {
            (*h)->left->data = (*h)->data;
            (*h)->data = data;
        }
    }
    else {
        InsertHelper(&((*h)->right), data, levels - 1, pow(2, levels - 2) - 1 - hypNbLeaf/2 + nbLeaf);
        if(data < (*h)->data) {
            (*h)->right->data = (*h)->data;
            (*h)->data = data;
        }
    }
}

int Insert(Heap *h, int data) {
    int nodes = count(*h) + 1;
    int levels = nb_levels(nodes);
    InsertHelper(h, data, levels, nodes);
}

void BuildHeap(Heap *h, int A[], int n) {
    if(h == NULL) return;
    for(int i = 0; i < n; i++) Insert(h, A[i]);
}

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int belong(Heap h, element e, int *count) {
    if(h == NULL) return 0;
    *count += 1;
    if(h->data == e) return 1;
    else if(h->data > e) return 0;
    return belong(h->left, e, count) || belong(h->right, e, count);
}

int maxHeap(Heap h, element *e) {
    if(h == NULL) return -100;
    *e = max(h->data, max(maxHeap(h->left, e), maxHeap(h->right, e)));
    return *e;
}

int domain(Heap A, Heap B) {
    if(A == NULL || B == NULL) return 0;
    if(A->data < B->data) return 0;
    element e, k;
    maxHeap(A, &e);
    maxHeap(B, &k);
    if(e > k) return 0;
    return 1;
}

void main() {
    int A[5] = {7, 3, 2, 6, 8};
    int B[6] = {9, 4, 1, 6, 7, 3};
    Heap h1 = NULL, h2 = NULL;
    BuildHeap(&h1, A, 5);
    BuildHeap(&h2, B, 6);
    printf("%d", domain(h1, h2));
}