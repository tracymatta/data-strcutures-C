#include <stdio.h>
#include <stdlib.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

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

//Iterative

Btree* find(Btree *B, element e) {
    if((*B) == NULL) return NULL;
    if(e == (*B)->data) return B;
    else if(e < (*B)->data) return find(&((*B)->left), e);
    return find(&((*B)->right), e);
}

int deleteRoot(Btree *B) {
    if((*B) == NULL) return 0;
    Btree C;
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
        Btree *D;
        D = &((*B)->left);
        while((*D)->right != NULL) {
            D = &((*D)->right);
        }
        (*B)->data = (*D)->data;
        C = (*D);
        *D = (*D)->left;
        free(C);
    }
    return 1;
}

int deleteIter(Btree *B, element e) {
    Btree *toDelete = find(B, e);
    if(toDelete) return deleteRoot(toDelete);
    return 0;
}

//Recursive

Btree maxBSTRec(Btree B) {
    if(B == NULL) return NULL;
    if(B->right == NULL) return B;
    return maxBSTRec(B->right);
}

int deleteRec(Btree *B, element e) {
    if((*B) == NULL) return 0;
    if(e == (*B)->data) {
        if((*B)->left != NULL && (*B)->right != NULL) {
            Btree toSwitch = maxBSTRec((*B)->left);
            (*B)->data = toSwitch->data;
            deleteRec(&((*B)->left), toSwitch->data);
        }
        else if((*B)->left == NULL) {
            Btree toFree = *B;
            (*B) = (*B)->right;
            free(toFree);
        }
        else if((*B)->right == NULL) {
            Btree toFree = *B;
            (*B) = (*B)->left;
            free(toFree);
        }
        else {
            free(*B);
            *B = NULL;
        }
        return 1;
    }
    else if(e < (*B)->data) return deleteRec(&((*B)->left), e);
    return deleteRec(&((*B)->right), e);
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
    deleteRec(&B, 6);
    InOrderR(B);
}