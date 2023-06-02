#include <stdio.h>
#include <string.h>

#define P 5

#define M 10

typedef char element[20];

typedef struct {
    element data;
    int link;
} entry;

typedef entry hashtable[M];

int hash_function(char *s) {
    return ((int) *s) % P;
}

void create_table(hashtable h) {
    for(int i = 0; i < M; i++) h[i].link = -2;
}

int empty(hashtable h, int v) {
    return h[v].link == -2;
}

int search_coalesced(hashtable T, element e)
{
    int h = hash_function(e);
    if(empty(T, h)) return 0;
    while(h != -1) {
        if(strcmp(T[h].data , e) == 0) return 1;
        h = T[h].link;
    }
    return 0;
}

int delete_coalesced(hashtable T,  element e)
{
    int h = hash_function(e);
    if(empty(T, h)) return 0;
    if(strcmp(T[h].data, e) == 0) {
        if(T[h].link == -1) T[h].link = -2;
        else {
            int d = T[h].link;
            strcpy(T[h].data, T[d].data);
            T[h].link = T[d].link;
            T[d].link = -2;
        }
    }
    else {
        int v = h;
        while(h != -1) {
            if(strcmp(T[h].data, e) == 0) break;
            v = h;
            h = T[h].link;
        }
        if(h == -1) return 0;
        else {
            T[v].link = T[h].link;
            T[h].link = -2;
        }
    }
    return 1;
}

int add_coalesced(hashtable T, int m, element e, int p)
{
	int h = hash_function(e);
	if(empty(T, h)) {
	    strcpy(T[h].data, e);
	    T[h].link = -1;
	}
	else {
	    while(T[h].link != -1) {
	        if(strcmp(T[h].data, e) == 0) return 0;
	        h = T[h].link;
	    }
        int j;
        for(j = m - 1; j >= p; j--) if(empty(T, j)) break;
        if(j < p) return 0;
        strcpy(T[j].data, e);
        T[j].link = -1;
        T[h].link = j;
	}
	return 1;
}

void printHash(hashtable h) {
    for(int i = 0; i < M; i++) {
        printf("%d : ", i);
        if(h[i].link != -2) printf("data=%s , link=%d", h[i].data, h[i].link);
        printf("\n");
    }
    printf("\n\n\n\n");
}

void test_insert(hashtable h) {
    add_coalesced(h, M, "a", P);
    add_coalesced(h, M, "aa", P);
    add_coalesced(h, M, "aaa", P);
    add_coalesced(h, M, "a", P);
}

void test_belong(hashtable h) {
    if(search_coalesced(h, "aaa")) printf("'aaa' Found\n");
    else printf("'aaa' Not Found\n");
    printf("\n\n\n\n");
}

void test_delete(hashtable h) {
    delete_coalesced(h, "a");
}

void main() {
    hashtable h;
    create_table(h);
    test_insert(h);
    printHash(h);
    test_belong(h);
    test_delete(h);
    printHash(h);
}