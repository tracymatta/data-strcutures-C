#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int *st;
    int size;
} *SegmentTree;

void printSegmentTree(SegmentTree ST) {
    for(int i = 0; i < ST->size; i++) printf("index: %d   value: %d\n", i, ST->st[i]);
    printf("\n");
}

void fillST(SegmentTree *ST, int *A, int index, int start, int end) {
    if(start > end) return;
    (*ST)->size += 1;
    if(start != end) {
        fillST(ST, A, 2*index + 1, start, (start + end) / 2);
        fillST(ST, A, 2*index + 2, (start + end) / 2 + 1, end);
        if(A[(*ST)->st[2*index + 1]] < A[(*ST)->st[2*index + 2]]) (*ST)->st[index] = (*ST)->st[2*index + 1];
        else (*ST)->st[index] = (*ST)->st[2*index + 2];
    }
    else (*ST)->st[index] = start;

}

SegmentTree createSegmentTree(int *A, int n) {
    SegmentTree ST = (SegmentTree)malloc(sizeof(struct Tree));
    ST->st = (int*)malloc(sizeof(int)*100);
    ST->size = 0;
    fillST(&ST, A, 0, 0, n-1);
    return ST;
}

int RMQ(SegmentTree ST, int *A, int n, int i, int j) {
    if(j < i) return -1;
    if(i == j) return i;
    int p1 = RMQ(ST, A, n, i , (i + j) / 2);
    int p2 = RMQ(ST, A, n, (i + j) / 2 + 1, j);
    if(*(A + p1) < *(A + p2)) return p1;
    else return p2;
}

void main() {
    int A[] = {18, 17, 13, 19, 15, 11, 20};
    SegmentTree ST = createSegmentTree(A, 7);
    printSegmentTree(ST);
    printf("RMQ(0, 1): %d\n", RMQ(ST, A, 7, 0, 1));
    printf("RMQ(0, 4): %d\n", RMQ(ST, A, 7, 0, 4));
    printf("RMQ(0, 6): %d\n", RMQ(ST, A, 7, 0, 6));
    printf("RMQ(1, 4): %d\n", RMQ(ST, A, 7, 1, 4));
    printf("RMQ(2, 3): %d\n", RMQ(ST, A, 7, 2, 3));
    printf("RMQ(3, 4): %d\n", RMQ(ST, A, 7, 3, 4));
    printf("RMQ(3, 5): %d\n", RMQ(ST, A, 7, 3, 5));
    printf("RMQ(6, 3): %d\n", RMQ(ST, A, 7, 6, 3));
}

