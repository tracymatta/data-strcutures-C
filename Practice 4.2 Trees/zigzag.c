#include <stdio.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

void zigZag(Btree B) {
    stack odd = CreateStack(), even = CreateStack();
    int count = 2;
    Push(&odd, B);
    Btree frontBtree;
    while(1) {
        if(isEmptyStack(odd) && isEmptyStack(even)) break;
        if(count % 2 == 1) {
            while(Top(odd, &frontBtree)) {
                Pop(&odd);
                printf("%d ", frontBtree->data);
                if(frontBtree->left != NULL) Push(&even, frontBtree->left);
                if(frontBtree->right != NULL) Push(&even, frontBtree->right);
            }
        }
        else {
            while(Top(even, &frontBtree)) {
                Pop(&even);
                printf("%d ", frontBtree->data);
                if(frontBtree->right != NULL) Push(&odd, frontBtree->right);
                if(frontBtree->left != NULL) Push(&odd, frontBtree->left);
            }
        }
        count += 1;
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
    zigZag(B);
}