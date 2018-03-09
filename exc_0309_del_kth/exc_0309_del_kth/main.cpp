
# include <stdio.h>
# include <stdlib.h>

# include "List.h"

int get_rKth(ListNode **pHead, int k)
{
	if (!pHead || !*pHead || k <= 0)
	{
		printf("Error!\n");
		return -1;
	}

	ListNode *pWork = *pHead;

	int i = 0;
	while (pWork && i < k - 1)
	{
		pWork = pWork->next;
		++i;
	}
	if (!pWork)
	{
		printf("No enough nodes!\n");
		return 0;
	}

	ListNode *pPre = *pHead;
	while (pWork->next)
	{
		pWork = pWork->next;
		pPre = pPre->next;
	}

	//ListNode *tmp = pPre->next;
	//pPre->data = tmp->data;
	//pPre->next = tmp->next;
	//free(tmp);
	//tmp = NULL;
	return pPre->data;
}

void test(int n, ListNode **pHead, int k)
{
	printf("Test[%d] %d\n", n, get_rKth(pHead, k));
}

void test1()
{
	int arr[] = { 11, 22, 33, 44, 55 };
	int len = 5;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(1, &pHead, 2);
}

void test2()
{
	int arr[] = { 11, 22, 33, 44, 55 };
	int len = 5;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(2, &pHead, 5);
}

void test3()
{
	int arr[] = { 11, 22, 33, 44, 55 };
	int len = 5;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(3, &pHead, 1);
}

void test4()
{
	int arr[] = { 11, 22, 33, 44, 55 };
	int len = 1;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(4, &pHead, 2);
}

void test5()
{
	int arr[] = { 11, 22, 33, 44, 55 };
	int len = 2;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(5, &pHead, 1);
}

void test6()
{
	int arr[] = { 11, 22, 33, 44, 55 };
	int len = 2;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(6, NULL, 1);
}

void test7()
{
	int arr[] = { 11, 22, 33, 44, 55 };
	int len = 2;
	ListNode *pHead = createListWithHeadPointer(arr, len);
	test(7, &pHead, 0);
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
