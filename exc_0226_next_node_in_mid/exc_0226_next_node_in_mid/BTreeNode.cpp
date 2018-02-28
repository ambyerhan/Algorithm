
# include <iostream>
# include <stdio.h>
# include "BTreeNode.h"

BTreeNode *createBiTree()
{
	BTreeNode *pHead = new BTreeNode();
	pHead->data = -1;
	pHead->pLchild = NULL;
	pHead->pRchild = NULL;

	return pHead;
}


BTreeNode *pre_mid_order(int *pre_ord, int *mid_ord, int len)
{
	if (len > 0)
	{
		BTreeNode *node = new BTreeNode();
		node->data = pre_ord[0];
		node->pLchild = NULL;
		node->pRchild = NULL;

		int pRoot = 0;
		int pLen = 0;
		for (int i = 0; i < len; ++i)
		{
			if (mid_ord[i] == node->data)
			{
				pRoot = i;
				break;
			}
			++pLen; // the sub-tree len
		}

		if (true && pLen != pRoot) // we should check if the input is valid
		{
			throw std::exception("1:Invalid Input!\n");
		}
		if (true && pRoot == 0)
		{
			if (mid_ord[0] == pre_ord[0])
				pLen = pRoot;
			else
				throw std::exception("2:Invalid Input!\n");
		}

		node->pLchild = pre_mid_order(pre_ord + 1, mid_ord, pLen);
		node->pRchild = pre_mid_order(pre_ord + pLen + 1, mid_ord + pRoot + 1, len - pLen - 1);

		return node;
	}
	return NULL;
}


BTreeNode *createBiTree_by_pre_mid_order(int *pre_ord, int *mid_ord, int len)
{
	BTreeNode *pHead = new BTreeNode();
	pHead->data = -1;
	pHead->pLchild = NULL;
	pHead->pRchild = NULL;

	BTreeNode *pWork = pHead;
	pWork->pLchild = pre_mid_order(pre_ord, mid_ord, len);

	return pHead;
}


void traverse_post(BTreeNode *pNode)
{
	if (pNode)
	{
		traverse_post(pNode->pLchild);
		traverse_post(pNode->pRchild);
		printf("%d ", pNode->data);
	}
}



TrTreeNode *pre_mid_order_Tr(int *pre_ord, int *mid_ord, int len)
{
	if (len > 0)
	{
		TrTreeNode *node = new TrTreeNode();
		node->data = pre_ord[0];
		node->pLchild = NULL;
		node->pRchild = NULL;
		node->pParent = NULL;

		int pRoot = 0;
		int pLen = 0;
		for (int i = 0; i < len; ++i)
		{
			if (mid_ord[i] == node->data)
			{
				pRoot = i;
				break;
			}
			++pLen; // the sub-tree len
		}

		if (true && pLen != pRoot) // we should check if the input is valid
		{
			throw std::exception("1:Invalid Input!\n");
		}
		if (true && pRoot == 0)
		{
			if (mid_ord[0] == pre_ord[0])
				pLen = pRoot;
			else
				throw std::exception("2:Invalid Input!\n");
		}

		node->pLchild = pre_mid_order_Tr(pre_ord + 1, mid_ord, pLen);
		if (node->pLchild)
			node->pLchild->pParent = node;
		node->pRchild = pre_mid_order_Tr(pre_ord + pLen + 1, mid_ord + pRoot + 1, len - pLen - 1);
		if (node->pRchild)
			node->pRchild->pParent = node;

		return node;
	}
	return NULL;
}


TrTreeNode *createTrTree_by_pre_mid_order(int *pre_ord, int *mid_ord, int len)
{
	TrTreeNode *pHead = new TrTreeNode();
	pHead->pLchild = NULL;
	pHead->pRchild = NULL;
	pHead->pParent = NULL;

	pHead->pLchild = pre_mid_order_Tr(pre_ord, mid_ord, len);

	return pHead;
}


void getNode_by_data(TrTreeNode *pNode, int n, TrTreeNode *&pTgtNode)
{
	if (pNode)
	{
		if (pNode->data == n)
			pTgtNode = pNode;
		getNode_by_data(pNode->pLchild, n, pTgtNode);
		getNode_by_data(pNode->pRchild, n, pTgtNode);
	}
}


void traverse_post(TrTreeNode *pNode)
{
	if (pNode)
	{
		traverse_post(pNode->pLchild);
		traverse_post(pNode->pRchild);
		printf("%d ", pNode->data);
	}
}
