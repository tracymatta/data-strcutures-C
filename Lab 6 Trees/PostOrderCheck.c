#include <stdio.h>
#include "CalkinWilfTree.h"

int PostOrderCheck(Btree B) {
    if(B == NULL) return 0;
    stack s1 = CreateStack(), s2 = CreateStack();
    Btree previous = NULL, A = B, previousR = NULL;
    while(1) {
        while(B != NULL) {
            Push(&s1, B);
            B = B->left;
        }
        while(A != NULL) {
            Push(&s2, A);
            A = A->right;
        }
        if(!isEmptyStack(s1)) {
            Top(s1, &B);
            Top(s2, &A);
            if(A->data.num != B->data.denum || A->data.denum != B->data.num) return 0;
            if(B->right == NULL || B->right == previous) {
                //printf("%d ", B->data);
                previous = B;
                B = NULL;
                Pop(&s1);
            }
            else B = B->right;
            if(A->left == NULL || A->left == previousR) {
                //printf("%d ", B->data);
                previousR = A;
                A = NULL;
                Pop(&s2);
            }
            else A = A->left;
        }
        else break;
    }
    return 1;
}

void main () {
    Btree CalkinWilfTree = CreateCalkinWilfTree(4);
    if(PostOrderCheck(CalkinWilfTree) == 1) printf("OK");
    else printf("NO");
}