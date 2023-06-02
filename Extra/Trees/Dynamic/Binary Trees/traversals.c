#include <stdio.h>
#include "../../../Implementations/Trees/Dynamic/Btree.h"

//Inorder (LDR) Traversal - Recursive

void InOrderR(Btree B) {
    if(B != NULL) {
        InOrderR(B->left);
        printf("%d ", B->data);
        InOrderR(B->right);
    }
}

//Inorder (LDR) Traversal - Iterative

void InOrderI(Btree B) {
    stack s = CreateStack();
    int proceed = 1;
    while(proceed == 1) {
        while(B != NULL) {
            Push(&s, B);
            B = B->left;
        }
        if(!isEmptyStack(s)) {
            Top(s, &B);
            Pop(&s);
            printf("%d ", B->data);
            B = B->right;
        }
        else proceed = 0;
    }
}

//Preorder (DLR) Traversal - Recursive

void PreOrderR(Btree B) {
    if(B != NULL) {
        printf("%d ", B->data);
        PreOrderR(B->left);
        PreOrderR(B->right);
    }
}

//Preorder (DLR) Traversal - Iterative

void PreOrderI(Btree B) {
    stack s = CreateStack();
    int proceed = 1;
    while(proceed == 1) {
        while(B != NULL) {
            printf("%d ", B->data);
            Push(&s, B);
            B = B->left;
        }
        if(!isEmptyStack(s)) {
            Top(s, &B);
            Pop(&s);
            B = B->right;
        }
        else proceed = 0;
    }
}

//Postorder (LRD) Traversal - Recursive

void PostOrderR(Btree B) {
    if(B != NULL) {
        PostOrderR(B->left);
        PostOrderR(B->right);
        printf("%d ", B->data);
    }
}

//Postorder (LRD) Traversal - Iterative

void PostOrderI(Btree B) {
    stack s = CreateStack();
    int proceed = 1;
    Btree previous = NULL;
    while(proceed == 1) {
        while(B != NULL) {
            Push(&s, B);
            B = B->left;
        }
        if(!isEmptyStack(s)) {
            Top(s, &B);
            if(B->right == NULL || B->right == previous) {
                printf("%d ", B->data);
                previous = B;
                B = NULL;
                Pop(&s);
            }
            else B = B->right;
        }
        else proceed = 0;
    }
}

//Level Order Traversal

void LevelOrder(Btree B) {
    if(B == NULL) return;
    queue q = CreateQueue();
    Btree frontBtree;
    EnQueue(&q, B);
    while(Front(q, &frontBtree)) {
        DeQueue(&q);
        printf("%d ", frontBtree->data);
        if(frontBtree->left != NULL) EnQueue(&q, frontBtree->left);
        if(frontBtree->right != NULL) EnQueue(&q, frontBtree->right);
    }
}

void main() {
    Btree Lleft = Construct(4, NULL, NULL);
    Btree Rleft = Construct(5, NULL, NULL);
    Btree Bleft = Construct(2, Lleft, Rleft);
    Btree Lright = Construct(6, NULL, NULL);
    Btree Rright = Construct(7, NULL, NULL);
    Btree Bright = Construct(3, Lright, Rright);
    Btree B = Construct(1, Bleft, Bright);
    LevelOrder(B);
}