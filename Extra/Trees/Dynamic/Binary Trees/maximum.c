#include <stdio.h>
#include "../../../Implementations/Trees/Dynamic/Btree.h"

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

//Using recursion

int MaxR(Btree B) {
    if(B == NULL) return 0;
    return max(max(MaxR(B->left), MaxR(B->right)), B->data);
}

//Using a stack: Inorder (LDR) Traversal - Iterative

int MaxInOrderI(Btree B) {
    stack s = CreateStack();
    int proceed = 1, max = -1;
    while(proceed == 1) {
        while(B != NULL) {
            Push(&s, B);
            B = B->left;
        }
        if(!isEmptyStack(s)) {
            Top(s, &B);
            Pop(&s);
            if(B->data > max) max = B->data;
            B = B->right;
        }
        else proceed = 0;
    }
    return max;
}

//Using a queue: Level Order Traversal

int MaxLevelOrder(Btree B) {
    int max = -1;
    if(B == NULL) return max;
    queue q = CreateQueue();
    Btree frontBtree;
    EnQueue(&q, B);
    while(Front(q, &frontBtree)) {
        DeQueue(&q);
        if(frontBtree->data > max) max = frontBtree->data;
        if(frontBtree->left != NULL) EnQueue(&q, frontBtree->left);
        if(frontBtree->right != NULL) EnQueue(&q, frontBtree->right);
    }
    return max;
}

void main() {
    Btree Lleft = Construct(4, NULL, NULL);
    Btree Rleft = Construct(5, NULL, NULL);
    Btree Bleft = Construct(2, Lleft, Rleft);
    Btree Lright = Construct(6, NULL, NULL);
    Btree Rright = Construct(7, NULL, NULL);
    Btree Bright = Construct(3, Lright, Rright);
    Btree B = Construct(1, Bleft, Bright);
    printf("%d\n", MaxInOrderI(B));
}