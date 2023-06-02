#include <stdio.h>
#include "../Implementations/Stacks/Static/Stack.h"

typedef struct {
    stack stack1, stack2;
} theStack;

void printStack(stack p) {
    element e;
    while(!isEmptyStack(p)) {
        Top(p, &e);
        printf("%d ", e);
        Pop(&p);
    }
    printf("\n");
}

theStack CreatetheStack() {
    theStack newstack;
    newstack.stack1 = CreateStack();
    newstack.stack2 = CreateStack();
    return newstack;
}

int isEmptytheStack(theStack s) {
    return s.stack1.top == -1;
}

int isFulltheStack(theStack s) {
    return s.stack1.top == N -1;
}

int PushtheStack(theStack *s, element e) {
    if(isFullStack(s->stack1)) return 0;
    Push(&(s->stack1), e);
    element top;
    Top(s->stack2, &top);
    if(e < top)  Push(&(s->stack2), e);
    else Push(&(s->stack2), top);
    return 1;
}

int PoptheStack(theStack *s) {
    if(isEmptyStack(s->stack1)) return 0;
    Pop(&(s->stack1));
    Pop(&(s->stack2));
    return 1;
}

int ToptheStack(theStack s, element *e) {
    if(isEmptyStack(s.stack1)) return 0;
    Top(s.stack1, e);
    return 1;
}

int getMin(theStack s, element *e) {
    if(isEmptyStack(s.stack2)) return 0;
    Top(s.stack2, e);
    return 1;
}

void main() {
    theStack s = CreatetheStack();
    PushtheStack(&s, 1);
    PushtheStack(&s, 2);
    PushtheStack(&s, 3);
    PushtheStack(&s, 4);
    PushtheStack(&s, 5);
    printStack(s.stack1);
    element x;
    getMin(s, &x);
    printf("%d\n", x);
}