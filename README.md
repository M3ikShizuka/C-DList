# C-List
typedef int bool;<br/>
<br/>
typedef struct SList<br/>
{<br/>
  int value;<br/>
  struct SList *pNext;<br/>
  struct SList *pPrev; // previous<br/>
 };<br/>
  <br/>
// Push<br/>
void ListPushFirst(struct SList** ppList, int value);<br/>
void ListPushLast(struct SList** ppList, int value);<br/>
void ListPushByIndex(struct SList** ppList, const int n, const int value);<br/>
// Pop<br/>
const int ListPopFirst(struct SList** ppList);<br/>
const int ListPopLast(struct SList** ppList);<br/>
const int ListPopByIndex(struct SList** ppList, const int n);<br/>
// Print<br/>
void ListPrint(struct SList* pList);<br/>
