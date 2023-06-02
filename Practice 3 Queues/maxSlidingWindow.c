#include <stdio.h>
#include "../Implementations/Deques/Static/Deque.h"

void maxSlidingWindow(int *T, int size, int window, int *toFill) {
    if(size < window) return;
    deque d = CreateDeque();
    int indexT = 0, indextoFill = 0;
    int max = 0;
    element e;
    while(indexT < window) {
        EnqueueRear(&d, *(T + indexT));
        indexT++;
        if(*(T + indexT) > max) max = *(T + indexT);
    }
    *(toFill + indextoFill) = max;
    indextoFill++;
    while(indexT < size) {
        Front(d, &e);
        DequeueFront(&d);
        EnqueueRear(&d, *(T + indexT));
        if(e != max) {
            if(*(T + indexT) > max) max = *(T + indexT);
        }
        else {
            max = 0;
            deque aux = CreateDeque();
            while(!isEmptyDeque(d)) {
                Front(d, &e);
                DequeueFront(&d);
                EnqueueFront(&aux, e);
                if(e > max) max = e;
            }
            while(!isEmptyDeque(aux)) {
                Front(aux, &e);
                DequeueFront(&aux);
                EnqueueFront(&d, e);
            }
        }
        *(toFill + indextoFill) = max;
        indextoFill++;
        indexT++;
    }
}

void main() {
    int T[8] = {1, 3, -1, -3, 5, 3, 6, 7};
    int B[6];
    maxSlidingWindow(T, 8, 3, B);
    for(int i = 0; i < 6; i++) {
        printf("%d ", B[i]);
    }
}