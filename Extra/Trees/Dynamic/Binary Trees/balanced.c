#include <stdio.h>
#include "../../../Implementations/Trees/Dynamic/Btree.h"

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int height(Btree B) {
    if(B == NULL) return 0;
    int left = height(B->left);
    int right = height(B->right);
    return 1 + max(left, right);
}

int balanced(Btree B) {
    if(B == NULL) return 1;
    int left = height(B->left);
    int right = height(B->right);
    return balanced(B->left) && balanced(B->right) && ((left - right == 0) || (left - right == 1) || (left - right == -1));
}

void main() {
    Btree Lleft = Construct(4, NULL, NULL);
    Btree Rleft = Construct(5, NULL, NULL);
    Btree Bleft = Construct(2, Lleft, Rleft);
    Btree Lright = Construct(6, NULL, NULL);
    Btree Rright = Construct(7, NULL, NULL);
    Btree Bright = Construct(3, Lright, Rright);
    Btree B = Construct(1, Bleft, Bright);
    printf("%d\n", balanced(B));
}