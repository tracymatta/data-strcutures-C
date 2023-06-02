#include <stdio.h>
#include <stdlib.h>
#include "../Implementations/Heaps/Static/MinHeap/Heap.h"

Heap CreateHeap(int capacity, int heap_type) {
    Heap h = (Heap)malloc(sizeof(Heap));
    if(!h) return NULL;
    h->heap_type = heap_type;
    h->count = 0;
    h->capacity = capacity;
    h->array = (int*)malloc(sizeof(int)*h->capacity);
    if(!h->array) return NULL;
    return h;
}

int Parent(Heap h, int i) {
    if(i <= 0 || i >= h->count) return -1;
    return (i - 1) / 2;
}

int LeftChild(Heap h, int i) {
    int left = 2 * i + 1;
    if(left >= h->count) return -1;
    return left;
}

int RightChild(Heap h, int i) {
    int right = 2 * i + 2;
    if(right >= h->count) return -1;
    return right;
}

int GetMinimum(Heap h) {
    if(h->count == 0) return -1;
    return h->array[0];
}

void PercolateDown(Heap *h, int i) {
    int l = LeftChild(*h, i), r = RightChild(*h, i), min = i, temp;
    if(l != -1 && (*h)->array[l] < (*h)->array[i]) min = l;
    if(r != -1 && (*h)->array[r] < (*h)->array[min]) min = r;
    if(min != i) {
        temp = (*h)->array[i];
        (*h)->array[i] = (*h)->array[min];
        (*h)->array[min] = temp;
        PercolateDown(h, min);
    }
}

int DeleteMin(Heap *h) {
    int data;
    if((*h)->count == 0) return -1;
    data = (*h)->array[0];
    (*h)->array[0] = (*h)->array[(*h)->count - 1];
    (*h)->count -= 1;
    PercolateDown(h, 0);
    return data;
}

int Insert(Heap *h, int data) {
    int i;
    if((*h)->count == (*h)->capacity) ResizeHeap(h);
    (*h)->count += 1;
    i = (*h)->count - 1;
    while(i > 0 && data < (*h)->array[(i - 1) / 2]) {
        (*h)->array[i] = (*h)->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    (*h)->array[i] = data;
}

void ResizeHeap(Heap *h) {
    int *oldArray = (*h)->array;
    (*h)->array = (int*)malloc(sizeof(int) * (*h)->capacity * 2);
    if(!(*h)->array) return;
    for(int i = 0; i <= (*h)->capacity; i++) {
        (*h)->array[i] = oldArray[i];
    }
    (*h)->capacity *= 2;
    free(oldArray);
}

void DestroyHeap(Heap *h) {
    if(h == NULL) return;
    free((*h)->array);
    free(h);
    h = NULL;
}

void BuildHeap(Heap *h, int A[], int n) {
    if(h == NULL) return;
    while(n > (*h)->capacity) ResizeHeap(h);
    for(int i = 0; i < n; i++) (*h)->array[i] = A[i];
    (*h)->count = n;
    for(int j = (n - 1) / 2; j >= 0; j--) PercolateDown(h, j);
}