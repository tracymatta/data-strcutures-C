#define N 10

typedef int element;

typedef struct Btree {
    element data;
    struct Btree *left, *right;
} *Btree;
