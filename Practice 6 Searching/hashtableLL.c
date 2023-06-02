#include <stdio.h>
#include <stdlib.h>

#define M 20

typedef int element;

typedef struct node {
	element data; 
	struct node *next;
} *list;

typedef list hashtable[M];

void create_table(hashtable h) {
    for(int i = 0; i < M; i++) h[i] = NULL;
}

int HF(int n) {
    return n % M;
}

int insert_list(list *l, element nb) {
    if(*l == NULL)
    {
        *l = (list) malloc (sizeof(struct node));
        if(!(*l)) return 0;
        (*l)->data = nb;
        (*l)->next = NULL;
        return 1;
    }
    return insert_list(&((*l)->next), nb);
}

int insert(hashtable h, element nb) {
	int hf = HF(nb);
	return insert_list(&h[hf], nb);
}

void printLL(list toPrint) {
    while(toPrint != NULL) {
        printf("%d ", toPrint->data);
        toPrint = toPrint->next;
    }
}

void printHash(hashtable h) {
    for(int i = 0; i < M; i++) {
        printf("Index %d : ", i);
        printLL(h[i]);
        printf("\n");
    }
}

void test_insert(hashtable h) {
    insert(h, 10);
    insert(h, 100);
    insert(h, 30);
    insert(h, 50);
}

void main() {
    hashtable h;
    create_table(h);
    test_insert(h);
    printHash(h);
}
