#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void push(node **binaryref, int data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *binaryref;
    *binaryref = newnode;
}

void printLL(node *binary) {
    if(binary==NULL) printf("empty");
    for( ; binary!=NULL; binary=binary->next) {
        printf("%d ", binary->data);
    }
    printf("\n");
}

int toDecimalHelper(node *binary, int *exponent) {
    if(binary == NULL) return 0;
    int decimal = toDecimalHelper(binary->next, exponent);
    *exponent += 1;
    return decimal + binary->data*pow(2, *exponent);
}

int toDecimal(node *binary) {
    int exponent = -1;
    return toDecimalHelper(binary, &exponent);
}

void main() {
    node *binary = NULL;
    push(&binary, 1);
    push(&binary, 1);
    push(&binary, 1);
    push(&binary, 0);
    push(&binary, 0);
    printLL(binary);
    printf("%d", toDecimal(binary));
}
