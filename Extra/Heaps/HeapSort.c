#include <Stdio.h>
#include "../../Implementations/Heaps/Static/MaxHeap/Heap.h"

void HeapSort(int A[], int n) {
    Heap h = CreateHeap(n, 1);
    int oldSize, temp;
    BuildHeap(&h, A, n);
    oldSize = h->count;
    for(int i = n - 1; i >= 0; i--) {
        //h->array[0] is the largest element
        temp = h->array[0];
        h->array[0] = h->array[h->count - 1];
        h->array[h->count - 1] = temp;
        h->count -= 1;
        PercolateDown(&h, 0);
    }
    h->count = oldSize;
    for(int j = 0; j < h->count; j++) A[j] = h->array[j];
}

void main() {
    int T[10] = {4, 56, 27, 32, 85, 19, 43, 38, 20, 5};
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
    HeapSort(T, 10);
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
}