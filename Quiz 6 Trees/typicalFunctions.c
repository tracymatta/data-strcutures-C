#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void preorder(BST B) {
    if(B) {
        printf("%d ", B->data);
        preorder(B->left);
        preorder(B->right);
    }
}

void inorder(BST B) {
    if(B) {
        inorder(B->left);
        printf("%d ", B->data);
        inorder(B->right);
    }
}

void postorder(BST B) {
    if(B) {
        postorder(B->left);
        postorder(B->right);
        printf("%d ", B->data);
    }
}

void insert(BST *B, element e) {
    if((*B) == NULL) {
        (*B) = Construct(e, NULL, NULL);
        return;
    }
    if(e <= (*B)->data) insert(&((*B)->left), e);
    else insert(&((*B)->right), e);
}

int find(BST B, int e) {
    if(B == NULL) return 0;
    if(B->data == e) return 1;
    else if(e < B->data) return find(B->left, e);
    return find(B->right, e);
}

void deleteRoot(BST *B) {
    if((*B) == NULL) return;
    BST C;
    if((*B)->right == NULL && (*B)->left == NULL) {
        C = (*B);
        *B = NULL;
        free(C);
    }
    else if((*B)->left == NULL) {
        C = (*B);
        *B = (*B)->right;
        free(C);
    }
    else if((*B)->right == NULL) {
        C = (*B);
        *B = (*B)->left;
        free(C);
    }
    else {
        BST *D;
        D = &((*B)->right);
        while((*D)->left != NULL) {
            D = &((*D)->left);
        }
        (*B)->data = (*D)->data;
        C = (*D);
        *D = (*D)->right;
        free(C);
    }
}

void deleteInCommon(BST A, BST *B) {
    if((*B) == NULL) return;
    while((*B) != NULL && find(A, (*B)->data) == 1) deleteRoot(B);
    if((*B) == NULL) return;
    deleteInCommon(A, &((*B)->left));
    deleteInCommon(A, &((*B)->right));
}

void test() {
    int n;
    scanf("%d", &n);
    int a, e;
    for( ; n > 0; n--) {
        BST A = NULL, B = NULL;
        scanf("%d", &a);
        for( ; a > 0; a--) {
            scanf("%d", &e);
            insert(&A, e);
        }
        scanf("%d", &a);
        for( ; a > 0; a--) {
            scanf("%d", &e);
            insert(&B, e);
        }
        deleteInCommon(A, &B);
        inorder(B);
        printf("\n");
        preorder(B);
        printf("\n");
        postorder(B);
        printf("\n\n");
    }
}

void main() {
    test();
}

/*
test case

3

4 5 8 2 7
6 98 5 4 2 0 7

4 8 3 0 8
3 8 8 8

4 7 3 0 6
3 8 9 8

*/