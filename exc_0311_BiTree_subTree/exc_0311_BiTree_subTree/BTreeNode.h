#pragma once

# ifndef _BTreeNode_H_
# define _BTreeNode_H_

typedef int ElemType;

struct BTreeNode
{
	ElemType data;
	BTreeNode *pLchild;
	BTreeNode *pRchild;
};

BTreeNode *createBiTree_by_pre_mid_order(int *pre_ord, int *mid_ord, int len);
void traverse_post(BTreeNode *pNode);

struct TrTreeNode
{
	ElemType data;
	TrTreeNode *pLchild;
	TrTreeNode *pRchild;
	TrTreeNode *pParent;
};

TrTreeNode *createTrTree_by_pre_mid_order(int *pre_ord, int *mid_ord, int len);
void getNode_by_data(TrTreeNode *pNode, int n, TrTreeNode *&pTgtNode);
void traverse_post(TrTreeNode *pNode);

# endif
