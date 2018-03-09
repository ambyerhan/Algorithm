
# include <stdio.h>
# include <stdlib.h>

# include "List.h"


void del_duplication(ListNode **pHead)
{
	if (!pHead || !*pHead)
	{
		printf("Error!\n");
		return;
	}

	ListNode *pWork = *pHead;
	ListNode *pPre = *pHead;

	if (!pWork->next) // only one node, return directly
		return;

	// make sure that the list has at least 2 nodes
	ListNode *pHeadNode = new ListNode();
	pHeadNode->data = -1;
	pHeadNode->next = pWork;

	*pHead = pHeadNode; // after finish the del, the pHead need to point to the pHeadNode->next
	pPre = pHeadNode;
	
	while (pWork)
	{
		if (!pWork->next) // finish: cuz, when pWork->next == NULL, it will go circling forever
			break; // or use pWork every time and using int var to check if cur-node need to be del
		while (pWork->next && pWork->data != pWork->next->data)
		{
			pPre = pWork;
			pWork = pWork->next;
		}
		while (pWork->next && pWork->data == pWork->next->data)
		{
			ListNode *pTmp = pWork;
			pWork = pWork->next;
			free(pTmp);
			pTmp = NULL;
		}
		if (pPre->next != pWork) // the pWork points to the last repeated node
		{// todo : dose every situation match this
			pPre->next = pWork->next;
			free(pWork);
			pWork = pPre->next;
		}
	}
	*pHead = pHeadNode->next;
	free(pHeadNode);
	pHeadNode = NULL;
}

void test(int n, ListNode **pHead)
{
	printf("Test[%d]\n", n);
	printf("\t >> bef: ");
	printList(pHead);
	printf("\n");
	del_duplication(pHead);
	printf("\t >> aft: ");
	printList(pHead);
	printf("\n");
}

void test1()
{
	int arr[] = { 1, 2, 2, 3, 3, 4 };
	int len = 6;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(1, &pHead);
}

void test2()
{
	int arr[] = { 1, 2, 2, 3, 3 };
	int len = 5;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(2, &pHead);
}

void test3()
{
	int arr[] = { 2, 2, 3, 3 };
	int len = 4;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(3, &pHead);
}

void test4()
{
	int arr[] = { 2, 2, 3 };
	int len = 3;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(4, &pHead);
}

void test5()
{
	int arr[] = { 2, 2, 1, 3, 3 };
	int len = 5;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(5, &pHead);
}

void test6()
{
	int arr[] = { 1, 2, 4, 3, 5 };
	int len = 5;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(6, &pHead);
}

void test7()
{
	int arr[] = { 1, 2, 4, 3, 5 };
	int len = 5;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(7, NULL);
}

int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();

	system("pause");
	return 0;
}
