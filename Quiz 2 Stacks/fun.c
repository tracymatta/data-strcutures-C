#include <stdio.h>
#include "../Implementations/Stacks/Static/Stack.h"

// Imagine you want to read a list of items, and each time you read a negative number -b, 
//  backward and print b numbers that come before the negative number
// If there are fewer than b items in the stack, print the available numbers and stop the program
// When there's no more input, print the remaining items in the stack 

void fun() {
    stack s = CreateStack();
    int e;
    element toPrint;
    while(scanf("%d", &e) != EOF && e != 0) { //the second condition is only for vscode to know when to stop, only the first for moodle
        if(e > 0) Push(&s, e);
        else {
            int i;
            for(i = 0; (i < (-1*e)) && (isEmptyStack(s) == 0); i++) {
                Top(s, &toPrint);
                Pop(&s);
                printf("%d ", toPrint);
            }
            if((isEmptyStack(s) == 1) && (i < (-1*e))) return;
        }
    }
    while(isEmptyStack(s) == 0) {
        Top(s, &toPrint);
        Pop(&s);
        printf("%d ", toPrint);
    }
}

void main() {
    fun();
}