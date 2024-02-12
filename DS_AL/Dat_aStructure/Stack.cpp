#include <iostream>
#include <vector>
#define TRUE	1
#define FALSE	0
#define STACK_LEN	100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack) 
{
	pstack->topIndex = -1;
}
int SIsEmpty(Stack* pstack) 
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) 
{
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}
Data SPop(Stack* pstack) 
{
	if (SIsEmpty(pstack)) 
	{
		//오류
		exit(-1);
	}

	return pstack->stackArr[--pstack->topIndex];

}
Data SPeek(Stack* pstack) 
{
	if (SIsEmpty(pstack))
	{
		//오류
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}