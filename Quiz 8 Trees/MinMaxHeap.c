#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct heap {
    int *array;
    int count;
    int capacity;
} *Heap;

Heap CreateHeap(int capacity) {
    Heap h = (Heap) malloc (sizeof(struct heap));
    h->count = 0;
    h->capacity = capacity;
    h->array = (int*) malloc (sizeof(int) * h->capacity);
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

int IsOnMinLevel(Heap H, int i) {
    int level = floor(log2(i + 1));
    if(level % 2 == 0) return 1;
    return 0;
}

int FindMin(Heap H, int i) {
    int min = i;
    if(LeftChild(H, i) != -1) {
        if(H->array[LeftChild(H, i)] < H->array[min]) min = LeftChild(H, i);
        if(LeftChild(H, LeftChild(H, i)) != -1 && H->array[LeftChild(H, LeftChild(H, i))] < H->array[min]) 
            min = LeftChild(H, LeftChild(H, i));
        if(RightChild(H, LeftChild(H, i)) != -1 && H->array[RightChild(H, LeftChild(H, i))] < H->array[min]) 
            min = RightChild(H, LeftChild(H, i));
    }
    if(RightChild(H, i) != -1) {
        if(H->array[RightChild(H, i)] < H->array[min]) min = RightChild(H, i);
        if(LeftChild(H, RightChild(H, i)) != -1 && H->array[LeftChild(H, RightChild(H, i))] < H->array[min]) 
            min = LeftChild(H, RightChild(H, i));
        if(RightChild(H, RightChild(H, i)) != -1 && H->array[RightChild(H, RightChild(H, i))] < H->array[min]) 
            min = RightChild(H, RightChild(H, i));
    }
    return min;
}

void PercolateDownMin(Heap *H, int i) {
    int m = FindMin(*H, i);
    if(m != i) {
        int temp = (*H)->array[i];
        (*H)->array[i] = (*H)->array[m];
        (*H)->array[m] = temp;
        if(m > RightChild(*H, i)) {
            int n = Parent(*H, m);
            if((*H)->array[m] > (*H)->array[n]) {
                int temp2 = (*H)->array[m];
                (*H)->array[m] = (*H)->array[n];
                (*H)->array[n] = temp;
            }
            PercolateDownMin(H, m);
        }
    }
}

int FindMax(Heap H, int i) {
    int max = i;
    if(LeftChild(H, i) != -1) {
        if(H->array[LeftChild(H, i)] > H->array[max]) max = LeftChild(H, i);
        if(LeftChild(H, LeftChild(H, i)) != -1 && H->array[LeftChild(H, LeftChild(H, i))] > H->array[max]) 
            max = LeftChild(H, LeftChild(H, i));
        if(RightChild(H, LeftChild(H, i)) != -1 && H->array[RightChild(H, LeftChild(H, i))] > H->array[max]) 
            max = RightChild(H, LeftChild(H, i));
    }
    if(RightChild(H, i) != -1) {
        if(H->array[RightChild(H, i)] > H->array[max]) max = RightChild(H, i);
        if(LeftChild(H, RightChild(H, i)) != -1 && H->array[LeftChild(H, RightChild(H, i))] > H->array[max]) 
            max = LeftChild(H, RightChild(H, i));
        if(RightChild(H, RightChild(H, i)) != -1 && H->array[RightChild(H, RightChild(H, i))] > H->array[max]) 
            max = RightChild(H, RightChild(H, i));
    }
    return max;
}

void PercolateDownMax(Heap *H, int i) {
    int m = FindMax(*H, i);
    if(m != i) {
        int temp = (*H)->array[i];
        (*H)->array[i] = (*H)->array[m];
        (*H)->array[m] = temp;
        if(m > RightChild(*H, i)) {
            int n = Parent(*H, m);
            if((*H)->array[m] < (*H)->array[n]) {
                int temp2 = (*H)->array[m];
                (*H)->array[m] = (*H)->array[n];
                (*H)->array[n] = temp;
            }
            PercolateDownMax(H, m);
        }
    }
}

void PercolateDown(Heap *H, int i) {
    if(IsOnMinLevel(*H, i)) PercolateDownMin(H, i);
    else PercolateDownMax(H, i); 
}

int DeleteMax(Heap *h) {
    if((*h)->count < 2) return -1;
    int left = LeftChild(*h, 0);
    int right = RightChild(*h, 0);
    int max;
    if(right == -1 || (*h)->array[left] > (*h)->array[right]) {
        max = (*h)->array[1];
        (*h)->array[1] = (*h)->array[(*h)->count - 1];
        (*h)->count -= 1;
        PercolateDown(h, 1);
    }
    else {
        max = (*h)->array[2];
        (*h)->array[2] = (*h)->array[(*h)->count - 1];
        (*h)->count -= 1;
        PercolateDown(h, 2);
    }
    return max;
}

void ResizeHeap(Heap *h) {
    int i; 
    int *oldArray = (*h)->array;
    (*h)->array = (int*) malloc (sizeof(int) * (*h)->capacity * 2);
    for(int i = 0; i < (*h)->capacity; i++) (*h)->array[i] = oldArray[i];
    (*h)->capacity *= 2;
    free(oldArray);
}

void BuildHeap(Heap *h, int A[], int n) {
    (*h)->array = (int*) malloc (sizeof(int) * n);
    for(int i = 0; i < n; i++) (*h)->array[i] = A[i];
    (*h)->count = n;
    for(int j = (n - 1) / 2; j >= 0; j--) PercolateDown(h, j);
}

void HeapSort(int A[], int n) {
    if(n == 0) return;
    Heap h = CreateHeap(n);
    BuildHeap(&h, A, n);
    for(int i = 0; i < n; i++) {
        A[i] = h->array[0];
        h->array[0] = h->array[h->count - 1];
        h->count -= 1;
        PercolateDown(&h, 0);
    }
}

void main() {
    int A[10] = {66, 71, 1, 97, 38, 6, 74, 99, 30, 67};
    HeapSort(A, 10);
    for(int i = 0; i < 10; i++) printf("%d ", A[i]);
}