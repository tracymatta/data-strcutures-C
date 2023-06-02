#include <stdio.h>
#include "../Implementations/Stacks/Static/Stack.h"

int nth(stack s, int n) {
    if(n < 1) return -1;
    while(n > 1 && !isEmptyStack(s)) {
        Pop(&s);
        n--;
    }
    if(n > 1) return -1;
    int e;
    Top(s,&e);
    return e;
}

void main() {
    stack s = CreateStack();
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 5);
    int n = 4;
    printf("The %d th element is: %d\n", n, nth(s, n));
    Top(s, &n);
    printf("The top element is: %d", n);
}