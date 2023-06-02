#include <stdio.h>
#include <string.h>

#define M 10

typedef char element[20];

typedef struct {
    element data;
    int link;
} entry;

typedef entry hashtable[M];

int hash_function(char *s) {
    return ((int) *s) % M;
}

void create_table(hashtable h) {
    for(int i = 0; i < M; i++) h[i].link = -2;
}

int empty(hashtable h, int v) {
    return h[v].link == -2;
}

int add_coalesced(hashtable T, int m, element e) {
	int h = hash_function(e), k = -1, v = -1;
	if(empty(T, h)) {
		strcpy(T[h].data, e);
		T[h].link = -1;
		return 1;
	}
	else if(hash_function(T[h].data) != hash_function(e)) {
		v = h;
		element l;
		strcpy(l, T[h].data);
		strcpy(T[h].data, e);
		e = l;
		k = T[h].link;
		T[h].link = -1;
		h = hash_function(e);
	}
	int j;
	for(j = m - 1; j >= 0; j--) if(empty(T, j)) break;
	if(j < 0) return 0;
	while(T[h].link != v) {
		if(strcmp(T[h].data, e) == 0) return 0;
		h = T[h].link;
	}
	T[h].link = j;
	T[j].link = k;
	strcpy(T[j].data, e);
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
    add_coalesced(h, M, "a");
    add_coalesced(h, M, "aa");
    add_coalesced(h, M, "aaa");
    add_coalesced(h, M, "a");
}

void main() {
    hashtable h;
    create_table(h);
    test_insert(h);
    printHash(h);
}