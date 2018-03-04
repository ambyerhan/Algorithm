/*
code of question about dp from: http://www.hawstein.com/posts/dp-novice-to-advanced.html
动态规划算法通常基于一个递推公式及一个或多个初始状态。 当前子问题的解将由上一次子问题的解推出。
*/
# include <stdio.h>
# include <stdlib.h>

# define LEN 100

void printIntArr(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
		printf("%d:%5d\n", i, arr[i]);
} 

void getMinCoin(int n)
{
	int min[LEN];

	int coinV[] = { 1, 3, 5 };

	min[0] = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		int m = 1000; // maximum
		int mi = 0;
		for (int j = 0; j < 3; ++j)
		{
			if (i - coinV[j] >= 0)
			{
				int tmp = min[i - coinV[j]] + 1;
				if (tmp < m)
				{
					m = tmp;
					mi = j;
				}
			}
		}
		min[i] = m;

		printf("%2d: %5d - %2d(%2d)\n", i, m, coinV[mi], (i - coinV[mi]));
	}

	// printIntArr(min, n + 1);
}

void LIS(int *arr, int n)
{
	int *longest = new int[n + 1]{ 0 };

	longest[0] = 0;
	longest[1] = 1;
	printf("%2d: %5d - %2d\n", 1, 1, 1);
	printf("%2d: %5d - %2d\n", 2, 1, 2);
	for (int i = 2; i < n; ++i)
	{
		int l = 1; // the length at least 1, e.t., current number itself is ordered
		int li = i; // if the current num is the smallest, which mean cannot go into the for-if, then the li should be current num's index + 1
		for (int j = 1; j < i; ++j)
		{
			/*if (arr[i] >= arr[j])
			{
				int tmp = 1 + longest[j];
				if (tmp > l)
				{
					l = tmp;
					li = j;
				}
			}*/
			if (arr[i] >= arr[j] && longest[i] < longest[j] + 1)
			{
				longest[i] = longest[j] + 1;
				li = j;
			}
		}
		printf("%2d: %5d - %2d\n", i + 1, longest[i], li + 1);
		//longest[i] = l;
	}

	delete[] longest;
}


int main(int argc, int *argv[])
{
	//getMinCoin(11);

	//int a[LEN] = { 5, 3, 4, 8, 6, 7 };
	//LIS(a, 6);

	system("pause");
	return 0;
}
