#include <stdio.h>
#include <stdlib.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

void insertBST(Btree *B, element e) {
    if(*B == NULL) {
        *B = Construct(e, NULL, NULL);
    }
    else {
        if((*B)->data < e) insertBST(&((*B)->right), e);
        else if((*B)->data > e) insertBST(&((*B)->left), e);
    }
}

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int min(int a, int b) {
    if(a > b) return b;
    return a;
}

int isBST(Btree B, int *prev) {
    if(B != NULL) {
        if(isBST(B->left, prev) == 0) return 0;
        if(*prev > B->data) return 0;
        else *prev =  B->data;
        if(isBST(B->right, prev) == 0) return 0;
    }
    return 1;
}

void main() {
    Btree B = Construct(8, NULL, NULL);
    stack s = CreateStack();
    int prior = 0;
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
    printf("%d\n", isBST(B, &prior));
}