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

void fillST(SegmentTree *ST, int *A, int index, int start, int end, int *max) {
    if(index > *max) *max = index;
    if(start < end) {
        fillST(ST, A, 2*index + 1, start, (start + end) / 2, max);
        fillST(ST, A, 2*index + 2, (start + end) / 2 + 1, end, max);
        if(A[(*ST)->st[2*index + 1]] < A[(*ST)->st[2*index + 2]]) (*ST)->st[index] = (*ST)->st[2*index + 1];
        else (*ST)->st[index] = (*ST)->st[2*index + 2];
    }
    else (*ST)->st[index] = start;
}

SegmentTree createSegmentTree(int *A, int n) {
    SegmentTree ST = (SegmentTree)malloc(sizeof(struct Tree));
    ST->st = (int*)malloc(sizeof(int)*100);
    int max = 0;
    fillST(&ST, A, 0, 0, n-1, &max);
    ST->size = max + 1;
    return ST;
}

void main() {
    int A[] = {79, 90, 31, 41, 51, 82, 32, 29, 94, 14, 26, 46, 96, 45, 43, 44, 42, 18, 39, 25};
    SegmentTree ST = createSegmentTree(A, 20);
    printSegmentTree(ST);
}