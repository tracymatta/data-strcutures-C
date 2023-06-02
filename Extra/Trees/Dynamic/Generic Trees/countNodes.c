#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;

typedef struct node {
    element data;
    struct node *firstChild, *nextSibling;
} *GenericTree;

GenericTree CreateBtree() {
    return NULL;
}

int isEmptyBtree(GenericTree G) {
    return G == NULL;
}

GenericTree Construct(element e, GenericTree firstChild, GenericTree nextSibling) {
    GenericTree created = (GenericTree)malloc(sizeof(GenericTree));
    if(!created) return 0;
    created->data = e;
    created->firstChild = firstChild;
    created->nextSibling = nextSibling;
    return created;
}

int countNodes (GenericTree G) {
    if(G == NULL) return 0;
    if(G->firstChild == NULL && G->nextSibling == NULL) return 1;
    return 1 + countNodes(G->firstChild) + countNodes(G->nextSibling);
}

void main() {
    GenericTree Five = Construct(5, NULL, NULL);
    GenericTree Seven = Construct(7, NULL, NULL);
    GenericTree Four = Construct(4, Seven, Five);
    GenericTree Six = Construct(6, NULL, NULL);
    GenericTree Three = Construct(3, Six, Four);
    GenericTree Two = Construct(2, NULL, Three);
    GenericTree One = Construct(1, Two, NULL);
    printf("%d\n", countNodes(One));
}