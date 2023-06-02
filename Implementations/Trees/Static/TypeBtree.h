#define N 20

typedef int element;

typedef struct {
    element root;
    int leftSubtree, rightSubtree;
} node;

typedef struct {
    node data[N];
    int rootIndex;
} Btree;