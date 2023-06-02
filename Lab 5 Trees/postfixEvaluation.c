#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

typedef char element;

typedef struct node {
    element data;
    struct node *left, *right;
} *ExpressionTree;

typedef struct {
    ExpressionTree data[N];
    int top;
} stack; 


ExpressionTree Construct(element e, ExpressionTree L, ExpressionTree R) {
    ExpressionTree created = (ExpressionTree) malloc (sizeof(struct node));
    if(!created) return 0;
    created->data = e;
    created->left = L;
    created->right = R;
    return created;
}


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

int Push(stack *p, ExpressionTree e) {
    if(isFullStack(*p)) return 0;
    p->data[++p->top] = e;
    return 1;
}

int Pop(stack *p) {
    if(isEmptyStack(*p)) return 0;
    p->top--;
    return 1;
}

int Top(stack p, ExpressionTree *e) {
    if(isEmptyStack(p)) return 0;
    *e = p.data[p.top];
    return 1;
}

int is_digit(char c) {
    if(c >= '0' && c <= '9') return 1;
    return 0;
}

float to_digit(char c) {
    return 1.0 * (c - '0');
}

int is_operator(char c) {
    return !is_digit(c);
}

float operation(float nb1, char c, float nb2) {
    float s;
    if(c == '+') s = nb1 + nb2;
    else if(c == '-') s = nb1 - nb2;
    else if(c == '*') s = nb1 * nb2;
    else if(c == '/') s = nb1 / nb2;
    else if(c == '^') s = pow(nb1, nb2);
    else if(c == '#') s = -1 * nb2;
    return s;
}

ExpressionTree Build(char *postfix)
{
    stack s = CreateStack();
    ExpressionTree zero = NULL, one, two;
    while(*postfix != '\0') {
        if(is_digit(*postfix)) {
            zero = Construct(*postfix, NULL, NULL);
            Push(&s, zero);
        }
        else if(*postfix == '#') {
            Top(s, &one);
            Pop(&s);
            zero = Construct(*postfix, NULL, one);
            Push(&s, zero);
        }
        else {
            Top(s, &two);
            Pop(&s);
            Top(s, &one);
            Pop(&s);
            zero = Construct(*postfix, one, two);
            Push(&s, zero);
        }
        postfix += 1;
    }
    return zero;
}


float result(ExpressionTree B)
{
    if(B == NULL) return 0.0;
    if(is_digit(B->data)) return to_digit(B->data);
    return operation(result(B->left), B->data, result(B->right));
}

void main() {
    ExpressionTree T = Build("623+-382/+*2^3+");
    printf("%lf\n", result(T));
    //test cases:
    // 623+-382/+*2^3+
    // 723+##2^-
    // 72+##2^
}