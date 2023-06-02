#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* element;

typedef struct Btree {
    element data;
    struct Btree *left, *right;
} *Btree;

typedef struct node {
    int data;
    Btree tree;
    struct node *next;
} node;

Btree Construct(element e, Btree L, Btree R) {
    Btree created = (Btree)malloc(sizeof(Btree));
    if(!created) return 0;
    created->data = e;
    created->left = L;
    created->right = R;
    return created;
}

void insertBST(Btree *B, element e) {
    if(*B == NULL) *B = Construct(e, NULL, NULL);
    else if(strcmp((*B)->data, e) < 0) insertBST(&((*B)->right), e);
    else if(strcmp((*B)->data, e) > 0) insertBST(&((*B)->left), e);
    else return;
}

void insertFBST(node **forest, element data) {
    while((*forest) != NULL && (*forest)->data < strlen(data)) forest = &((*forest)->next);
    if((*forest) == NULL || (*forest)->data != strlen(data)) {
        node *keepTrack = (node*)malloc(sizeof(node));
        keepTrack->data = strlen(data);
        keepTrack->tree = NULL;
        keepTrack->next = (*forest);
        (*forest) = keepTrack;
    }
    insertBST(&((*forest)->tree), data);
}

int search(node **forest, element W) {
    while((*forest) != NULL && (*forest)->data < strlen(W)) forest = &((*forest)->next);
    if((*forest) == NULL || (*forest)->data != strlen(W)) {
        insertFBST(forest, W);
        return 0;
    }
    Btree *B = &((*forest)->tree);
    while(B != NULL) {
        if(strcmp((*B)->data, W) == 0) return 1;
        else if(strcmp((*B)->data, W) < 0) B = &((*B)->right);
        else B = &((*B)->left);
    }
    (*B) = Construct(W, NULL, NULL);
    return 0;
}

void printHelper(Btree B, char c) {
    if(B == NULL) return;
    if(B->data[0] == c) printf("%s ", B->data);
    if(B->data[0] <= c) printHelper(B->right, c);
    if(B->data[0] >= c) printHelper(B->left, c);
}

void print(node *forest, char c) {
    if(forest == NULL) return;
    printHelper(forest->tree, c);
    print(forest->next, c);
}

void main() {
    node *forest = NULL;
    insertFBST(&forest, "d");
    insertFBST(&forest, "b");
    insertFBST(&forest, "m");
    insertFBST(&forest, "h");
    insertFBST(&forest, "xde");
    insertFBST(&forest, "mir");
    insertFBST(&forest, "def");
    insertFBST(&forest, "miz");
    insertFBST(&forest, "dfgy");
    insertFBST(&forest, "dfaa");
    insertFBST(&forest, "xxyz");
    insertFBST(&forest, "mirt");
    insertFBST(&forest, "ghte");
    print(forest, 'd');
    insertFBST(&forest, "be");
    insertFBST(&forest, "behave");
    insertFBST(&forest, "been");
    print(forest, 'b');

}