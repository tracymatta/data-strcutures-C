#include <stdio.h>
#include "C:\Users\HP\Documents\CS2022\Semester 4 2021-2022\I2206 Data Structures (C)\Implementations\Trees\Dynamic\Btree.h"

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

//Iterative minimum and maximum

int minBSTIter(Btree B) {
    while(B) {
        if(B->left == NULL) return B->data;
        B = B->left;
    }
    return -1;
}

int maxBSTIter(Btree B) {
    while(B) {
        if(B->right == NULL) return B->data;
        B = B->right;
    }
    return -1;
}

//Recursive minimum and maximum

int minBSTRec(Btree B) {
    if(B == NULL) return -1;
    if(B->left == NULL) return B->data;
    return minBSTRec(B->left);
}

int maxBSTRec(Btree B) {
    if(B == NULL) return -1;
    if(B->right == NULL) return B->data;
    return maxBSTRec(B->right);
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
    printf("\nIterative: ");
    printf("min %d, ", minBSTIter(B));
    printf("max %d\n", maxBSTIter(B));
    printf("Recursive: ");
    printf("min %d, ", minBSTRec(B));
    printf("min %d\n", maxBSTRec(B));
}