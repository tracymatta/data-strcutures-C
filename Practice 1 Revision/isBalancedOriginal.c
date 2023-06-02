#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isBalancedHelper(char *str, int counter) {
    if(counter == -1) return 0;
    if(*str == '\0') {
        if(counter != 0) return 0;
        else return 1;
    }
    if(*str == ',') {
        if(counter != 0) return 0;
    }
    if(*str == '(') return isBalancedHelper(str+1, counter+1);
    else if(*str == ')') return isBalancedHelper(str+1, counter-1);
    return isBalancedHelper(str+1, counter);
}

int isBalanced(char *str) {
    return isBalancedHelper(str, 0);
}

void main()
{
    char *s =(char*)malloc(sizeof(char)*5);
    s = "((()))";
    printf("%d",isBalanced(s)); 
}