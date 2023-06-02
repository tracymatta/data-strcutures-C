#include <stdio.h>
#include "../Implementations/Trees/Dynamic/Btree.h"

void printRec(Btree B) {
    if(B == NULL) return;
    if(B->right == NULL && B->left == NULL) printf("%d ", B->data);
    printRec(B->right);
    printRec(B->left);
}

void printIter(Btree B) {
    if(B == NULL) return;
    queue q = CreateQueue();
    EnQueue(&q, B);
    while(Front(q, &B)) {
        DeQueue(&q);
        if(B->right == NULL && B->left == NULL) printf("%d ", B->data);
        if(B->right != NULL) EnQueue(&q, B->right);
        if(B->left != NULL) EnQueue(&q, B->left);
    }
    printf("\n");
}

void main() {
    Btree B = Construct(6, 
                        Construct(3, 
                            Construct(1, 
                                Construct(-5, 
                                    NULL, 
                                    Construct(0, 
                                        NULL, 
                                        NULL
                                    )
                                ),
                                NULL
                            ),
                            Construct(5, 
                                Construct(4, 
                                    NULL, 
                                    NULL
                                ),
                                NULL
                            )
                        ),
                        Construct(8,
                            NULL,
                            Construct(23,
                                NULL,
                                NULL
                            )
                        )
                    );
    printIter(B);
    printRec(B);
}