/*
有一串整数，请找出序列中连续数字的和的最大值
如：{ 3, -1, 3, -4, 3, -9, 3 }， 和的最大值为5， 由连续的数字：3， -1， 3组成
*/
# include <stdio.h>
# include <stdlib.h>

# define LEN 100

int max_sum(int *arr, int len)
{
	if (!arr)
	{
		printf("Error!\n");
		return -1; // -1 means unvalid
	}

	int *sums = new int[len + 1];

	sums[0] = 0;
	sums[1] = arr[0];

	int max = 0;
	for (int i = 2; i < len + 1; ++i)
	{
		int mx = arr[i - 1] > arr[i - 1] + sums[i - 1] ? arr[i - 1] : arr[i - 1] + sums[i - 1]; // max(current, current + former, former)
		sums[i] = mx;
		if (mx > max)
			max = mx;
	}

	delete[] sums;
	return max;
}

void test(int n, int *arr, int len)
{
	printf("[%d] %d\n", n, max_sum(arr, len));
}

void test1()
{
	int arr[LEN] = { 3, -1, 3, -4, 3, -9, 3 };
	test(1, arr, 7);
}

int main(int argc, int *argv[])
{
	test1();

	system("pause");
	return 0;
}
