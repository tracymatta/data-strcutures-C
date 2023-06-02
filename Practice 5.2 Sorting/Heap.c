#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

Heap CreateHeap(int capacity, int heap_type) {
    Heap h = (Heap)malloc(sizeof(Heap));
    if(!h) return NULL;
    h->heap_type = heap_type;
    h->count = 0;
    h->capacity = capacity;
    h->array = (element*) malloc (sizeof(element)*h->capacity);
    if(!h->array) return NULL;
    return h;
}

int isEmptyHeap(Heap h) {
    return h->count == 0;
}

int isFullHeap(Heap h) {
    return h->count == h->capacity;
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

int GetMaximum(Heap h, element *e) {
    if(h->count == 0) return 0;
    *e = h->array[0];
    return 1;
}

void PercolateDown(Heap *h, int i) {
    int l = LeftChild(*h, i), r = RightChild(*h, i), max = i;
    element temp;
    if(l != -1 && (*h)->array[l].counter > (*h)->array[i].counter) max = l;
    if(r != -1 && (*h)->array[r].counter > (*h)->array[max].counter) max = r;
    if(max != i) {
        temp = (*h)->array[i];
        (*h)->array[i] = (*h)->array[max];
        (*h)->array[max] = temp;
        PercolateDown(h, max);
    }
}

int DeleteMax(Heap *h) {
    int data;
    if((*h)->count == 0) return -1;
    data = (*h)->array[0].data;
    (*h)->array[0] = (*h)->array[(*h)->count - 1];
    (*h)->count -= 1;
    PercolateDown(h, 0);
    return data;
}

int Insert(Heap *h, element data) {
    int i;
    if((*h)->count == (*h)->capacity) ResizeHeap(h);
    (*h)->count += 1;
    i = (*h)->count - 1;
    while(i > 0 && data.counter > (*h)->array[(i - 1) / 2].counter) {
        (*h)->array[i] = (*h)->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    (*h)->array[i] = data;
}

void ResizeHeap(Heap *h) {
    element *oldArray = (*h)->array;
    (*h)->array = (element*) malloc (sizeof(element) * (*h)->capacity * 2);
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