#include <stdio.h>
#include "../Implementations/Heaps/Static/MinHeap/Heap.h"

void print(Heap h) {
    if(h == NULL) return;
    int min = -1, count = 0, newMin;
    while(1) {
        newMin = GetMinimum(h);
        if(min == -1) min = newMin;
        if(newMin == -1 || newMin != min) {
            printf("%d", min);
            if(count != 1) printf("^%d", count);
            if(newMin != -1) printf(" x ");
            else break;
            min = newMin;
            count = 0;
        }
        count += 1;
        DeleteMin(&h);
    }
}

void main() {
    int A[6] = {2, 3, 5, 2, 5, 6};
    Heap h = CreateHeap(6, 2);
    BuildHeap(&h, A, 6);
    print(h);
}