#include <stdio.h>
#include <stdlib.h>
#include "../../../Implementations/Trees/Dynamic/Btree.h"

void insertBST(Btree *B, element e) {
    if(*B == NULL) {
        *B = Construct(e, NULL, NULL);
    }
    else {
        if((*B)->data < e) insertBST(&((*B)->right), e);
        else if((*B)->data > e) insertBST(&((*B)->left), e);
    }
}


void InOrderR(Btree B, stack *q) {
    if(B != NULL) {
        InOrderR(B->left, q);
        Push(q, B);
        InOrderR(B->right, q);
    }
}

int isPairPresent(Btree B, int target , int *nb1, int *nb2) // return the pair numbers in nb1 and nb2
{
    int *regular = (int*)malloc(sizeof(int)*20);
    int *reverse = regular;
    stack q = CreateStack();
    Btree e;
    InOrderR(B, &q);
    while(Top(q, &e)) {
        Pop(&q);
        *reverse = e->data;
        reverse += 1;
    }
    reverse -= 1;
    int *start = regular;
    while(regular != reverse) {
        if(*regular + *reverse == target) {
            *nb2 = *regular;
            *nb1 = *reverse;
            return 1;
        }
        if(*regular + *reverse < target) {
            regular = start;
            reverse -= 1;
        }
        if(*regular + *reverse > target) regular += 1;
    }
    return 0;
}

void main() {
    Btree B = Construct(8, NULL, NULL);
    insertBST(&B, 6);
    insertBST(&B, 3);
    insertBST(&B, 5);
    insertBST(&B, 4);
    insertBST(&B, 14);
    insertBST(&B, 12);
    insertBST(&B, 10);
    insertBST(&B, 13);
    insertBST(&B, 16);
    insertBST(&B, 15);
    int one, two;
    if(isPairPresent(B, 9, &one, &two)) {
        printf("%d + %d = 9\n", one, two);
    }
    else printf("No sum\n");
}