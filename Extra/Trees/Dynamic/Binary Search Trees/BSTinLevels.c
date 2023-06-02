#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct tree {
    element data;
    struct tree *left, *right, *nextLevel;
} *tree;

tree find(tree A, element x) {
    if(A == NULL) return NULL;
    if(A->data == x) return A;
    else if(A->data > x) return find(A->left, x);
    return find(A->right, x);
}

int insert(element x, tree *A, tree *B) {
    if(*A == NULL) {
        *A = (tree)malloc(sizeof(struct tree));
        if(!(*A)) return 0;
        (*A)->data = x;
        (*A)->left = (*A)->right = (*A)->nextLevel = NULL;
        *B = *A;
    }
    else {
        if(x == (*A)->data) return 0;
        else if(x < (*A)->data) return insert(x, &((*A)->left), B);
        return insert(x, &((*A)->right), B);
    }
    return 1;
}

void prefix(tree S, element word[], int *length, tree *A) {
    int i = 0;
    tree T;
    *A = NULL;
    while(1) {
        T = find(S, word[i]);
        if(T == NULL) break;
        else {
            i++;
            *A = T;
            S = T->nextLevel;
        }
    }
    *length = i;
}

int findWord(tree S, element word[]) {
    int length;
    tree A;
    prefix(S, word, &length, &A);
    if(length == strlen(word)) return 1;
    return 0;
}

int insertWord(tree *S, element word[]) {
    int length;
    tree A, B, C;
    prefix(*S, word, &length, &A);
    if(length == strlen(word)) return 0;
    for(int i = length; word[i] != '\0'; i++) {
        if(A == NULL) C = *S;
        else C = A->nextLevel;
        if(insert(word[i], &C, &B) == 0) return 0;
        if(*S == NULL) *S = C;
        if(A && A->nextLevel != C) A->nextLevel = C;
        A = B;
    }
    return 1;
}

void printTree(tree S) {
    if(S) {
        printTree(S->left);
        printf("%c ", S->data);
        printTree(S->nextLevel);
        printTree(S->right);
    }
}

void main() {
    tree S = NULL;
    printf("%d\n", insertWord(&S, "mn"));
    printf("%d\n", insertWord(&S, "ke"));
    printf("%d\n", insertWord(&S, "me"));
    printf("%d\n", insertWord(&S, "r"));
    printf("%d\n", insertWord(&S, "uf"));
    printf("%d\n", insertWord(&S, "kn"));
    printf("%d\n", insertWord(&S, "ub"));
    printf("%d\n", insertWord(&S, "mz"));
    printf("%d\n", insertWord(&S, "kd"));
    printf("%d\n", insertWord(&S, "ubc"));
    printf("%d\n", insertWord(&S, "ubz"));
    printf("%d\n", insertWord(&S, "ubb"));
    printTree(S);
}
