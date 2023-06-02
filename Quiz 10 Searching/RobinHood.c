#include <stdio.h>

#define N 11

typedef char element;

typedef element Hash[N];

int HF(element k, int n) {
    return ((int) k ) % n;
}

int insert(Hash h, element val, int n) {
    int i = HF(val, n), j = i, probe1 = 0, probe2;
    do {
        if(h[i] == '0') {
            h[i] = val;
            return 1;
        }
        probe2 = i - HF(h[i], n);
        if(probe2 < 0) probe2 += n;
        if(probe2 >= probe1) probe1 += 1;
        else {
            int temp = h[i];
            h[i] = val;
            val = temp;
            probe1 = probe2 + 1;
        }
        i = (i + 1) % N;
    } while(i != j);
    return 0;
}

void test_insert(Hash H) {
    insert(H, 'D', 11);
    insert(H, 'r', 11);
    insert(H, 'X', 11);
    insert(H, 'F', 11);
    insert(H, 'h', 11);
    insert(H, 'a', 11);
    insert(H, 'S', 11);
    insert(H, 'v', 11);
    insert(H, 'g', 11);
} 

void printHash(Hash H) {
    for(int i = 0; i < N; i++) {
        printf("%d : ", i);
        if(H[i] != '0') printf("data=%c ", H[i]);
        printf("\n");
    }
}

void main() {
    Hash H;
    for(int i = 0; i < N; i++) H[i] = '0';
    test_insert(H);
    printHash(H);
}