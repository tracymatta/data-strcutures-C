#define N 10

typedef int element;

typedef struct Btree {
    element data;
    struct Btree *left, *right;
} *Btree;

typedef struct {
    Btree data[N];
    int top;
} stack; 

typedef struct {
    Btree data[N];
    int front, rear;
} queue;