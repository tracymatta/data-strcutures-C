#include <stdio.h>
#include <stdlib.h>
#include "../Implementations/Stacks/Static/Stack.h"

// Write a program that changes a positive decimal n to an hexadecimal number

void dec_to_hex(int n, char *hex) {
    if(n < 0) return;
    char *f = hex;
    if(n == 0) {
        *f = '0';
        f +=1;
    }
    stack s = CreateStack();
    int remains;
    element e;
    while(n != 0) {
        remains = n % 16;
        n = n / 16;
        Push(&s, remains);
    }
    while(isEmptyStack(s) == 0) {
        Top(s, &e);
        Pop(&s);
        if(e < 10) *f = e + '0';
        else *f = 'A' + (e - 10);
        f += 1;
    }
    *f = '\0';
}

void main() {
    char *hex = (char*)malloc(sizeof(char)*10);
    dec_to_hex(15, hex);
    printf("%s\n", hex);
}