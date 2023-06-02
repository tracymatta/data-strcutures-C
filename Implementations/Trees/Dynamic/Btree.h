#include "TypeBtree.h"

extern Btree CreateBtree();
extern int isEmptyBtree(Btree B);
extern Btree Construct(element e, Btree L, Btree R);
extern int Root(Btree B, element *e);
extern int Right(Btree B, Btree *R);
extern int Left(Btree B, Btree *L);
extern void printBtree(Btree B);

extern stack CreateStack();
extern int isEmptyStack(stack p);
extern int isFullStack(stack p);
extern int Push(stack *p, Btree e);
extern int Pop(stack *p);
extern int Top(stack p, Btree *e);
extern void printStack(stack p);

extern queue CreateQueue();
extern int EnQueue(queue *q, Btree e);
extern int DeQueue(queue *q);
extern int Front(queue q, Btree *e);
extern int isEmptyQueue(queue q);
extern int isFullQueue(queue q);
extern void printQueue(queue q);