#include <stdio.h>
#include "CalkinWilfTree.h"

int LevelOrderCheck(Btree B) {
    if(B == NULL) return 0;
    if(B->data.num != 1 || B->data.denum != 1) return 0;
    queue q = CreateQueue();
    Btree frontBtree;
    EnQueue(&q, B);
    while(Front(q, &frontBtree)) {
        DeQueue(&q);
        if(frontBtree->left != NULL) {
            EnQueue(&q, frontBtree->left);
            EnQueue(&q, frontBtree->right);
            if(frontBtree->left->data.denum != frontBtree->right->data.num) return 0;
        }
    }
    if(frontBtree->data.denum != 1) return 0;
    return 1;
}

void main () {
    Btree CalkinWilfTree = CreateCalkinWilfTree(4);
    printf("%d\n", LevelOrderCheck(CalkinWilfTree));
}