
# include <stdio.h>
# include <stdlib.h>

# include "List.h"

# define LEN 100

int getMidNode(ListNode **pHead)
{
	if (!pHead || !*pHead)
	{
		printf("Error!\n");
		return -1; // here -1 means illegal input
	}

	ListNode *pFast = *pHead;
	ListNode *pSlow = *pHead;

	while (pSlow->next && pFast->next && pFast->next->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}

	return pSlow->data;
}

void test(int n, ListNode **pHead)
{
	printf("Test[%d] %d\n", n, getMidNode(pHead));
}

void test1()
{
	int a[LEN] = { 1, 2, 3 };
	int len = 3;
	ListNode *pHead = createListWithHeadPointer(a, len);
	test(1, &pHead);
}

void test2()
{
	int a[LEN] = { 1, 2 };
	int len = 2;
	ListNode *pHead = createListWithHeadPointer(a, len);
	test(2, &pHead);
}

void test3()
{
	int a[LEN] = { 11 };
	int len = 1;
	ListNode *pHead = createListWithHeadPointer(a, len);
	test(3, &pHead);
}

void test4()
{
	int a[LEN] = { 1, 4, 5, 7, 2, 3 };
	int len = 6;
	ListNode *pHead = createListWithHeadPointer(a, len);
	test(4, &pHead);
}

void test5()
{
	int a[LEN] = { 1, 4, 5, 7, 2, 3, 9 };
	int len = 7;
	ListNode *pHead = createListWithHeadPointer(a, len);
	test(5, &pHead);
}

void test6()
{
	int a[LEN] = { 1, 4, 5, 7, 2, 3, 9 };
	int len = 7;
	ListNode *pHead = createListWithHeadPointer(a, len);
	test(6, NULL);
}

int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	system("pause");
	return 0;
}
