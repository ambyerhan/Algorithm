
# include <stdio.h>
# include <stdlib.h>

# define LEN 100

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

bool isEven(int n)
{
	return (n & 0x01) == 0 ? true : false;
	//return n % 2 == 0 ? true : false;
}

void even_odd_arr(int *arr, int len, bool (*fun)(int))
{
	if (!arr || len <= 0)
	{
		printf("Error!\n");
		return;
	}

	int i = 0;
	int j = len - 1;
	
	while (i < j)
	{
		while (i < j && !fun(arr[i]))
			++i;
		while (i < j && fun(arr[j]))
			--j;
		if (i < j)
			swap(arr[i], arr[j]);
	}
}

void printArr(int *arr, int len)
{
	if (!arr)
	{
		printf("Error\n");
		return;
	}
	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void test(int n, int *arr, int len)
{
	printf("Test[%d]", n);
	printf("\n\t>> bef: ");
	printArr(arr, len);
	even_odd_arr(arr, len, isEven);
	printf("\t>> aft: ");
	printArr(arr, len);
}

void test1()
{
	int arr[LEN] = { 1, 2, 3, 4, 5 };
	int len = 5;
	test(1, arr, len);
}

void test2()
{
	int arr[LEN] = { 1, 3, 5, 4, 2 };
	int len = 5;
	test(2, arr, len);
}

void test3()
{
	int arr[LEN] = { 4, 2, 1, 3, 5 };
	int len = 5;
	test(3, arr, len);
}

void test4()
{
	int arr[LEN] = { 4, 2, 1, 3, 5 };
	int len = 1;
	test(4, arr, len);
}

void test5()
{
	int arr[LEN] = { 4, 2, 1, 3, 5 };
	int len = 1;
	test(5, NULL, len);
}

int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();

	system("pause");
	return 0;
}
