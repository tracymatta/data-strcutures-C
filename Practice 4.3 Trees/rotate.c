#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

void LevelOrder(Btree B) {
    if(B == NULL) return;
    queue q = CreateQueue();
    EnQueue(&q, B);
    int *levels = (int*) malloc (sizeof(int) * 20);
    int *traverseLevels = levels + 1;
    *levels = 1;
    int currLevel = 1;
    while(Front(q, &B)) {
        int level = *levels;
        DeQueue(&q);
        if(level != currLevel) {
            printf("\n");
            currLevel = level;
        }
        printf("%d ", B->data);
        if(B->left != NULL) {
            *traverseLevels = level + 1;
            traverseLevels += 1;
            EnQueue(&q, B->left);
        }
        if(B->right != NULL) {
            *traverseLevels = level + 1;
            traverseLevels += 1;
            EnQueue(&q, B->right);
        }
        levels += 1;
    }
    
}

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int height(Btree B) {
    if(B == NULL) return 0;
    return 1 + max(height(B->left), height(B->right));
}

int diffLR(Btree B) {
    if(B == NULL) return 0;
    return height(B->left) - height(B->right);
}

int balanced(Btree B) {
    return B == NULL || (abs(diffLR(B)) < 2 && balanced(B->left) && balanced(B->right));
}

void leftRotation(Btree *B) {
    if((*B) == NULL || (*B)->right == NULL) return;
    Btree C = (*B)->right;
    (*B)->right = C->left;
    C->left = (*B);
    (*B) = C;
}

void rightRotation(Btree *B) {
    if((*B) == NULL || (*B)->left == NULL) return;
    Btree C = (*B)->left;
    (*B)->left = C->right;
    C->right = (*B);
    (*B) = C;
}

void leftRightRotation(Btree *B) {
    if(B == NULL || (*B)->left == NULL) return;
    leftRotation(&((*B)->left));
    rightRotation(B);
}

void rightLeftRotation(Btree *B) {
    if(B == NULL || (*B)->right == NULL) return;
    rightRotation(&((*B)->right));
    leftRotation(B);
}

int leftLean(Btree B) {
    return diffLR(B) > 0;
}

int rightLean(Btree B) {
    return diffLR(B) < 0;
}

int insertBST(Btree *B, element e) {
    if(*B == NULL) {
        *B = Construct(e, NULL, NULL);
        return 1;
    }
    else if((*B)->data == e) return 0;
    else if((*B)->data < e) return insertBST(&((*B)->right), e);
    return insertBST(&((*B)->left), e);
}

int insertBalancedBST(Btree *B, element e) {
    if(insertBST(B, e) == 0) return 0;
    if(e < (*B)->data) {
        if(rightLean((*B)->left) == 1) leftRightRotation(B);
        else rightRotation(B);
    }
    else {
        if(leftLean((*B)->right) == 1) rightLeftRotation(B);
        else leftRotation(B);
    }
    return 1;
}

void main() {
    Btree B = NULL;
    insertBalancedBST(&B, 40);
    insertBalancedBST(&B, 15);
    insertBalancedBST(&B, 30);
    insertBalancedBST(&B, 20);
    insertBalancedBST(&B, 10);
    insertBalancedBST(&B, 50);
    LevelOrder(B);
}