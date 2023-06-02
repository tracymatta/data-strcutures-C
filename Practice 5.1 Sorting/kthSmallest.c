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

int QuickSortHelper(int A[], int low, int high, int k) {
    int pivot;
    if(k > 0 && high > low && k <= (high - low + 1)) {
        pivot = Partition(A, low, high);
        if(k == pivot - low + 1) return A[pivot];
        if(k < pivot - low + 1) return QuickSortHelper(A, low, pivot - 1, k);
        else return QuickSortHelper(A, pivot + 1, high, k - (pivot - low + 1));
    }
    if(high == low && k == 1) return A[low];
    return -1;
}

int QuickSort(int A[], int n, int k) {
    return QuickSortHelper(A, 0, n - 1, k);
}

void main() {
    int T[10] = {-72, 100, 24, -66, -43, 4, 48, -41, -68, -64};
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
    printf("%d\n", QuickSort(T, 10, 5));
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
}