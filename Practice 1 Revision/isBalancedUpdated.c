#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isBalancedH(char *str, int c, int *i) { 
    if(*(str + *i) == '(') {
        *i = *i+1;
        int result = isBalancedH(str, 1, i);
        if(result == 0) return 0;
        else {
            if(*(str+*i+1) == '\0') {
                if(c == 0) return 1;
                else return 0;
            }
            *i = *i+1;
            return isBalancedH(str, c, i);
        }  
    }  
    if (*(str + *i) == '{') {
        *i = *i+1;
        int result = isBalancedH( str, 2, i);
        if(result == 0) return 0;
        else {
            if(*(str+*i+1) == '\0') {
                if(c == 0) return 1;
                else return 0;
            }
            *i = *i+1;
            return isBalancedH(str, c, i);
        }
    }
    if (*(str + *i) == '[') {
        *i = *i+1;
        int result = isBalancedH( str, 3, i);
        if(result == 0) return 0;
        else {
            if(*(str+*i+1) == '\0') {
                if(c == 0) return 1;
                else return 0;
            }
            *i = *i+1;
            return isBalancedH(str, c, i);
        }
    }
    if (*(str + *i) == ')') {
        if (c == 1) return 1;
        else return 0;   
    } 
    if (*(str + *i) == '}') {
        if (c == 2) return 1;
        else return 0;
    }
    if (*(str + *i) == ']') {
        if (c == 3) return 1;
        else return 0;
    }
    return 0;
}
int isBalanced(char *str) {
    int i = 0;
    return isBalancedH(str, 0, &i);
}

void main() {
    char *s = (char*)malloc(sizeof(char)*8);
    s = "({}[])";
    printf("%d",isBalanced(s)); 
}
