#include "TypePQueueLL.h"

extern pqueue CreatePQueue();
extern int isEmptyPQueue(pqueue p);
extern int EnqueuePQueue(pqueue *p, element e, int priority);
extern int Front(pqueue p, element *e);
extern int DequeuePQueue(pqueue *p);
extern int DeleteValue(pqueue *p, element e);
extern void UpdatePriority(pqueue *p, element e, int priority);
extern void printPQueue(pqueue p);