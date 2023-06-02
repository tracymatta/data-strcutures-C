#include <stdio.h>
#include "../Implementations/Stacks/Static/Stack.h"


typedef struct Array {
    stack s;
    int nb_elements;
} Array;

Array CreateArray(int elements) {
    Array newArray;
    newArray.nb_elements = elements;
    newArray.s = CreateStack();
    while(elements > 0) {
        Push(&(newArray.s), 0);
        elements--;
    }
    return newArray;
}

int Assign(Array *toChange, int data, int pos) {
    if(pos > toChange->nb_elements || pos < 0) return 0;
    int counter = 0;
    int e;
    stack p = CreateStack();
    while(counter <= toChange->nb_elements -pos -1) {
        Top(toChange->s, &e);
        Push(&p, e);
        Pop(&(toChange->s));
        counter++;
    }
    Push(&(toChange->s), data);
    Pop(&p);
    while(!isEmptyStack(p)) {
        Top(p, &e);
        Push(&(toChange->s), e);
        Pop(&p);
    }
    return 1;
}

void printArrayHelper(Array toPrint) {
    if(isEmptyStack(toPrint.s)) return;
    int data;
    Top(toPrint.s, &data);
    Pop(&(toPrint.s));
    printArrayHelper(toPrint);
    printf("%d ", data);
}

void printArray(Array toPrint, int size) {
    int counter = 0;
    while(counter < toPrint.nb_elements -size) {
        Pop(&(toPrint.s));
        counter++;
    }
    printArrayHelper(toPrint);
    printf("\n");
}

void main() {
    Array A = CreateArray(5);
    Assign(&A, -5, 0);
    Assign(&A, 66, 3);
    Assign(&A, 20, 1);
    Assign(&A, 0, 2);
    printArray(A, 4);
    printArray(A, 4);
}

