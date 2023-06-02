#include <stdio.h>

void BubbleSort(int A[], int n) {
    int temp, flag = 1;
    for(int i = n - 1; i >= 0 && flag == 1; i--) {
        flag = 0;
        for(int j = 0; j < i; j++) {
            if(A[j] > A[j + 1]) {
                flag = 1;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void main() {
    int T[10] = {4, 56, 27, 32, 85, 19, 43, 38, 20, 5};
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
    BubbleSort(T, 10);
    for(int i = 0; i < 10; i++) printf("%d ", T[i]);
    printf("\n");
}