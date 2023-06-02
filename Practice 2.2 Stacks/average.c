#include <stdio.h>
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

double average(stack s) {
    if(isEmptyStack(s)) return 0/1.0;
    element count = 0, sum = 0, top;
    while(!isEmptyStack(s)) {
        Top(s, &top);
        Pop(&s);
        sum += top;
        count++;
    }
    return sum/(1.0*count);
}

void main() {
    stack s = CreateStack();
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 5);
    printStack(s);
    printf("%lf\n", average(s));
    printStack(s);
}