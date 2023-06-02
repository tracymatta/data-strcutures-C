#include <stdio.h>

void SelectionSort(int A[], int n) {
    int temp, min;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) {
            if(A[j] < A[min]) min = j;
        }
        if(min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

void main() {
    int T[10] = {4, 56, 27, 32, 85, 19, 43, 38, 20, 5};
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
    SelectionSort(T, 10);
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
}