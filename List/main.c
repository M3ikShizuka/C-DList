#include "main.h"
#include "list.h"

int main()
{
	system("color 0A");

	//// PUSH
	// Init lsit
	struct SList *pList = (struct SList*)malloc(sizeof(struct SList));
		// = NULL; 
		// = (struct SList*)malloc(sizeof(struct SList));

	// for tests when pList is empty
	if (pList)
	{
		pList->value = 2;
		pList->pNext = NULL;
		pList->pPrev = NULL;
		printf("--- pList init value: %i ---\n", pList->value);
	}

	ListPrint(pList);

	// Add front
	ListPushFirst(&pList, 1);
	ListPrint(pList);
	ListPushLast(&pList, 4);
	ListPrint(pList);
	ListPushByIndex(&pList, 1, 3);

	//// Print all
	ListPrint(pList);

	//// POP
	ListPopFirst(&pList);
	ListPrint(pList);
	ListPopLast(&pList);
	ListPrint(pList);
	ListPopByIndex(&pList, 1);
	ListPrint(pList);
	ListPopLast(&pList);
	ListPrint(pList);

	system("pause");

	return 0;
}