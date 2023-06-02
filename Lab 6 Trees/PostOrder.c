#include <stdio.h>
#include "CalkinWilfTree.h"

void PostOrderR(Btree B) {
    if(B != NULL) {
        PostOrderR(B->left);
        PostOrderR(B->right);
        printf("%d/%d ", B->data.num, B->data.denum);
    }
}

void ReversePostOrderR(Btree B) {
    if(B != NULL) {
        ReversePostOrderR(B->right);
        ReversePostOrderR(B->left);
        printf("%d/%d ", B->data.num, B->data.denum);
    }
}

void main () {
    Btree CalkinWilfTree = CreateCalkinWilfTree(4);
    PostOrderR(CalkinWilfTree);
    printf("\n");
    ReversePostOrderR(CalkinWilfTree);
    printf("\n");
}