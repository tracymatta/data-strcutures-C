#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"

typedef Btree Pagoda;

Pagoda merge(Pagoda L, Pagoda R) {
    Pagoda F = NULL, Lrightmost, Rleftmost, parentL, parentR;
    if(L == NULL && R == NULL) F = NULL;
    else if(L == NULL) F = R;
    else if(R == NULL) F = L;
    else {
        while(L != NULL || R != NULL) {
            if(L != NULL) Lrightmost = L->right;
            if(R != NULL) Rleftmost = R->left;
            if(R == NULL || (L != NULL && Lrightmost->data < Rleftmost->data)) {
                parentL = Lrightmost->right;
                if(F != NULL) Lrightmost->right = F->right;
                else Lrightmost->right = Lrightmost;
                if(F != NULL) F->right = Lrightmost;
                F = Lrightmost;
                if(L != Lrightmost) L->right = parentL;
                else L = NULL;
            }
            else {
                parentR = Rleftmost->left;
                if(F != NULL) Rleftmost->left = F->left;
                else Rleftmost->left = Rleftmost;
                if(F != NULL) F->left = Rleftmost;
                F = Rleftmost;
                if(R != Rleftmost) R->left = parentR;
                else R = NULL;
            }
        }
    }
    return F;
}

int insert(Pagoda *P, element e) {
    Pagoda created = (Pagoda)malloc(sizeof(Pagoda));
    if(!created) return 0;
    created->data = e;
    created->left = created;
    created->right = created;
    (*P) = merge(*P, created);
    return 1;
}

void deleteRoot(Pagoda *P) {
    if((*P) == NULL) return;
    if((*P)->left == (*P) && (*P)->right == (*P)) {
        free((*P));
        (*P) = NULL;
        return;
    }
    Pagoda left = (*P)->left, right = (*P)->right;
    while(left->left != (*P)) left = left->left;
    while(right->right != (*P)) right = right->right;
    if(left == (*P)) left = NULL;
    else left->left = (*P)->left;
    if(right == (*P)) right = NULL;
    else right ->right = (*P)->right;
    free((*P));
    (*P) = merge(left, right);
}

void heapSort(int *A, int size) {
    Pagoda P = NULL;
    for(int i = 0; i < size; i++) {
        insert(&P, A[i]);
    }
    for(int i = size - 1; i >= 0; i--) {
        A[i] = P->data;
        deleteRoot(&P);
    }
}

void main() {
    int A[10] = {5, 8, 29, 45, 12, 50};
    int size = 6;
    for(int i = 0; i < size; i++) printf("%d ", A[i]);
    printf("\n");
    heapSort(A, size);
    for(int i = 0; i < size; i++) printf("%d ", A[i]);
    printf("\n");
}