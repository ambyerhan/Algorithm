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
	for (int i = 1; i < n; ++i)
		longest[i] = 1; // at least at each postion, it's len is 1

	longest[0] = 0;
	longest[1] = 1;
	//printf("%2d: %5d - %2d\n", 1, 1, 1);
	printf("%2d: %5d - %2d\n", 1, longest[1], 0);
	for (int i = 2; i < n + 1; ++i)
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
			if (arr[i - 1] >= arr[j - 1] && longest[i] < longest[j] + 1)
			{
				longest[i] = longest[j] + 1;
				li = j - 1;
			}
		}
		if (longest[i] == 1) // when the progress doesn't go into the if above, then it's value will be 0(initialized with 0, can be inialize with 1)
		{
			//longest[i] = 1;
			li = i - 1;
		}
		printf("%2d: %5d - %2d\n", i, longest[i], li);
		//longest[i] = l;
	}

	delete[] longest;
}

int longestZigZag(int *arr, int n)
{
	int *longests = new int[n + 1]{ 0 };
	int *positive = new int[n + 1]; // 0: just one elem or none, 1: pos, 2: neg

	longests[0] = 0;
	positive[0] = 0;
	longests[1] = 1;
	positive[1] = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		int lgst = 1;
		for (int j = 1; j < i; ++j)
		{
			if (arr[i - 1] == arr[j - 1])
				continue;
			if (positive[j] == 0 && longests[i] < 1 + longests[j])
			{
				longests[i] = 1 + longests[j];
				positive[i] = arr[j - 1] - arr[i - 1] > 0 ? 1 : 2; // 1 or 2
			}
			else if (positive[j] == 1
				&& arr[j - 1] - arr[i - 1] < 0
				&& longests[i] < 1 + longests[j])
			{
				longests[i] = 1 + longests[j];
				positive[i] = arr[j - 1] - arr[i - 1] > 0 ? 1 : 2; // always 2
			}
			else if (positive[j] == 2
				&& arr[j - 1] - arr[i - 1] > 0
				&& longests[i] < 1 + longests[j])
			{
				longests[i] = 1 + longests[j];
				positive[i] = arr[j - 1] - arr[i - 1] > 0 ? 1 : 2; // always 1
			}
			else
				;
		}
	}

	int longest = longests[n];
	//for (int i = 0; i < n + 1; ++i)
	//{
	//	printf("%d ", longests[i]);
	//}
	//printf("\n");
	//for (int i = 0; i < n + 1; ++i)
	//{
	//	printf("%d ", positive[i]);
	//}
	delete[] longests;
	delete[] positive;

	return longest;
}

void check(int n, int m)
{
	if (n == m)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

int test_zig_zag(int n, int *arr, int len)
{
	return longestZigZag(arr, len);
}

void test1_zig_zag()
{
	int arr[] = { 1, 7, 4, 9, 2, 5 };

	check(test_zig_zag(1, arr, 6), 6);
}

void test2_zig_zag()
{
	int arr[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };

	check(test_zig_zag(2, arr, 10), 7);
}

void test3_zig_zag()
{
	int arr[] = { 44 };

	check(test_zig_zag(3, arr, 1), 1);
}

void test4_zig_zag()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	check(test_zig_zag(4, arr, 9), 2);
}

void test5_zig_zag()
{
	int arr[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };

	check(test_zig_zag(5, arr, 19), 8);
}

void test6_zig_zag()
{
	int arr[] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 600, 947, 978, 46,
		100, 953, 670, 862, 568, 188, 67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
		477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 249, 22, 176, 279, 23, 22,
		617, 462, 459, 244 };

	check(test_zig_zag(6, arr, 50), 36);
}


int main(int argc, int *argv[])
{
	//getMinCoin(11);

	int a[LEN] = { 5, 3, 4, 8, 6, 7 };
	LIS(a, 6);

	// zig-zag test
	/*test1_zig_zag();
	test3_zig_zag();
	test5_zig_zag();
	test2_zig_zag();
	test4_zig_zag();
	test6_zig_zag();*/

	system("pause");
	return 0;
}
