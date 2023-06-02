#include <stdio.h>
#include <stdlib.h>
#include "../Implementations/Stacks/Static/Stack.h"

void printStack(stack s) {
    int e;
    while(!isEmptyStack(s)) {
        Top(s, &e);
        printf("%d ", e);
        Pop(&s);
    }
    printf("\n");
}

void sort(int *T, int size) {
    stack p = CreateStack(), q = CreateStack();
    element e;
    int i = 0;
    for(i = 0; i < size; i++) {
        if(isEmptyStack(p)) Push(&p, *(T + i));
        else {
            Top(p, &e);
            if(*(T + i) < e) Push(&p, *(T + i));
            else {
                while(!isEmptyStack(p)) {
                    Top(p, &e);
                    if(*(T + i) < e) {
                        Push(&p, *(T + i));
                        break;
                    }
                    else {
                        Push(&q, e);
                        Pop(&p);
                    }
                }
                if(isEmptyStack(p)) Push(&p, *(T + i));
                while(!isEmptyStack(q)) {
                    Top(q, &e);
                    Pop(&q);
                    Push(&p, e);
                }
            }
        }
    }
    i = 0;
    while(!isEmptyStack(p)) {
        Top(p, &e);
        Pop(&p);
        *(T + i) = e;
        i++;
    }
}

void main() {
    int *T = (int*)malloc(sizeof(int)*4);
    T[0] = 33;
    T[1] = 21;
    T[2] = 48;
    T[3] = 34;
    for(int i=0; i<4; i++) printf("%d ", T[i]);
    printf("\n");
    sort(T, 4);
    for(int i=0; i<4; i++) printf("%d ", T[i]);
    printf("\n");
}