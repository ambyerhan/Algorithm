/*
最长递增子序列问题
	设L=<a1,a2,…,an>是n个不同的实数的序列，L的递增子序列是这样一个子序列Lin=<aK1,ak2,…,akm>
	其中k1<k2<…<km且aK1<ak2<…<akm。求最大的m值。

	Tip: 子序列不一定要相邻!!!
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define DEBUG true

int LIS(int *arr, int len)
{
	if (!arr || len <= 0)
	{
		printf("Error!\n");
		return -1; // -1 means error inputs
	}

	int *lis = (int *)malloc(sizeof(int) * len);
	memset(lis, 0, len);

	// dp
	lis[0] = 1;
	for (int i = 1; i < len; ++i)
	{
		lis[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}
	//

#if DEBUG
	for (int i = 0; i < len; ++i)
		printf("%3d", lis[i]);
	printf("\n");
#endif

	int max = lis[len - 1];
	free(lis);
	return max;
}

void test(int i, int *arr, int len)
{
	printf("Test[%d] lis = %d\n", i, LIS(arr, len));
}

void test1()
{
	int arr[] = { 1, 4, 3, 4 };
	int len = 4;
	test(1, arr, len);
}

void test2()
{
	int arr[] = { 5, 3, 4, 8, 6, 7 };
	int len = 6;
	test(2, arr, len);
}

int main(int argc, int *argv[])
{
	test1();
	test2();

	system("pause");
	return 0;
}
