#include <stdio.h>

void InsertionSort(int A[], int n) {
    int v, j;
    for(int i = 1; i < n; i++) {
        v = A[i];
        j = i;
        while(j > 0 && A[j - 1] > v) {
            A[j] = A[j - 1];
            j -= 1;
        }
         A[j] = v;
    }
}

void main() {
    int T[10] = {4, 56, 27, 32, 85, 19, 43, 38, 20, 5};
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
    InsertionSort(T, 10);
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
}