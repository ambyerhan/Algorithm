
# include <stdio.h>
# include <stdlib.h>

# include "List.h"


void reverse_list(ListNode **pHead)
{
	if (!pHead || !*pHead)
	{
		printf("Error!\n");
		return;
	}

	ListNode *pPre = *pHead;
	if (!pPre->next) // if there is only one node, then return
		return;

	ListNode *pTmp = NULL;
	ListNode *pWork = pPre->next;

	pPre->next = NULL;
	while (pWork)
	{
		pTmp = pWork->next;
		pWork->next = pPre;

		pPre = pWork;
		pWork = pTmp;
	}

	*pHead = pPre;
}

void test(int n, ListNode **pHead)
{
	printf("Test [%d]\n\t>>bef:", n);
	printList(pHead);
	reverse_list(pHead);
	printf("\n\t>>aft:");
	printList(pHead);
	printf("\n");
}

void test1()
{
	int arr[] = { 1, 2, 3, 4 };
	int len = 4;
	ListNode *pHead = createListWithHeadPointer(arr, len);

	test(1, &pHead);
}

void test2()
{
	int arr[] = { 1, 2, 3 };
	int len = 3;
	ListNode *pHead = createListWithHeadPointer(arr, len);

	test(2, &pHead);
}

void test3()
{
	int arr[] = { 1 };
	int len = 1;
	ListNode *pHead = createListWithHeadPointer(arr, len);

	test(3, &pHead);
}

void test4()
{
	int arr[] = { 1, 2 };
	int len = 2;
	ListNode *pHead = createListWithHeadPointer(arr, len);

	test(4, &pHead);
}

void test5()
{
	int arr[] = { 1, 2 };
	int len = 2;
	ListNode *pHead = createListWithHeadPointer(arr, len);

	test(5, NULL);
}

void test6()
{
	int arr[] = { 1, 2 };
	int len = 2;
	ListNode *pHead = createListWithHeadPointer(arr, len);

	test(6, NULL);
}

int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();

	system("pause");
	return 0;
}
