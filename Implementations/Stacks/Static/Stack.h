#include "TypeStack.h"

stack CreateStack();
extern int isEmptyStack(stack p);
extern int isFullStack(stack p);
extern int Push(stack *p, element e);
extern int Pop(stack *p);
extern int Top(stack p, element *e);