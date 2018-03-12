/*
数塔问题 ：要求从顶层走到底层，若每一步只能走到相邻的结点，则经过的结点的数字之和最大是多少？

 9
12	15
10	 6	 8
 2	18	 9	 5
19	 7	10	 4	16

即a[i][j] 与 a[i+1][j], a[i+1][j+1]相连

dynamic programming: 自顶向下的分析，自底向上的计算
转移方程: sum[i][j] = max(sum[i+1][j], sum[i+1][j+1]) + data[i][j]
*/


# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define DEBUG true
# define LEN 5

int max(int a, int b)
{
	return a > b ? a : b;
}

int nTower(int (*arr)[LEN], int len)
{
	if (!arr || !*arr || len <= 0)
	{
		printf("Error!\n");
		return -1;
	}

	int **path = (int **)malloc(sizeof(int *) * len);
	for (int i = 0; i < len; ++i)
	{
		path[i] = (int *)malloc(sizeof(int) * len);
		memset(path[i], 0, len);
	}

	// dp part
	for (int i = len - 1; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (i == len - 1)
				path[i][j] = arr[i][j];
			else
			{
				path[i][j] = max(path[i + 1][j], path[i + 1][j + 1]) + arr[i][j];
			}
		}
	}
	//

#if DEBUG
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("%3d", path[i][j]);
		}
		printf("\n");
	}
#endif

	int max = path[0][0];
	for (int i = 0; i < len; ++i)
		free(path[i]);
	free(path);
	return max;
}

void test(int i, int (*arr)[LEN], int len)
{
	printf("Test[%d] max path = %d\n", i, nTower(arr, len));
}

void test1()
{
	int arr[][LEN] = { { 9,  0, 0, 0, 0},
						  {12, 15, 0, 0, 0},
						  {10,  6, 8, 0, 0},
						  { 2, 18, 9, 5, 0},
						  {19,  7,10, 4,16} };
	int len = 5;
	test(1, arr, len);
}

int main(int argc, int *argv[])
{
	test1();

	system("pause");
	return 0;
}
