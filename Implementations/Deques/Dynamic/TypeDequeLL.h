typedef int element;

typedef struct node {
    element data;
    struct node *next;
} node;

typedef struct {
    node *front, *rear;
} deque;