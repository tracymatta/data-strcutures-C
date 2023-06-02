#include "TypeBST.h"

extern BST CreateBST();
extern int isEmptyBST(BST B);
extern BST Construct(element e, BST L, BST R);
extern int Root(BST B, element *e);
extern int Right(BST B, BST *R);
extern int Left(BST B, BST *L);

extern stack CreateStack();
extern int isEmptyStack(stack p);
extern int isFullStack(stack p);
extern int Push(stack *p, BST e);
extern int Pop(stack *p);
extern int Top(stack p, BST *e);
extern void printStack(stack p);

extern queue CreateQueue();
extern int EnQueue(queue *q, BST e);
extern int DeQueue(queue *q);
extern int Front(queue q, BST *e);
extern int isEmptyQueue(queue q);
extern int isFullQueue(queue q);
extern void printQueue(queue q);