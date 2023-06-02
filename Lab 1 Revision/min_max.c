#include <stdio.h>

void min_max(int tab[], int size, int *min, int *max) {
    if(size <= 0) return;
    if(size == 1) {
        *min = tab[size-1];
        *max = tab[size-1];
        return;
    }
    min_max(tab, size-1, min, max);
    if(tab[size-1] < *min) *min = tab[size-1];
    else if(tab[size-1] > *max) *max = tab[size-1];
}

void main() {
    int tab[5] = {358, -418, -113, 389, -207};
    int min, max;
    min_max(tab, 5, &min, &max);
    printf("%d %d", min, max);
}