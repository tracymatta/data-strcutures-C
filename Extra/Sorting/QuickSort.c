#include <stdio.h>

int Partition(int A[], int low, int high) {
    int left = low + 1, right = high, pivotItem = A[low];
    while(left <= right) {
        while(A[left] <= pivotItem && left <= right) left += 1;
        while(A[right] > pivotItem && left <= right) right -= 1;
        if(left < right) {
            int temp = A[left];
            A[left] = A[right];
            A[right] = temp;
            left += 1;
            right -= 1;
        }
    }
    A[low] = A[right];
    A[right] = pivotItem;
    return right;
}

void QuickSortHelper(int A[], int low, int high) {
    int pivot;
    if(high > low) {
        pivot = Partition(A, low, high);
        QuickSortHelper(A, low, pivot - 1);
        QuickSortHelper(A, pivot + 1, high);
    }
}

void QuickSort(int A[], int n) {
    QuickSortHelper(A, 0, n - 1);
}

void main() {
    int T[10] = {4, 56, 27, 32, 85, 19, 43, 38, 20, 5};
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
    QuickSort(T, 10);
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
}