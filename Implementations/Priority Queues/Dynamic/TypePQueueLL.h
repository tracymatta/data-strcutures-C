typedef int element;

typedef struct node {
    element data;
    int priority;
    struct node *next;
} node;

typedef struct {
    node *front;
} pqueue;