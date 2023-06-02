#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../../Implementations/Trees/Dynamic/Btree.h"

Btree CreateBtree() {
    return NULL;
}

int isEmptyBtree(Btree B) {
    return B == NULL;
}

Btree Construct(element e, Btree L, Btree R) {
    Btree created = (Btree)malloc(sizeof(Btree));
    if(!created) return 0;
    created->data = e;
    created->left = L;
    created->right = R;
    return created;
}

int Root(Btree B, element *e) {
    if(isEmptyBtree(B)) return 0;
    *e = B->data;
    return 1;
}

int Right(Btree B, Btree *R) {
    if(isEmptyBtree(B)) return 0;
    *R = B->right;
    return 1;
}

int Left(Btree B, Btree *L) {
    if(isEmptyBtree(B)) return 0;
    *L = B->left;
    return 1;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int height(Btree B) {
    if(B == NULL) return 0;
    return 1 + max(height(B->left), height(B->right));
}

int length(int n) {
    int len = 0;
    do {
        n = n / 10;
        len += 1;
    } while(n != 0);
    return len;
}

char *formatSpaces(int n) {
    char *spaces = (char*) malloc(sizeof(char) * (n + 1));
    spaces[n] = '\0';
    n -= 1;
    for( ; n >= 0; n--) spaces[n] = ' ';
    return spaces;
}

char *formatToString(int n) {
    int len = length(n);
    char *str = (char*) malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    do {
        str[len - 1] = (n % 10) + '0';
        len -= 1;
        n = n / 10;
    } while(n != 0);
    return str;
}

Btree** generateArrayOfRows(Btree B, int *maxWidth)
{
    int h = height(B);
    Btree **nodes = (Btree**) malloc (sizeof(Btree*) * h);
    if(B == NULL) return nodes;
    *nodes = (Btree*) malloc (sizeof(Btree)); 
    **nodes = B;
    *maxWidth = 1;
    int nbOfNodesInCurrLevel;
    for(int currentLevel = 0; currentLevel < h; currentLevel++) {
        *(nodes + currentLevel + 1) = (Btree*) malloc (sizeof(Btree) * pow(2, currentLevel + 1));
        nbOfNodesInCurrLevel = pow(2, currentLevel);
        for(int currentCount = 0; currentCount < nbOfNodesInCurrLevel; currentCount++) {
            if(currentLevel == h - 1) continue;
            B = nodes[currentLevel][currentCount];
            if(B != NULL) {
                if(length(B->data) > *maxWidth) *maxWidth = length(B->data);
                nodes[currentLevel + 1][2 * currentCount] = B->left;
                nodes[currentLevel + 1][2 * currentCount + 1] = B->right;
            }
            else {
                nodes[currentLevel + 1][2 * currentCount] = NULL;
                nodes[currentLevel + 1][2 * currentCount + 1] = NULL;
            }
        }
    }
    return nodes;
}

char **formatArrayIntoString(Btree **nodes, int len, int width, int *lenOfRes) {
    char **res = (char**) malloc(sizeof(char*) * 100);
    int resIndex = 0;
    if(width % 2 == 0) width += 1;
    if(width < 3) width = 3;
    int nbOfNodesInCurrLevel, indentation = 0;
    for(int size = len - 1; size >= 0; size--) {
        *(res + resIndex) = (char*) malloc(sizeof(char) * 100);
        res[resIndex][0] = '\0';
        int space = (1 << (len - size - 1)) * (width + 1) / 2 - 1;
        nbOfNodesInCurrLevel = pow(2, size);
        for(int i = 0; i < nbOfNodesInCurrLevel; i++) {
            strcat(res[resIndex], formatSpaces(i > 0 ? indentation * 2 + 1 : indentation));
            if(nodes[size][i] != NULL) {
                int data = nodes[size][i]->data;
                int longPadding = width - length(data);
                int shortPadding = longPadding / 2;
                longPadding -= shortPadding;
                strcat(res[resIndex], formatSpaces(i % 2 == 1 ? shortPadding : longPadding));
                strcat(res[resIndex], formatToString(data));
                strcat(res[resIndex], formatSpaces(i % 2 == 1 ? longPadding : shortPadding));

            }
            else {
                strcat(res[resIndex], formatSpaces(width));
            }
        }
        if(nbOfNodesInCurrLevel == 1) break;
        resIndex += 1;
        int leftSpace = space + 1, rightSpace = space - 1;
        for(int i = 0; i < space; i++) {
            *(res + resIndex) = (char*) malloc(sizeof(char) * 100);
            res[resIndex][0] = '\0';
            for(int j = 0; j < nbOfNodesInCurrLevel; j++) {
                if(j % 2 == 0) {
                    strcat(res[resIndex], formatSpaces(j > 0 ? leftSpace * 2 + 1 : leftSpace));
                    strcat(res[resIndex], nodes[size][j] != NULL ? "/" : " ");
                    strcat(res[resIndex], formatSpaces(rightSpace + 1));
                }
                else {
                    strcat(res[resIndex], formatSpaces(rightSpace));
                    strcat(res[resIndex], nodes[size][j] != NULL ? "\\" : " ");
                }
            }
            resIndex += 1;
            leftSpace += 1;
            rightSpace -= 1;
        }
        indentation += space + 1;
    }
    *lenOfRes = resIndex;
    return res;
}

void printBtree(Btree B) {
    printf("\n\n");
    int width;
    Btree **arrayOfB = generateArrayOfRows(B, &width);
    int lenOfRes;
    char **result = formatArrayIntoString(arrayOfB, height(B), width, &lenOfRes);
    for( ; lenOfRes >= 0; lenOfRes--) printf("%s\n", result[lenOfRes]);
    printf("\n\n");
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

int Push(stack *p, Btree e) {
    if(isFullStack(*p)) return 0;
    p->data[++p->top] = e;
    return 1;
}

int Pop(stack *p) {
    if(isEmptyStack(*p)) return 0;
    p->top--;
    return 1;
}

int Top(stack p, Btree *e) {
    if(isEmptyStack(p)) return 0;
    *e = p.data[p.top];
    return 1;
}

void printStack(stack p) {
    Btree e;
    while(!isEmptyStack(p)) {
        Top(p, &e);
        printf("%d ", e);
        Pop(&p);
    }
    printf("\n");
}

queue CreateQueue() {
    queue q;
    q.front = 1;
    q.rear = 0;
    return q;
}

int isEmptyQueue(queue q) {
    return (q.front == (q.rear + 1) % N);
}

int isFullQueue(queue q) {
    return (q.front == (q.rear + 2) % N);
}

int EnQueue(queue *q, Btree e) {
    if(isFullQueue(*q)) return 0;
    q->rear = (q->rear + 1) % N;
    q->data[q->rear] = e;
    return 1; 
}

int DeQueue(queue *q) {
    if(isEmptyQueue(*q)) return 0;
    q->front = (q->front + 1) % N;
    return 1;
}

int Front(queue q, Btree *e) {
    if(isEmptyQueue(q)) return 0;
    *e = q.data[q.front];
    return 1;
}

void printQueue(queue q) {
    Btree e;
    while(!isEmptyQueue(q)) {
        Front(q, &e);
        printf("%d ", e);
        DeQueue(&q);
    }
    printf("\n");
}