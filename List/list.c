#include "list.h"

// Add
void ListPushFirst(struct SList** ppList, int value)
{
	printf("=== ListPushFirst value: %i ===\n", value);

	struct SList *pList = *ppList;
	// Init new list
	struct SList *pListNew = (struct SList*)malloc(sizeof(struct SList));
	pListNew->value = value;
	pListNew->pNext = pList;
	pListNew->pPrev = NULL;

	if (!pList)
	{
		*ppList = pListNew;
		return;
	}

	// Init list
	pList->pPrev = pListNew;
	// Set pointer on first element
	*ppList = pListNew;
}

void ListPushLast(struct SList** ppList, int value)
{
	printf("=== ListPushLast value: %i ===\n", value);

	struct SList *pList = *ppList;
	// Init new list
	struct SList *pListNew = (struct SList*)malloc(sizeof(struct SList));
	pListNew->value = value;
	pListNew->pNext = NULL;
	pListNew->pPrev = NULL;

	if (!pList)
	{
		*ppList = pListNew;
		return;
	}

	while (pList->pNext)
	{
		pList = pList->pNext;
	}

	// Init new list
	pListNew->pNext = NULL;
	pListNew->pPrev = pList;
	// Init list
	pList->pNext = pListNew;
}

void ListPushByIndex(struct SList** ppList, const int n, const int value)
{
	printf("=== ListPushByIndex n: %i value: %i ===\n", n, value);

	struct SList *pList = *ppList;
	// Init new list
	struct SList *pListNew = (struct SList*)malloc(sizeof(struct SList));
	pListNew->value = value;
	pListNew->pNext = NULL;
	pListNew->pPrev = NULL;

	if (!pList)
	{
		*ppList = pListNew;
		return;
	}

	int iIndex = 0;
	bool bFound = 0;
	while (pList->pNext)
	{
		if (iIndex == n)
		{
			bFound = 1;
			break;
		}

		pList = pList->pNext;
		iIndex++;
	}

	if (bFound)
	{
		// Init new list
		pListNew->pNext = pList->pNext;
		pListNew->pPrev = pList;
		// Init list
		if (pList->pNext)
			pList->pNext->pPrev = pListNew;
		
		pList->pNext = pListNew;
	}
	else
	{
		// Init new list
		pListNew->pNext = NULL;
		pListNew->pPrev = pList;
		// Init list
		pList->pNext = pListNew;
	}
}
// Get
const int ListPopFirst(struct SList** ppList)
{
	printf("=== ListPopFirst ===\n");

	struct SList *pList = *ppList;
	// if List is empty
	if (!pList)
	{
		return -1;
	}

	int value = pList->value;
	*ppList = pList->pNext;
	if (pList->pNext)
		pList->pNext->pPrev = NULL;
	else
		*ppList = NULL; // if list consist only one element

	free(pList);
	return value;
}

const int ListPopLast(struct SList** ppList)
{
	printf("=== ListPopLast ===\n");

	struct SList *pList = *ppList;
	if (!pList)
	{
		return -1;
	}

	while (pList->pNext)
	{
		pList = pList->pNext;
	}

	int value = pList->value;
	if (pList->pPrev)
		pList->pPrev->pNext = NULL;
	else
		*ppList = NULL; // if list consist only one element

	free(pList);
	return value;
}

const int ListPopByIndex(struct SList** ppList, const int n)
{
	printf("=== ListPopByIndex n: %i ===\n", n);

	struct SList *pList = *ppList;
	if (!pList)
	{
		return -1;
	}

	int iIndex = 0;
	bool bFound = 0;
	while (pList)
	{
		if (iIndex == n)
		{
			bFound = 1;
			break;
		}

		if (!pList->pNext)
			break;

		pList = pList->pNext;
		iIndex++;
	}

	if (bFound)
	{
		if (pList->pNext)
		{
			pList->pNext->pPrev = pList->pPrev;
		}

		if (pList->pPrev)
		{
			pList->pPrev->pNext = pList->pNext;
		}
		else
		{
			*ppList = pList->pNext;
		}

		int value = pList->value;
		free(pList);
		return value;
	}
	else
	{
		return -2; // if List size < n
	}
}
// Print
void ListPrint(struct SList* pList)
{
	int iIndex = 0;
	while (pList)
	{
		printf("List \tid: %i\tvalue: %i\n", iIndex, pList->value);
		pList = pList->pNext;
		iIndex++;
	}
}