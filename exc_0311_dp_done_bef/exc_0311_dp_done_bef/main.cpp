
/*
最大连续子序列之和
	给定K个整数的序列{ N1, N2, ..., NK }，其任意连续子序列可表示为{ Ni, Ni+1, ..., Nj }，
	其中 1 <= i <= j <= K。最大连续子序列是所有连续子序中元素和最大的一个， 例如给定序列
	{ -2, 11, -4, 13, -5, -2 }，其最大连续子序列为{ 11, -4, 13 }，最大和为20。

状态转移方程：
	
*/

# include <stdio.h>
# include <stdlib.h>

# define DEBUG true

int max(int a, int b)
{
	return a > b ? a : b;
}

int largest_subsequent(int *arr, int len)
{
	if (!arr || len <= 0)
	{
		printf("Error!\n");
		return -1; // means error
	}

	int *sum = (int *)malloc(sizeof(int) * len);
	sum[0] = arr[0];
	for (int i = 1; i < len; ++i)
	{
		sum[i] = max(arr[i], sum[i - 1] + arr[i]);
	}

#if DEBUG
	for (int i = 0; i < len; ++i)
		printf("%d ", sum[i]);
	printf("\n");
#endif

	int max = 0;
	for (int i = 0; i < len; ++i)
		if (max < sum[i])
			max = sum[i];
	free(sum);
	return max;
}

void test(int i, int *arr, int len)
{
	printf("Test[%d] the sum = %d\n", i, largest_subsequent(arr, len));
}

void test1()
{
	int arr[] = { -2, 11, -4, 13, -5, - 2 };
	int len = 6;
	test(1, arr, len);
}

int main(void)
{
	test1();

	system("pause");
	return 0;
}
