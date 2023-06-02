#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"

Btree CreateBtree() {
    return NULL;
}

Btree Construct(element e) {
    Btree created = (Btree)malloc(sizeof(Btree));
    if(!created) return 0;
    created->data = e;
    created->left = created;
    created->right = created;
    return created;
}

