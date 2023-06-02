#include <stdio.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

void Inorder(Btree B) {
    if(B == NULL) return;
    printf("%c ", B->data);
    Inorder(B->left);
    Inorder(B->right);
}

Btree Build(char *preorder, int *start) {
    if(*(preorder + *start) == '\0') return NULL;
    *start += 1;
    if(*(preorder + (*start) - 1) == '0') {
        return Construct(*(preorder + (*start) - 1), NULL, NULL);
    }
    Btree B = Construct(*(preorder + (*start) - 1), NULL, NULL);
    B->left = Build(preorder, start);
    B->right = Build(preorder, start);
    return B;
}

void main() {
    int start = 0;
    Btree B = Build("ABDF000E00C0G00", &start);
    Inorder(B);
}