typedef int element;

#define N 10

typedef struct node {
    element data;
    struct node *left, *right;
} *BST;

typedef struct {
    BST data[N];
    int top;
} stack; 

typedef struct {
    BST data[N];
    int front, rear;
} queue;