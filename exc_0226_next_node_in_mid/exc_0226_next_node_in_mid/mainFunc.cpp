
# include <stdio.h>
# include <stdlib.h>

# include "BTreeNode.h"

# define LEN 100

TrTreeNode *getNextNum(TrTreeNode *pRoot, int num)
{
	TrTreeNode *next = NULL;

	// first find the node that node->data == num
	TrTreeNode *pCurNode = NULL;
	getNode_by_data(pRoot, num, pCurNode);

	if (!pCurNode)
	{
		return NULL;
	}

	// second search the next num in in_order
	if (pCurNode->pRchild)
	{
		// if the cur node has rchild
		TrTreeNode *pWork = pCurNode->pRchild;
		while (pWork->pLchild)
			pWork = pWork->pLchild;
		next = pWork;
	}
	else if (!pCurNode->pRchild && pCurNode->pParent && pCurNode->pParent->pLchild == pCurNode)
	{
		// if the cur node hasnt rchild and it is the lchild of it's parent
		next = pCurNode->pParent;
	}
	else
	{
		if (!pCurNode->pParent)
			next = NULL;

		// if the cur node has not rchild and it is the rchild of it's parent
		TrTreeNode *pWork = pCurNode->pParent;
		while (pWork->pParent)
		{
			if (pWork->pParent->pRchild == pWork)
			{
				pWork = pWork->pParent;
				next = NULL;
			}
			else
			{
				next = pWork->pParent;
				break;
			}
		}
	}

	return next;
}

void test(int n, TrTreeNode *pHead, int num)
{
	TrTreeNode *next = getNextNum(pHead->pLchild, num);
	if (next)
		printf("Test%d: in[%d] --> %d\n", n, num, next->data);
	else
		printf("Test%d: in[%d] --> No\n", n, num);
}

void test1()
{
	int pre[LEN] = { 1, 2, 4, 5, 8, 9, 3, 6, 7 };
	int mid[LEN] = { 4, 2, 8, 5, 9, 1, 6, 3, 7 };

	TrTreeNode *pHead = createTrTree_by_pre_mid_order(pre, mid, 9); // pHead->pLchild is the root

	int num = 2;
	test(1, pHead, num);
}

void test2()
{
	int pre[LEN] = { 1, 2, 4, 5, 8, 9, 3, 6, 7 };
	int mid[LEN] = { 4, 2, 8, 5, 9, 1, 6, 3, 7 };

	TrTreeNode *pHead = createTrTree_by_pre_mid_order(pre, mid, 9); // pHead->pLchild is the root

	int num = 4;
	test(2, pHead, num);
}

void test3()
{
	int pre[LEN] = { 1, 2, 4, 5, 8, 9, 3, 6, 7 };
	int mid[LEN] = { 4, 2, 8, 5, 9, 1, 6, 3, 7 };

	TrTreeNode *pHead = createTrTree_by_pre_mid_order(pre, mid, 9); // pHead->pLchild is the root

	int num = 9;
	test(3, pHead, num);
}

void test4()
{
	int pre[LEN] = { 1, 2, 4, 5, 8, 9, 3, 6, 7 };
	int mid[LEN] = { 4, 2, 8, 5, 9, 1, 6, 3, 7 };

	TrTreeNode *pHead = createTrTree_by_pre_mid_order(pre, mid, 9); // pHead->pLchild is the root

	int num = 1;
	test(4, pHead, num);
}

void test5()
{
	int pre[LEN] = { 1, 2, 4, 5, 8, 9, 3, 6, 7 };
	int mid[LEN] = { 4, 2, 8, 5, 9, 1, 6, 3, 7 };

	TrTreeNode *pHead = createTrTree_by_pre_mid_order(pre, mid, 9); // pHead->pLchild is the root

	int num = 7;
	test(5, pHead, num);
}

void test6()
{
	int pre[LEN] = { 1, 2, 4, 5, 8, 9, 3, 6, 7 };
	int mid[LEN] = { 4, 2, 8, 5, 9, 1, 6, 3, 7 };

	TrTreeNode *pHead = createTrTree_by_pre_mid_order(pre, mid, 9); // pHead->pLchild is the root

	int num = 11;
	test(6, pHead, num);
}

int main(void)
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
