#include <stdio.h>

#define N 11

typedef int element;

typedef struct {
    element T1[N];
    element T2[N];
    int size;
 } Hash;

int H1(int k, int size) {
    return k % size;
}

int H2(int k, int size) {
    return (k / size) % size;
}

int belong(Hash h, element e)
{
	 if(*(h.T1 + H1(e, h.size)) == e) return 1;
	 else if(*(h.T2 + H2(e, h.size)) == e) return 1;
	 return 0;
}

int deleteh(Hash *h, element e)
{
     int h1 = H1(e, h->size), h2 = H2(e, h->size);
	 if(*(h->T1 + h1) == e) *(h->T1 + h1) = -1;
	 else if(*(h->T2 + h2) == e) *(h->T2 + h2) = -1;
	 else return 0;
	 return 1;
}

int insertHelper(Hash *h, element e, int counter, int flag, element first) {
    if(counter == 2*h->size) return 0;
    int h1 = H1(e, h->size), h2 = H2(e, h->size);
    if(flag == 1) {
        int i = *(h->T1 + h1);
        *(h->T1 + h1) = e;
        if(i < 0) return 1;
        else return insertHelper(h, i, counter + 1, 2, first);
    }
    else {
        int i = *(h->T2 + h2);
        *(h->T2 + h2) = e;
        if(i < 0) return 1;
        else return insertHelper(h, i, counter + 1, 1, first);
    }
    return 1;
}

int insert(Hash *h, element e)
{
    if(belong(*h, e) == 1) return 0;
	return insertHelper(h, e, 1, 1, e);
}

void printHash(Hash h) {
    for(int i = 0; i < N; i++) {
        printf("%d : T1=  ", i);
        if(h.T1[i] > 0) printf("%d", h.T1[i]);
        else printf("  ");
        printf("  T2=  ");
        if(h.T2[i] > 0) printf("%d", h.T2[i]);
        printf("\n");
    }
    printf("\n\n\n\n");
}

void test_insert(Hash *h) {
    insert(h, 20);
    insert(h, 50);
    insert(h, 53);
    insert(h, 75);
    insert(h, 72);
}

void test_belong(Hash h) {
    if(belong(h, 50)) printf("50 in the table\n");
    else printf("50 not in the table\n");
    if(belong(h, 20)) printf("20 in the table\n");
    else printf("20 not in the table\n");
    if(belong(h, 33)) printf("33 in the table\n");
    else printf("33 not in the table\n");
    printf("\n\n\n\n");
}

void test_delete(Hash *h) {
    deleteh(h, 75);
    deleteh(h, 44);
    deleteh(h, 20);
    deleteh(h, 72);
}

void main() {
    Hash h;
    h.size = N;
    for(int i = 0; i < N; i++) h.T1[i] = h.T2[i] = 0;
    test_insert(&h);
    printHash(h);
    test_belong(h);
    test_delete(&h);
    printHash(h);
}