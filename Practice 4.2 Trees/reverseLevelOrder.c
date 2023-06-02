#include <stdio.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

void reverseLevelOrder(Btree B) {
    if(B == NULL) return;
    queue q = CreateQueue();
    stack res = CreateStack();
    Btree frontBtree, e;
    EnQueue(&q, B);
    Push(&res, B);
    while(Front(q, &frontBtree)) {
        DeQueue(&q);
        if(frontBtree->right != NULL) {
            EnQueue(&q, frontBtree->right);
            Push(&res, frontBtree->right);
        }
        if(frontBtree->left != NULL) {
            EnQueue(&q, frontBtree->left);
            Push(&res, frontBtree->left);
        }
    }
    while(Top(res, &e)) {
        printf("%d ", e->data);
        Pop(&res);
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
    reverseLevelOrder(B);
}