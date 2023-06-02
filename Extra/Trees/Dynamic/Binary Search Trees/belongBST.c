#include <stdio.h>
#include "../../../Implementations/Trees/Dynamic/Btree.h"

void InOrderR(Btree B) {
    if(B != NULL) {
        InOrderR(B->left);
        printf("%d ", B->data);
        InOrderR(B->right);
    }
}

void insertBST(Btree *B, element e) {
    if(*B == NULL) {
        *B = Construct(e, NULL, NULL);
    }
    else {
        if((*B)->data < e) insertBST(&((*B)->right), e);
        else if((*B)->data > e) insertBST(&((*B)->left), e);
    }
}

Btree belongIter(Btree B, int e) {
    while(B) {
        if(B->data == e) return B;
        else if(e < B->data) B = B->left;
        else B = B->right;
    }
    return NULL;
}

Btree belongRec(Btree B, int e) {
    if(B == NULL) return NULL;
    if(B->data == e) return B;
    else if(e < B->data) return belongRec(B->left, e);
    return belongRec(B->right, e);
}

void main() {
    Btree B = Construct(8, NULL, NULL);
    insertBST(&B, 6);
    insertBST(&B, 3);
    insertBST(&B, 5);
    insertBST(&B, 4);
    insertBST(&B, 14);
    insertBST(&B, 12);
    insertBST(&B, 10);
    insertBST(&B, 13);
    insertBST(&B, 16);
    insertBST(&B, 15);
    InOrderR(B);
    printf("\n");
    if(belongIter(B, 6)) printf("6 belongs to B\n");
    else printf("6 does not belong to B\n");
    if(belongIter(B, 20)) printf("6 belongs to B\n");
    else printf("20 does not belong to B\n");
}