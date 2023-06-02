#define N 10

typedef struct {
    int counter;
    int data;
} element;

typedef struct {
    element *array;
    int count;
    int capacity;
    int heap_type;
} *Heap;