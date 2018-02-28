
# include <stdio.h>
# include <stdlib.h>

# include "BTreeNode.h"

# define LEN 100

void test(int n, int *pre, int *mid, int len)
{
	printf("Test%d:", n);
	BTreeNode *p = createBiTree_by_pre_mid_order(pre, mid, len);
	traverse_post(p->pLchild);
	printf("\n");
}

void test1()
{
	int pre[LEN] = {1, 2, 4, 7, 3, 5, 6, 8};
	int mid[LEN] = {4, 7, 2, 1, 5, 3, 8, 6};
	int len = 8;

	test(1, pre, mid, len);
}
void test2()
{
	int pre[LEN] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int mid[LEN] = { 2, 7, 2, 1, 5, 3, 8, 6 };
	int len = 1;

	test(2, pre, mid, len);
}

int main(void)
{
	test1();
	test2();

	system("pause");
	return 0;
}
