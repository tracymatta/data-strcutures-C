#include "TypeHeap.h"

extern Heap CreateHeap(int capacity, int heap_type);
extern int Parent(Heap h, int i);
extern int LeftChild(Heap h, int i);
extern int RightChild(Heap h, int i);
extern int GetMaximum(Heap h);
extern void PercolateDown(Heap *h, int i);
extern int DeleteMax(Heap *h);
extern int Insert(Heap *h, int data);
extern void ResizeHeap(Heap *h);
extern void DestroyHeap(Heap *h);
extern void BuildHeap(Heap *h, int A[], int n);