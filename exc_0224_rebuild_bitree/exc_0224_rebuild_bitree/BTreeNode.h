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

# endif
