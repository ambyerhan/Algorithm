
# include <stdio.h>
# include <stdlib.h>

int fabi(int n)
{
	if (n < 0)
		return -1; // means error input
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	int pre = 0;
	int post = 1;

	int fn = 0;
	for (int i = 2; i < n; ++i)
	{
		fn = pre + post;

		pre = post;
		post = fn;
	}

	return fn;
}

void test(int n, int num)
{
	printf("Test%d: f(%d)=%d\n", n, num, fabi(num));
}

void test1()
{
	test(1, 3);
}

void test2()
{
	test(2, 5);
}

void test3()
{
	test(3, 10);
}

void test4()
{
	test(4, 40);
}

void test5()
{
	test(5, 1);
}

void test6()
{
	test(6, 2);
}

int main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	system("pause");
	return 0;
}
