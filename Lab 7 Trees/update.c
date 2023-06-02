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

int minST(int *A, int a, int b) {
    if(a == -1) return b;
    if(b == -1) return a;
    if(A[a] < A[b]) return a;
    return b;
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

void updatePointStreeHelper(SegmentTree ST, int *A, int start, int end, int index, int current) {
    if(start > end) return;
    if(start != end) {
        if(index <= (start + end) / 2) {
            updatePointStreeHelper(ST, A, start, (start + end) / 2, index, 2*current + 1);
            if(A[ST->st[2 * current + 2]] < A[ST->st[2 * current + 1]]) ST->st[current] = ST->st[2*current + 2];
            else ST->st[current] = ST->st[2 * current + 1];
        }
        else {
            updatePointStreeHelper(ST, A, (start + end) / 2 + 1, end, index, 2*current + 2);
            if(A[ST->st[2 * current + 2]] < A[ST->st[2 * current + 1]]) ST->st[current] = ST->st[2*current + 2];
            else ST->st[current] = ST->st[2 * current + 1];
        }
    }
}

void updatePointStree(SegmentTree ST, int *A, int n, int index, int newValue) {
    A[index] = newValue;
    updatePointStreeHelper(ST, A, 0, n - 1, index, 0);
}

void main() {
    int A[] = {18, 17, 13, 19, 15, 11, 20};
    int n = 7;
    SegmentTree ST = createSegmentTree(A, n);
    updatePointStree(ST, A, n, 5, 99);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("RMQ(%d, %d) = %d\n", i, j, RMQ(ST, A, n, i, j));
        }
    }
}
