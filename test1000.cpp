#include "Stack.h"

void StackInit(Stack* pst) 
{
	assert(pst);
	
	pst->arr = NULL;
	pst->top = pst->lim = 0;
}

void StackDest(Stack* pst)
{
	assert(pst);

	free(pst->arr);
	pst->arr = NULL;
	pst->lim = pst->top = 0;
}

bool StackIsEmpty(Stack* pst)
{
	assert(pst);

	return pst->top == 0;
}

void StackCheckLimit(Stack* pst) 
{
	// 檢視是否需要增容
	if (pst->lim == pst->top) 
	{
		int new_lim = pst->lim == 0 ? 4 : 2 * pst->lim;
		StackDT* new_arr = (StackDT*)realloc(pst->arr, sizeof(StackDT) * new_lim);
		// 防止動態記憶體開闢失敗
		if (new_arr == NULL)
		{
			printf("malloc failed!\n");
			exit(-1);
		}
		// 更新數據
		pst->lim = new_lim;
		pst->arr = new_arr;
	}
}

void StackPush(Stack* pst, StackDT x)
{
	assert(pst);

	// 檢視是否需要增容
	StackCheckLimit(pst);  
	
	// 將數據入棧（置於棧頂）
	pst->arr[pst->top] = x;
	pst->top++;
}

void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackIsEmpty(pst));   // 防止棧内沒有元素的情況下出棧導致BUG

	pst->top--;
}

StackDT StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackIsEmpty(pst));

	return pst->arr[pst->top - 1];
}

int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}




