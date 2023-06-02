#include "../Implementations/Trees/Static/SBtree.h"

void CreateBTree(Btree *B) {   
    B->rootIndex = 1;
    for(int i = 0; i < N; i++) B->data[i].leftSubtree = -1;
}

int addLeftChild(Btree *B, element parent, element leftChild) {
    int i;
    for(i = 0; i < N && (B->data[i].leftSubtree == -1 || B->data[i].root != parent); i++);
    if(i == N) return 0; // parent doesn't exist
    if(B->data[i].leftSubtree != 0) return 0; // parent already has a left subtree 
    int j;
    for(j = 0; j < N && (B->data[j].leftSubtree == -1 || B->data[j].root != leftChild); j++);
    if(j < N) return 0; // if the child is already in the tree
    for(j = 1; j < N && B->data[j].leftSubtree != -1; j++);
    if (j == N) return 0;
    B->data[j].root = leftChild;
    B->data[j].rightSubtree = 0;
    B->data[j].leftSubtree = 0;
    B->data[i].leftSubtree = j;
    return 1;
}

int addRightChild(Btree *B, element parent, element rightChild) {
    int i;
    for(i = 0; i < N && (B->data[i].leftSubtree == -1 || B->data[i].root != parent); i++);
    if(i == N) return 0; // parent doesn't exist
    if(B->data[i].rightSubtree != 0) return 0; // parent already has a left subtree 
    int j;
    for(j = 0; j < N && (B->data[j].leftSubtree == -1 || B->data[j].root != rightChild); j++);
    if(j < N) return 0; // if the child is already in the tree
    for(j = 1; j < N && B->data[j].leftSubtree != -1; j++);
    if (j == N) return 0;
    B->data[j].root = rightChild;
    B->data[j].rightSubtree = 0;
    B->data[j].leftSubtree = 0;
    B->data[i].rightSubtree = j;
    return 1;
}