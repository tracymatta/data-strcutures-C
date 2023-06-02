#include <stdio.h>
#include "../Implementations/Trees/Static/SBtree.h"

int completeHelper(Btree B, int rootIndex) {
    if(B.data[rootIndex].leftSubtree == 0 && B.data[rootIndex].rightSubtree == 0) return 1;
    else if(B.data[rootIndex].leftSubtree == 0 || B.data[rootIndex].rightSubtree == 0) return 0;
    return completeHelper(B, B.data[rootIndex].leftSubtree) && completeHelper(B, B.data[rootIndex].rightSubtree);
}

int Complete(Btree B) {
    if(B.data[B.rootIndex].leftSubtree == -1) return -1;
    return completeHelper(B, B.rootIndex);
}

void main() {
    Btree B;
    CreateBTree(&B);
    B.data[1].root = 1;
    B.data[1].leftSubtree = 0;
    B.data[1].rightSubtree = 0;
    addLeftChild(&B, 1, 2);
    addRightChild(&B, 1, 3);
    addLeftChild(&B, 2, 4);
    addRightChild(&B, 2, 5);
    addLeftChild(&B, 3, 6);
    addRightChild(&B, 3, 7);
    printf("%d", Complete(B));
}