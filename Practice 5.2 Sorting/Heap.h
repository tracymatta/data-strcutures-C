#include "TypeHeap.h"

extern Heap CreateHeap(int capacity, int heap_type);
extern int isEmptyHeap(Heap h);
extern int isFullHeap(Heap h);
extern int Parent(Heap h, int i);
extern int LeftChild(Heap h, int i);
extern int RightChild(Heap h, int i);
extern int GetMaximum(Heap h, element *e);
extern void PercolateDown(Heap *h, int i);
extern int DeleteMax(Heap *h);
extern int Insert(Heap *h, element data);
extern void ResizeHeap(Heap *h);
extern void DestroyHeap(Heap *h);