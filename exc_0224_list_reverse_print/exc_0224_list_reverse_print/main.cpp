
# include <stdio.h>
# include <stdlib.h>
# include <cassert>
# include "List.h"

# define LEN 100

void reversePrint(ListNode *node)
{
	if (!node)
	{
		printf("[Warn] Empty list!\n");
		return;
	}

	ListNode *pWork = node;
	int stk[LEN] = { 0 };
	int top = 0;

	while (pWork)
	{
		assert(top < LEN); // out of work-mem
		stk[top++] = pWork->data;
		pWork = pWork->next;
	}

	while (top > 0)
	{
		printf("%d ", stk[--top]);
	}
}

void reversePrint_rec(ListNode *node)
{
	if (node)
	{
		if (node->next)
			reversePrint_rec(node->next);
		printf("%d ", node->data);
	}
}

void test(int n, int *a, int len, bool rec = true)
{
	ListNode *pHead = createList(a, len);
	printf("Test%d :", n);
	if (rec)
		reversePrint_rec(pHead->next);
	else
		reversePrint(pHead->next);
	printf("\n");
}

void test1()
{
	int a[LEN] = { 0,1,2,3,4,5,6,7,8,9 };
	test(1, a, 10);
}

void test2()
{
	int a[LEN] = { 0,1,2,3,4,5,6,7,8,9 };
	test(2, a, 10, false);
}

void test3()
{
	int a[LEN] = { 0,1,2,3,4,5,6,7,8,9 };
	test(3, a, 1, true);
}

void test4()
{
	int a[LEN] = { 0,1,2,3,4,5,6,7,8,9 };
	test(4, NULL,0, true);
}
int main(void)
{
	test1();
	test2();
	test3();
	test4();

	system("pause");
	return 0;
}
