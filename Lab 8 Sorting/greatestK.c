#include <stdio.h>
#include "../Implementations/Heaps/Static/MaxHeap/Heap.h"

void print_max(int *A, int n, int k)
{
    if(k <= 0 || n <=0 || k > n) return;
	Heap h = CreateHeap(n, 1);
	BuildHeap(&h, A, n);
	for(; k > 0; k--) printf("%d ", DeleteMax(&h));
}

void main() {
	int A[10] = {4, 6, 98, 40, 32, 63, 12, 145, 1, 80};
	print_max(A, 10, 5);
}