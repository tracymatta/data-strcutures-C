#include <stdio.h>
#include <string.h>

#define N 100

typedef char element;

typedef struct {
    element data[N];
    int top;
} stack; 

stack CreateStack() {
    stack p;
    p.top = -1;
    return p;
}

int isEmptyStack(stack p) {
    return p.top == -1;
}

int isFullStack(stack p) {
    return p.top == N-1;
}

int Push(stack *p, element e) {
    if(isFullStack(*p)) return 0;
    p->data[++p->top] = e;
    return 1;
}

int Pop(stack *p) {
    if(isEmptyStack(*p)) return 0;
    p->top--;
    return 1;
}

int Top(stack p, element *e) {
    if(isEmptyStack(p)) return 0;
    *e = p.data[p.top];
    return 1;
}

void printStack(stack s) {
    char e;
    while(!isEmptyStack(s)) {
        Top(s, &e);
        printf("%c ", e);
        Pop(&s);
    }
    printf("\n");
}

int isPalindrome(char *str) {
    if(*str == '\0') return -1;
    int length = strlen(str), counter = 0;
    element sTop;
    if(length == 1) return 1;
    stack s = CreateStack();
    while(counter < length/2) {
        Push(&s, *str);
        str = str + 1;
        counter++;
    }
    if(length%2 == 1) str = str + 1;
    while(!isEmptyStack(s) && *str != '\0') {
        Top(s, &sTop);
        if(sTop != *str) return 0;
        Pop(&s);
        str = str + 1;
    }
    if(!isEmptyStack(s) || *str != '\0') return 0;
    return 1;
}

void main() {
    printf("%d", isPalindrome("layal"));
}