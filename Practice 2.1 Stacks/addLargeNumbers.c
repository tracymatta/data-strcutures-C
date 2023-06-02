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

void sum(char *first, char *second, char *sum) {
    char *firstIterator = first, *secondIterator = second;
    stack firstStack = CreateStack(), secondStack = CreateStack(), sumStack = CreateStack();
    int carry = 0;
    element firstInput, secondInput, sumInput;
    while(*firstIterator != '\0') {
        Push(&firstStack, *firstIterator - '0');
        firstIterator = firstIterator + 1;
    }
    while(*secondIterator != '\0') {
        Push(&secondStack, *secondIterator - '0');
        secondIterator = secondIterator + 1;
    }
    while(!isEmptyStack(firstStack) && !isEmptyStack(secondStack)) {
        Top(firstStack, &firstInput);
        Top(secondStack, &secondInput);
        sumInput = firstInput + secondInput + carry;
        carry = sumInput/10;
        Push(&sumStack, sumInput%10);
        Pop(&firstStack);
        Pop(&secondStack);
    }
    while(!isEmptyStack(firstStack)){
        Top(firstStack, &firstInput);
        sumInput = firstInput + carry;
        carry = sumInput/10;
        Push(&sumStack, sumInput%10);
        Pop(&firstStack);
    }
    while(!isEmptyStack(secondStack)){
        Top(secondStack, &secondInput);
        sumInput = secondInput + carry;
        carry = sumInput/10;
        Push(&sumStack, sumInput%10);
        Pop(&secondStack);
    }
    int counter = 0;
    while(!isEmptyStack(sumStack)) {
        Top(sumStack, &sumInput);
        *(sum + counter) = sumInput + '0';
        Pop(&sumStack);
        counter++;
    }
    *(sum + counter) = '\0';
}

void main() {
    char *third = (char*)malloc(sizeof(char)*10);
    sum("592", "3784", third);
    printf("%s", third);
}