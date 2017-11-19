#pragma once
#include "head.h"

typedef int bool;

typedef struct SList
{
	int value;
	struct SList *pNext;
	struct SList *pPrev; // previous
};

// Push
void ListPushFirst(struct SList** ppList, int value);
void ListPushLast(struct SList** ppList, int value);
void ListPushByIndex(struct SList** ppList, const int n, const int value);
// Pop
const int ListPopFirst(struct SList** ppList);
const int ListPopLast(struct SList** ppList);
const int ListPopByIndex(struct SList** ppList, const int n);
// Print
void ListPrint(struct SList* pList);