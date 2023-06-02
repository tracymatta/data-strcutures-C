#include <stdio.h>

#define N 10

typedef char element;

typedef element Hash[N];

int HF(char k, int size) {
    return ((int)k) % size;
}

int belong(Hash h, element e, int size, int hop)
{
    int idx = HF(e, size), count = 0;
    while(count < hop) {
        if(*(h + ((idx + count) % size)) == e) return 1;
        count += 1;
    }
    return 0;
}

int insert(Hash h, element e, int size, int hop)
{
    if(belong(h, e, size, hop) == 1) return 0;
    int idx = HF(e, size), count = 0;
    while(count < hop) {
        if(*(h + ((idx + count) % size)) <= '0') {
            *(h + ((idx + count) % size)) = e;
            return 1;
        } 
        count += 1;
    }
    int empty = size + 1;
    while(count < size) {
        if(*(h + ((idx + count) % size)) <= '0') {
            empty = (idx + count) % size;
            if(empty < 0) empty += size;
            break;
        }
        count += 1;
    }
    if(empty == size + 1) return 0;
    count = hop - 1;
    while(count > 0) {
        int r = ((empty - count) % size);
        if(r < 0) r += size;
        int j = HF(*(h + r), size), i;
        for(i = 0; i < hop; i++) if(empty == ((j + i) % size)) break;
        if(i == hop) {
            count -= 1;
            continue;
        }
        *(h + empty) = *(h + r);
        *(h + r) = '0';
        empty = r;
        //if(empty < 0) empty += size;
        for(i = 0; i < hop; i++) if(empty == ((idx + i) % size)) break;
        if(i < hop) {
            *(h + empty) = e;
            return 1;
        } 
        count = hop - 1;
    }
    return 0;
}

void main() {
    Hash h;
    for(int i = 0; i < N; i++) h[i] = '0';
    insert(h, 'a', N, 3);
    insert(h, 'b', N, 3);
    insert(h, 'l', N, 3);
    insert(h, 'd', N, 3);
    insert(h, 'e', N, 3);
    insert(h, 'k', N, 3);
    for(int i = 0; i < N; i++) {
        printf("%d : ", i);
        if(h[i] != '0') printf("data=%c", h[i]);
        printf("\n");
    }
    if(belong(h, 'k', N, 3)) printf("'k' in the table\n");
    else printf("'k' not in the table\n");
    if(belong(h, 'c', N, 3)) printf("'c' in the table\n");
    else printf("'c' not in the table\n");
}