#include <stdio.h>
#include "../Implementations/Stacks/Static/Stack.h"

typedef struct  {
	stack s;
	element min;
} theStack;

void printStack(stack s) {
    int e;
    while(!isEmptyStack(s)) {
        Top(s, &e);
        printf("%d ", e);
        Pop(&s);
    }
    printf("\n");
}

theStack CreatetheStack()
{
	theStack p;
	p.s = CreateStack();
	return p;
}

int PushtheStack(theStack *p, element e)
{
	if(isFullStack(p->s)) return 0;
    if(isEmptyStack(p->s)){
        Push(&(p->s), e);
        p->min = e;
        return 1;
    }
    else if(e >= p->min) {
        Push(&(p->s), e);
    }
    else {
        Push(&(p->s), 2*e - p->min);
        p->min = e;
    }
    return 1;
}

int PoptheStack(theStack *p)
{
    if(isEmptyStack(p->s)) return 0;
    int y;
    Top(p->s, &y);
    Pop(&(p->s));
    if(y < p->min) p->min = 2 * p->min - y;
    return 1;
}

int ToptheStack(theStack p, element *e)
{
    if(isEmptyStack(p.s)) return 0;
    int y;
    Top(p.s, &y);
    if(y >= p.min) *e = y;
    else *e = p.min;
    return 1;
}

int getMin(theStack p, element *e)
{
	if(isEmptyStack(p.s)) return 0;
	*e = p.min;
	return 1;
}

void main() {
    theStack s = CreatetheStack();
    PushtheStack(&s, 1);
    PushtheStack(&s, 2);
    PushtheStack(&s, 3);
    PushtheStack(&s, 4);
    PushtheStack(&s, 5);
    printStack(s.s);
    element x;
    getMin(s, &x);
    printf("%d\n", x);
}