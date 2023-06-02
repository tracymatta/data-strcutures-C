#include <stdio.h>
#include "../Implementations/Trees/Static/SBtree.h"

int min(int a, int b) {
    if(a > b) return b;
    return a;
}

int min_rec(Btree B, int rootIndex) {
    if(B.data[rootIndex].leftSubtree == -1) return -1;
    else if(B.data[rootIndex].leftSubtree == 0 && B.data[rootIndex].rightSubtree == 0) return B.data[rootIndex].root;
    else if(B.data[rootIndex].leftSubtree == 0) return min(B.data[rootIndex].root, min_rec(B, B.data[rootIndex].rightSubtree));
    else if(B.data[rootIndex].rightSubtree == 0) return min(B.data[rootIndex].root, min_rec(B, B.data[rootIndex].leftSubtree));
    return min(B.data[rootIndex].root, min(min_rec(B, B.data[rootIndex].leftSubtree), min_rec(B, B.data[rootIndex].rightSubtree)));
}

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int max_rec(Btree B, int rootIndex) {
    if(B.data[rootIndex].leftSubtree == -1) return -1;
    else if(B.data[rootIndex].leftSubtree == 0 && B.data[rootIndex].rightSubtree == 0) return B.data[rootIndex].root;
    else if(B.data[rootIndex].leftSubtree == 0) return max(B.data[rootIndex].root, max_rec(B, B.data[rootIndex].rightSubtree));
    else if(B.data[rootIndex].rightSubtree == 0) return max(B.data[rootIndex].root, max_rec(B, B.data[rootIndex].leftSubtree));
    return max(B.data[rootIndex].root, max(max_rec(B, B.data[rootIndex].leftSubtree), max_rec(B, B.data[rootIndex].rightSubtree)));
}

int isBSTHelper(Btree B, int rootIndex) {
    if(B.data[rootIndex].leftSubtree == 0 && B.data[rootIndex].rightSubtree == 0) return 1;
    else if(B.data[rootIndex].leftSubtree == 0) return B.data[rootIndex].root < min_rec(B, B.data[rootIndex].rightSubtree) 
                                                       && isBSTHelper(B, B.data[rootIndex].rightSubtree);
    else if(B.data[rootIndex].rightSubtree == 0) return B.data[rootIndex].root > max_rec(B, B.data[rootIndex].leftSubtree) 
                                                        && isBSTHelper(B, B.data[rootIndex].leftSubtree);
    return B.data[rootIndex].root > max_rec(B, B.data[rootIndex].leftSubtree) 
           && B.data[rootIndex].root < min_rec(B, B.data[rootIndex].rightSubtree) 
           && isBSTHelper(B, B.data[rootIndex].rightSubtree) 
           && isBSTHelper(B, B.data[rootIndex].leftSubtree);
}

int isBST(Btree B) {
    if(B.data[B.rootIndex].leftSubtree == -1) return -1;
    return isBSTHelper(B, B.rootIndex);
}

void main() {
    Btree B;
    CreateBTree(&B);
    B.data[1].root = 4;
    B.data[1].leftSubtree = 0;
    B.data[1].rightSubtree = 0;
    addLeftChild(&B, 1, 2);
    addRightChild(&B, 1, 6);
    addLeftChild(&B, 2, 1);
    addRightChild(&B, 2, 3);
    addLeftChild(&B, 6, 5);
    addRightChild(&B, 6, 7);
    printf("%d", isBST(B));
}