#include <stdio.h>

#define SIZE 13

typedef int element;

typedef element Hash[SIZE];

int HF(int k, int N) {
    return k % N;
}

void insert(Hash T, int val, int N) {
    int h = HF(val, N);
    if(T[h] == -1) T[h] = val;
    else {
        int i = h;
        do {
            if(T[i] == -1) {
                T[i] = val;
                break;
            }
            if(HF(T[i], N) == h && val < T[i]) {
                int temp = T[i];
                T[i] = val;
                val = temp;
            }
            i = (i + 1) % N;
        } while(i != h);
    }
}

void printHash(Hash h) {
    for(int i = 0; i < SIZE; i++) {
        printf("%d : ", i);
        if(h[i] != -1) printf("data=%d", h[i]);
        printf("\n");
    }
    printf("\n\n\n\n");
}

void test_insert(Hash h) {
    insert(h, 5, SIZE);
    insert(h, 6, SIZE);
    insert(h, 9, SIZE);
    insert(h, 10, SIZE);
    insert(h, 35, SIZE);
    insert(h, 22, SIZE);
    insert(h, 14, SIZE);
    insert(h, 1, SIZE);
    insert(h, 11, SIZE);
    insert(h, 48, SIZE);
}

void main() {
    Hash h;
    for(int i = 0; i < SIZE; i++) h[i] = -1;
    test_insert(h);
    printHash(h);
}