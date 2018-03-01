
# include <iostream>
# include <stdio.h>
# include <stdlib.h>

# define LEN 100

int inorder(int *arr, int h, int t)
{
	int rslt = arr[h];
	for (int i = h; i < t; ++i)
	{
		if (arr[i] < rslt)
			rslt = arr[i];
	}
	return rslt;
}

int min(int *arr, int len)
{
	if (!arr || len <= 0)
		throw new std::exception("Invalid Array!");

	int h = 0;
	int t = len - 1;
	int m = h;

	while (arr[h] >= arr[t]) // important
	{
		if (t - h == 1)
		{
			m = t;
			break;
		}

		m = (int)((h + t) / 2);

		if (arr[h] == arr[m] && arr[m] == arr[t] && arr[h] == arr[t])
			return inorder(arr, h, t);

		if (arr[m] >= arr[h])
			h = m;
		else
			t = m;
	}

	return arr[m];
}

int find_min(int *arr, int h, int t)
{
	if (!arr)
	{
		throw new std::exception("Invalid Array!");
	}

	int i = h;
	int j = t;
	int mid;

	if (arr[h] < arr[t]) // the circle arr is ordered
		return arr[h];

	while (i < j)
	{
		mid = (int)((i + j) / 2);

		if (arr[mid] >= arr[i])
		{
			i = mid;
		}
		else
		{
			j = mid;
		}
	}
	return arr[mid];
}

void test(int n, int *arr, int len)
{
	int m = find_min(arr, 0, len - 1);
	printf("Test%d: %d\n", n, m);
}

void test1()
{
	int a[LEN] = { 3, 4, 5, 1, 2 };
	test(1, a, 5);
}

int main(void)
{
	test1();

	system("pause");
	return 0;
}
