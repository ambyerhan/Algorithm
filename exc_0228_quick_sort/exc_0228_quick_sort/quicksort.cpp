
# include <iostream>
# include <stdio.h>
# include <stdlib.h>

# define LEN 100

using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *a, int l, int r) // partition get the pivot
{
	int axis = a[l];
	while (l < r)
	{
		while (l < r && a[r] >= axis)
			--r;
		a[l] = a[r];

		while (l < r && a[l] <= axis)
			++l;
		a[r] = a[l];
	}
	a[l] = axis;

	return l;
}

void quick_sort(int *a, int l, int r) // quicksort recursive
{
	if (l >= r)
		return;

	int ax = partition(a, l, r);
	quick_sort(a, l, ax - 1); // split with ax
	quick_sort(a, ax + 1, r);
}

void test(int n, int *a, int l, int r, int len)
{
	quick_sort(a, l, r);
	printf("Test%d:", n);
	for (int i = 0; i < len; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void test1()
{
	int a[LEN] = { 9, 8, 7, 6 ,5, 4, 3, 1, 1, 0 };
	test(1, a, 0, 9, 10);
}

void test2()
{
	int a[LEN] = { 9, 8, 1, 3, 10, 4 };
	test(2, a, 0, 5, 6);
}

int main(void)
{	
	test1();
	test2();

	system("pause");
	return 0;
}

