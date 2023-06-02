#include <stdio.h>
#include <math.h>

int countReversalsHelper(char *str, int count, int reversals) {
    if(*str == '\0') {
        if(count%2 != 0) return -1;
        else return abs(count/2)+reversals;
    }
    if(*str == '(') return countReversalsHelper(str+1, count+1, reversals);
    else{
        if(count == 0) {
            count+=1;
            reversals++;
        }
        else{
            count-=1;
        }
        return countReversalsHelper(str+1, count, reversals);
    } 
}

int countReversals(char *str) {
    return countReversalsHelper(str, 0, 0);
}

void main() {
    char str[] = "(((((((((())))))))))))))()";
    printf("%d", countReversals(str));
}