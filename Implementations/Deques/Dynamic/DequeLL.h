#include <stdio.h>
#include "TypeDequeLL.h"

extern deque CreateDeque();
extern int isEmptyDeque(deque d);
extern int isFullDeque(deque d);
extern int EnqueueFront(deque *d, element e);
extern int DequeueFront(deque *d);
extern int Front(deque d, element *e);
extern int EnqueueRear(deque *d, element e);
extern int DequeueRear(deque *d);
extern int Rear(deque d, element *e);
extern void printDeque(deque d);
