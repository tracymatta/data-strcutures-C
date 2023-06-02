#include <stdio.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

int countBtree(Btree root) {
    if(root == NULL) return 0;
    return 1 + countBtree(root->left) + countBtree(root->right);
}

int isHeap(Btree root) {
    if(root == NULL) return 0;
    queue q = CreateQueue();
    int count = countBtree(root), counter = 1;
    EnQueue(&q, root);
    while(Front(q, &root)) {
        DeQueue(&q);
        if(root->left) {
            if(root->left->data > root->data) return 0;
            counter += 1;
            EnQueue(&q, root->left);
        }
        else if(counter != count) return 0;
        if(root->right) {
            if(root->right->data > root->data) return 0;
            counter += 1;
            EnQueue(&q, root->right);
        }
        else if(counter != count) return 0;
    }
    return 1;
}

void main() {
    Btree Lleft = Construct(3, NULL, NULL);
    Btree Rleft = Construct(2, NULL, NULL);
    Btree Bleft = Construct(4, Lleft, Rleft);
    Btree Lright = Construct(1, NULL, NULL);
    Btree Bright = Construct(5, Lright, NULL);
    Btree B = Construct(6, Bleft, Bright);
    printf("%d ", isHeap(B));
}