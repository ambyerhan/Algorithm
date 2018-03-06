
# include <stdio.h>
# include <stdlib.h>
# include <cassert>

# define LEN 100

int partition(int *arr, int head, int tail)
{
	int i = head;
	int j = tail;

	int p = arr[head];
	while (i < j)
	{
		while (i < j && p <= arr[j])
			--j;
		arr[i] = arr[j];

		while (i < j && arr[i] <= p)
			++i;
		arr[j] = arr[i]; // arr[j++] may cause wrong, cuz when outer while i < j, but after above i--, it maybe change the relation between i and j
	}
	assert(i == j);

	arr[i] = p;
	return i;
}

void quick_sort(int *arr, int head, int tail)
{
	if (!arr)
	{
		printf("Error!");
		exit(-1);
	}

	int piovt = partition(arr, head, tail);
	if (head < piovt - 1) // must be check
		quick_sort(arr, head, piovt - 1);
	if (piovt + 1 < tail)
		quick_sort(arr, piovt + 1, tail);
}

void test(int n, int *arr, int len)
{
	printf("[%d]  ", n);
	quick_sort(arr, 0, len - 1);
	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}


void test1()
{
	int arr[LEN] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	test(1, arr, 10);
}

void test2()
{
	int arr[LEN] = { 1 };
	test(2, arr, 1);
}

void test3()
{
	int arr[LEN] = { 6, 9, 7, 5, 10, 1, 4, 2, 8, 3 };
	test(3, arr, 10);
}

int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}
