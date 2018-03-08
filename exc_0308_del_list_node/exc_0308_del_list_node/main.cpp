
# include <stdio.h>
# include <stdlib.h>

# include "List.h"

void delNode(ListNode **pHead, ListNode *pDel)
{
	if (!pHead || !pDel)
	{
		printf("Error!\n");
		return ;
	}

	if (!*pHead)
	{
		printf("Empty list!\n");
	}

	ListNode *pWork = *pHead; // pWork point to the first node

	if (pWork == pDel && !pWork->next) // there is only one node
	{
		free(pDel);
		pDel = NULL;
		pWork = NULL;
		*pHead = NULL; // have to release this
		pHead = NULL;
		return;
	}
	if (!pDel->next) // O(n)
	{
		while (pWork->next != pDel)
			++pWork;
		pWork->next = pDel->next; // actually null
		free(pDel);
		pDel = NULL;
	}
	else // O(1)
	{
		ListNode *t = pDel->next;
		pDel->data = t->data;
		pDel->next = t->next;
		free(t);
		t = NULL;		
	}
}

ListNode* getDelPoint(ListNode **pH, int idx)
{
	ListNode *pWork = *pH;
	if (!pWork)
		return NULL;
	for (int i = 0; i < idx - 1; ++i)
	{
		if (!pWork)
		{
			printf("Error!\n");
			system("pause");
			exit(-1);
		}
		pWork = pWork->next;
	}
	return pWork;
}

void test(int n, ListNode **pHead, ListNode *pDel)
{
	printf("Test[%d]\n", n);
	printf("\t> bef: ");
	printList(pHead);
	delNode(pHead, pDel);
	printf("\n\t> aft: ");
	printList(pHead);
	printf("\n");
}

void test1()
{
	int a[] = { 1, 2, 3, 4 };
	ListNode *pHead = createListWithHeadPointer(a, 4);
	ListNode *pDel = getDelPoint(&pHead, 3);
	test(1, &pHead, pDel);
}

void test2()
{
	int a[] = { 1, 2, 3, 4 };
	ListNode *pHead = createListWithHeadPointer(a, 4);
	ListNode *pDel = getDelPoint(&pHead, 4);
	test(2, &pHead, pDel);
}

void test3()
{
	int a[] = { 1 };
	ListNode *pHead = createListWithHeadPointer(a, 1);
	ListNode *pDel = getDelPoint(&pHead, 1);
	test(3, &pHead, pDel);
}

int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}
