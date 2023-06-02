#include <stdio.h>
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

// Version 1 using inorder traversal

void InOrderR(Btree B, stack *s) {
    if(B != NULL) {
        InOrderR(B->left, s);
        Push(s, B);
        InOrderR(B->right, s);
    }
}

int isBSTInorder(Btree B) {
    stack s = CreateStack();
    InOrderR(B, &s);
    Btree frontBtree, prior;
    while(Top(s, &prior)) {
        Pop(&s);
        if(Top(s, &frontBtree) == 0) return 1; 
        if(prior->data < frontBtree->data) return 0;
    }
    return 1;
}

// Version 2 using min and max

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int MaxR(Btree B) {
    if(B == NULL) return 0;
    return max(max(MaxR(B->left), MaxR(B->right)), B->data);
}

int min(int a, int b) {
    if(a > b) return b;
    return a;
}

int MinR(Btree B) {
    if(B == NULL) return 0;
    return min(min(MinR(B->left), MinR(B->right)), B->data);
}

int isBSTMinMax(Btree B) {
    if(B == NULL) return 1;
    return isBSTMinMax(B->left) && (MaxR(B->left) == 0 || (MaxR(B->left) < B->data)) && isBSTMinMax(B->right) && (MinR(B->right) == 0 || (MinR(B->right) > B->data));
}

void main() {
    Btree B = Construct(8, NULL, NULL);
    stack s = CreateStack();
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
    printf("%d\n", isBSTMinMax(B));
}