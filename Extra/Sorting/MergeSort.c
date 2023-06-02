#include <stdio.h>

void Fusion(int T[], int lower, int upper, int middle) {
    int i = lower, j = middle + 1, k = 0, c[upper - lower + 1];
    while(i <= middle && j <= upper) {
        if(T[i] < T[j]) c[k++] = T[i++];
        else c[k++] = T[j++];
    }
    while(i <= middle) c[k++] = T[i++];
    while(j <= upper) c[k++] = T[j++];
    for(i = lower, j = 0; j < k; i++, j++) T[i] = c[j];
}

void MergeSort(int T[], int lower, int upper) {
    if(lower < upper) {
        int middle = (lower + upper) / 2;
        MergeSort(T, lower, middle);
        MergeSort(T, middle + 1, upper);
        Fusion(T, lower, upper, middle);
    }
}

void main() {
    int T[10] = {4, 56, 27, 32, 85, 19, 43, 38, 20, 5};
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
    MergeSort(T, 0, 9);
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
}