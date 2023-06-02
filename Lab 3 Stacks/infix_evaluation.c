#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "..\Implementations\Stacks\Static\Stack.h"

int stackable(char o1, char o2)
{
    switch (o1) {
        case '(': return 1;
        case '+': 
        case '-': return (o2 == '(');
        case '#': return (o2 != '#');
        case '*':
        case '/': return (o2 == '(' || o2 == '+' || o2 == '-');
        case '^': return (o2 != '#' && o2 != '^');
        case ')': return (o2 == '(');
    }
    return 0;
}

float result(float first, float second, char oper) {
    switch(oper) {
        case '+': return first + second;
        case '-': return first - second;
        case '*': return first * second;
        case '/': return first / second;
        case '^': return pow(first, second);
        case '#': return -1 * second;
    }
    return 0.0;
}

int isOperator(char str) {
    switch(str) {
        case '+': 
        case '-': 
        case '*': 
        case '/': 
        case '^': 
        case '#': return 1;
    }
    return 0;
}

float infix_evaluation(char *infix) {
    if(*infix == '\0') return 0.0;
    char *postfix = infix;
    char *toIteratePostfix = infix;
    stack eval = CreateStack();
    while(*infix != '\0') {
        if((*infix == '(' || isOperator(*infix)) && isEmptyStack(eval)) {
            Push(&eval, *infix);
        }
        else if(!isEmptyStack(eval) && (*infix == '(' || isOperator(*infix))) {
            element h;
            Top(eval, &h);
            if(stackable(*infix, h)) Push(&eval, *infix);
            else {
                Pop(&eval);
                *toIteratePostfix = h;
                toIteratePostfix += 1;
                Push(&eval, *infix);
            }
        }
        else if(*infix == ')') {
            element e;
            Top(eval, &e);
            Pop(&eval);
            while(e != '(') {
                *toIteratePostfix = e;
                toIteratePostfix = toIteratePostfix + 1;
                Top(eval, &e);
                Pop(&eval);
            }
        }
        else if(*infix != ' ') {
            *toIteratePostfix = *infix;
            toIteratePostfix = toIteratePostfix + 1;
        }
        infix = infix + 1;
    }
    while(!isEmptyStack(eval)) {
        element k;
        Top(eval, &k);
        Pop(&eval);
        *toIteratePostfix = k;
        toIteratePostfix = toIteratePostfix + 1;
    }
    *toIteratePostfix = '\0';
    printf("%s\n", postfix);
    while(*postfix != '\0') {
        if(isOperator(*postfix)) {
            element first, second;
            Top(eval, &second);
            Pop(&eval);
            Top(eval, &first);
            Pop(&eval);
            if(*postfix == '#') Push(&eval, first);
            Push(&eval, result(first, second, *postfix));
        }
        else {
            Push(&eval, *postfix -'0');
        }
        postfix = postfix + 1;
    }
    if(isEmptyStack(eval)) return 0.0;
    element answer;
    Top(eval, &answer);
    return answer;
}


void main() {
    char a[30] = "((6-(2+3))*(3+8/2))^2+3";
    printf("%f", infix_evaluation(a));
    // ((6-(2+3))*(3+8/2))^2+3
    // 7-(#(#(2+3)))^2
    // ((((1))))
    // ((4-1)/(#1-4)+5)*(2-1)-3
}