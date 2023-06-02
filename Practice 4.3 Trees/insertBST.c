#include <stdio.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

void InOrderR(Btree B) {
    if(B != NULL) {
        InOrderR(B->left);
        printf("%d ", B->data);
        InOrderR(B->right);
    }
}

// Recursive

void insertBST(Btree *B, element e) {
    if(*B == NULL) {
        *B = Construct(e, NULL, NULL);
    }
    else {
        if((*B)->data < e) insertBST(&((*B)->right), e);
        else if((*B)->data > e) insertBST(&((*B)->left), e);
    }
}

// Iterative

void insertBSTIter(Btree *B, element e) {
    Btree *toIter = B;
    while((*toIter) != NULL) {
        if((*toIter)->data < e) toIter = &((*toIter)->right);
        else if((*toIter)->data > e) toIter = &((*toIter)->left);
        else return;
    }
    *toIter = Construct(e, NULL, NULL);
}

void main() {
    Btree B = Construct(8, NULL, NULL);
    insertBSTIter(&B, 6);
    insertBST(&B, 3);
    insertBST(&B, 5);
    insertBSTIter(&B, 4);
    insertBST(&B, 14);
    insertBST(&B, 12);
    insertBST(&B, 10);
    insertBSTIter(&B, 13);
    insertBST(&B, 16);
    insertBST(&B, 15);
    InOrderR(B);
}