#include <stdio.h>
#include "../../../Implementations/Trees/Dynamic/Btree.h"

int nbOfLeafNodes(Btree B) {
    if(B == NULL) return 0;
    if(B->left == NULL && B->right == NULL) return 1;
    return nbOfLeafNodes(B->left) + nbOfLeafNodes(B->right);
}

void main() {
    Btree Lleft = Construct(4, NULL, NULL);
    Btree Rleft = Construct(5, NULL, NULL);
    Btree Bleft = Construct(2, Lleft, Rleft);
    Btree Lright = Construct(6, NULL, NULL);
    Btree Rright = Construct(7, NULL, NULL);
    Btree Bright = Construct(3, Lright, Rright);
    Btree B = Construct(1, Bleft, Bright);
    printf("%d\n", nbOfLeafNodes(B));
}