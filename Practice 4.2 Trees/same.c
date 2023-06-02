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

// Version 1 using belongs function

int belongr(Btree B, element e)
{
    if(B == NULL) return 0;
    if(B->data == e) return 1;
    if(e < B->data) return belongr(B->left, e);
    return belongr(B->right, e);
}

int belong(Btree A, Btree B)
{
	// recursive function: checking whether left and right subtrees of A belongs to B, check A root too
    if(A == NULL) return 1;
    return belongr(B, A->data) && belong(A->left, B) && belong(A->right, B); 
    
}

int same(Btree A, Btree B)
{
	// call belong function twice: A belongs to B and B belongs to A
    if(belong(A, B) == 0) return 0;
    if(belong(B, A) == 0) return 0;
    return 1;
}

// Version 2 using inorder traversal result comparison

void InOrderR(Btree B, stack *s) {
    if(B != NULL) {
        InOrderR(B->left, s);
        Push(s, B);
        InOrderR(B->right, s);
    }
}

int sameIter(Btree B1, Btree B2) {
    stack s1 = CreateStack();
    stack s2 = CreateStack();
    InOrderR(B1, &s1);
    InOrderR(B2, &s2);
    Btree first, second;
    while(Top(s1, &first) && Top(s2, &second)) {
        if(first->data != second->data) return 0;
        Pop(&s1);
        Pop(&s2);
    }
    if(!isEmptyStack(s1) || !isEmptyStack(s2)) return 0;
    return 1;
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
    Btree C = Construct(8, NULL, NULL);
    insertBST(&C, 6);
    insertBST(&C, 3);
    insertBST(&C, 5);
    insertBST(&C, 4);
    insertBST(&C, 14);
    insertBST(&C, 12);
    insertBST(&C, 10);
    insertBST(&C, 13);
    insertBST(&C, 16);
    insertBST(&C, 15);
    printf("%d\n", sameIter(B, C));
}