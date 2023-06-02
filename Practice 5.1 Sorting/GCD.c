#include <stdio.h>
#include "../Implementations/Heaps/Static/MinHeap/Heap.h"

int GCD(Heap L, Heap R) {
    int gcd = 1, minL, minR;
    while(1) {
        minL = GetMinimum(L);
        minR = GetMinimum(R);
        if(minL == -1 || minR == -1) break;
        if(minL == minR) {
            gcd *= minL;
            DeleteMin(&L);
            DeleteMin(&R);
        }
        else if(minL < minR) DeleteMin(&L);
        else DeleteMin(&R);
    }
    return gcd;
}

void main() {
    int A[6] = {2, 3, 5, 2, 5, 6};
    Heap h1 = CreateHeap(6, 2);
    BuildHeap(&h1, A, 6);
    int B[4] = {2, 3, 7, 9};
    Heap h2 = CreateHeap(4, 2);
    BuildHeap(&h2, B, 4);
    printf("%d", GCD(h1, h2));
}
