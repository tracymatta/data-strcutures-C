#include <stdio.h>
#include "../Implementations/Trees/Static/SBtree.h"

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int max_rec(Btree B, int rootIndex) {
    if(rootIndex == 0 || B.data[rootIndex].leftSubtree == -1) return -1;
    return max(B.data[rootIndex].root, max(max_rec(B, B.data[rootIndex].leftSubtree), max_rec(B, B.data[rootIndex].rightSubtree)));
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
    printf("%d", max_rec(B, 1));
}