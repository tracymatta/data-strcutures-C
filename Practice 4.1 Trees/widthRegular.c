#include <stdio.h>
#include <stdlib.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

int widthRegular(Btree B)
{
    if(B == NULL) return 0;
    queue q = CreateQueue();
    Btree frontBtree;
    int *level = (int*)malloc(sizeof(int)*20);
    int *toIterateLevel = level + 1;
    int currentLevel = 1, currentCount = 0, maxWidth = 0;
    EnQueue(&q, B);
    *level = 1;
    while(Front(q, &frontBtree)) {
        DeQueue(&q);
        if(*level == currentLevel) currentCount += 1;
        else {
            if(currentCount > maxWidth) maxWidth = currentCount;
            currentCount = 1;
            currentLevel = *level;
        }
        if(frontBtree->left != NULL) {
            *toIterateLevel = *level + 1;
            toIterateLevel += 1;
            EnQueue(&q, frontBtree->left);
        }
        if(frontBtree->right != NULL) {
            *toIterateLevel = *level + 1;
            toIterateLevel += 1;
            EnQueue(&q, frontBtree->right);
        }
        level += 1;
    }
    if(currentCount > maxWidth) maxWidth = currentCount;
    return maxWidth;
}

void main() {
    Btree Lleft = Construct(4, NULL, NULL);
    Btree Rleft = Construct(5, NULL, NULL);
    Btree Bleft = Construct(2, Lleft, Rleft);
    Btree Lright = Construct(6, NULL, NULL);
    Btree Rright = Construct(7, NULL, NULL);
    Btree Bright = Construct(3, Lright, Rright);
    Btree B = Construct(1, Bleft, Bright);
    printBtree(B);
    printf("%d\n", widthRegular(B));
}