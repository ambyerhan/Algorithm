/*
merging two orderd lists to a ordered list
*/


# include <stdio.h>
# include <stdlib.h>

# include "List.h"

// the recursive one, easy to understand
ListNode *Merge(ListNode *pH1, ListNode *pH2)
{
	if (!pH1)
		return pH2;
	if (!pH2)
		return pH1;

	ListNode *pMerge = NULL;
	if (pH1->data <= pH2->data)
	{
		pMerge = pH1;
		pMerge->next = Merge(pH1->next, pH2);
	}
	else
	{
		pMerge = pH2;
		pMerge->next = Merge(pH1, pH2->next);
	}

	return pMerge;
}

ListNode *merge_list(ListNode **pHead1, ListNode **pHead2)
{
	if (!pHead1 || !pHead2)
	{
		printf("Error!\n");
		return NULL;
	}

	if (!*pHead1 && !*pHead2) // two empty lists
	{
		return NULL;
	}
	if (!*pHead1 && *pHead2)
		return *pHead2;
	if (*pHead1 && !*pHead2)
		return *pHead1;

	ListNode *pHead = NULL;
	ListNode *pWork = NULL;
	ListNode *pWork1 = *pHead1;
	ListNode *pWork2 = *pHead2;

	// get the first node
	if (pWork1->data <= pWork2->data)
	{
		pHead = pWork1;
		pWork = pHead;
		pWork1 = pWork1->next;
	}
	else
	{
		pHead = pWork2;
		pWork = pHead;
		pWork2 = pWork2->next;
	}

	while (pWork1 && pWork2)
	{
		if (pWork1->data <= pWork2->data)
		{
			pWork->next = pWork1;
			pWork1 = pWork1->next;
		}
		else
		{
			pWork->next = pWork2;
			pWork2 = pWork2->next;
		}
		pWork = pWork->next;
	}
	if (pWork1)
	{
		pWork->next = pWork1;
	}
	if (pWork2)
	{
		pWork->next = pWork2;
	}

	return pHead;
}

void test(int n, ListNode **pH1, ListNode **pH2)
{
	printf("Test[%d]\n", n);
	printf("\t>>");
	printList(pH1);
	printf("\n\t>>");
	printList(pH2);

	ListNode *pH = merge_list(pH1, pH2);
	printf("\n\t>>");
	printList(&pH);
	printf("\n");
}

void test1()
{
	int a[] = { 1, 3, 5 };
	int b[] = { 2, 4, 6 };
	int la = 3;
	int lb = 3;
	ListNode *pH1 = createListWithHeadPointer(a, la);
	ListNode *pH2 = createListWithHeadPointer(b, lb);
	test(1, &pH1, &pH2);
}

void test2()
{
	int a[] = { 1, 3, 5 };
	int b[] = { 2, 4, 6 };
	int la = 3;
	int lb = 0;
	ListNode *pH1 = createListWithHeadPointer(a, la);
	ListNode *pH2 = createListWithHeadPointer(b, lb);
	test(2, &pH1, &pH2);
}

void test3()
{
	int a[] = { 1, 3, 5 };
	int b[] = { 2, 4, 6 };
	int la = 0;
	int lb = 3;
	ListNode *pH1 = createListWithHeadPointer(a, la);
	ListNode *pH2 = createListWithHeadPointer(b, lb);
	test(3, &pH1, &pH2);
}

void test4()
{
	int a[] = { 1, 3, 5, 6, 9, 10, 20 };
	int b[] = { 2, 4, 6 };
	int la = 7;
	int lb = 3;
	ListNode *pH1 = createListWithHeadPointer(a, la);
	ListNode *pH2 = createListWithHeadPointer(b, lb);
	test(4, &pH1, &pH2);
}

void test5()
{
	int a[] = { 1, 3, 5, 6, 9, 10, 20 };
	int b[] = { 2, 4, 6 };
	int la = 0;
	int lb = 0;
	ListNode *pH1 = createListWithHeadPointer(a, la);
	ListNode *pH2 = createListWithHeadPointer(b, lb);
	test(5, &pH1, &pH2);
}

void test6()
{
	int a[] = { 1, 3, 5, 6 };
	int b[] = { 2, 4, 6, 9, 10, 20 };
	int la = 4;
	int lb = 6;
	ListNode *pH1 = createListWithHeadPointer(a, la);
	ListNode *pH2 = createListWithHeadPointer(b, lb);
	test(6, &pH1, &pH2);
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
