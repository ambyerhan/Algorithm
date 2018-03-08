
# include <stdio.h>
# include "List.h"

ListNode* createEmptyList()
{
	ListNode *pHead = new ListNode();
	pHead->data = -1;
	pHead->next = NULL;

	return pHead;
}

ListNode* createList(ElemType *a, int len)
{
	ListNode *pHead = new ListNode();
	pHead->data = -1;
	pHead->next = NULL;

	ListNode *pWork = pHead;
	for (int i = 0; i < len; ++i)
	{
		ListNode *node = new ListNode();
		node->data = a[i];
		node->next = NULL;

		pWork->next = node;
		pWork = pWork->next;
	}

	return pHead;
}


ListNode* createListWithHeadPointer(ElemType *a, int len)
{
	if (!a || len <= 0)
		return NULL;

	ListNode *pWork = new ListNode();
	pWork->data = a[0];
	pWork->next = NULL;
	ListNode *pHead = pWork;
	for (int i = 1; i < len; ++i)
	{
		ListNode *node = new ListNode();
		node->data = a[i];
		node->next = NULL;

		pWork->next = node;
		pWork = pWork->next;
	}

	return pHead;
}

void printList(ListNode **pHead)
{
	ListNode *pWork = *pHead;
	while (pWork)
	{
		printf("%3d ", pWork->data);
		pWork = pWork->next;
	}
}
