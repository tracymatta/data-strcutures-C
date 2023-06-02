#include <stdio.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

//Level Order Traversal

void levelOrder(Btree B) {
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
    levelOrder(B);
}