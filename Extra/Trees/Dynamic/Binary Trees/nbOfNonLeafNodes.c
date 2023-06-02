#include <stdio.h>
#include "../../../Implementations/Trees/Dynamic/Btree.h"

int nbOfNonLeafNodes(Btree B) {
    if(B == NULL || (B->left == NULL && B->right == NULL)) return 0;
    return 1 + nbOfNonLeafNodes(B->left) + nbOfNonLeafNodes(B->right);
}

void main() {
    Btree Lleft = Construct(4, NULL, NULL);
    Btree Rleft = Construct(5, NULL, NULL);
    Btree Bleft = Construct(2, Lleft, Rleft);
    Btree Lright = Construct(6, NULL, NULL);
    Btree Rright = Construct(7, NULL, NULL);
    Btree Bright = Construct(3, Lright, Rright);
    Btree B = Construct(1, Bleft, Bright);
    printf("%d\n", nbOfNonLeafNodes(B));
}