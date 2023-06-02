#include <stdio.h>
#include "../../../Implementations/Trees/Dynamic/Btree.h"

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int mystery(Btree B) {
    if(B == NULL) return 0;
    return max(mystery(B->left), mystery(B->right));
}

void main() {
    Btree L = Construct(2, NULL, NULL);
    Btree R = Construct(3, NULL, NULL);
    Btree B = Construct(1, L, R);
    printf("%d", mystery(B));
}