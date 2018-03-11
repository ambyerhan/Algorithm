
/*
!!!!uncheck
not check yet: cuz its not so important so far (2018.03.11)
*/

# include <stdio.h>
# include <stdlib.h>

# include "BTreeNode.h"

bool isSame(BTreeNode *pR1, BTreeNode *pR2)
{
	if ((!pR1 && !pR2) || (pR1 && !pR2) || // pR2 can be null, cuz it is a sub tree of pR1
		(pR1->data == pR2->data &&
		isSame(pR1->pLchild, pR2->pLchild) &&
		isSame(pR1->pRchild, pR2->pRchild)))
	{
		return true;
	}
	else
		return false;
}

bool isSubTree(BTreeNode *pRoot1, BTreeNode *pRoot2)
{
	bool isSub = false;
	if (pRoot1 && pRoot2)
	{
		if (pRoot1->data == pRoot2->data)
		{
			isSub = isSame(pRoot1, pRoot2);
		}
		
		if (!isSub) // (!isSub)
		{
			isSub = isSubTree(pRoot1->pLchild, pRoot2);
			isSub = isSubTree(pRoot1->pRchild, pRoot2);
		}

		if (isSub)
			return isSub;
	}
	else
	{
		return false;
	}
}

int main(int argc, int *argv[])
{

	system("pause");
	return 0;
}
