
# include <stdio.h>
# include <stdlib.h>

# define DEBUG true

int step_num(int n)
{
	if (n <= 0)
		return -1;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	int *steps = (int *)malloc(sizeof(int) * (n + 1));
	
	steps[0] = 0;
	steps[1] = 1;
	steps[2] = 2;
	for (int i = 3; i < n + 1; ++i)
	{
		steps[i] = steps[i - 1] + steps[i - 2];
	}
#if DEBUG
	for (int i = 0; i < n; ++i)
		printf("%d ", steps[i]);
#endif

	int step_n = steps[n];
	free(steps);

	return step_n;
}

void test(int n, int step)
{
	printf("Test[%2d] %d\n", n, step_num(step));
}

void test1()
{
	test(1, 1);
}

void test2()
{
	test(2, 2);
}

void test3()
{
	test(3, 10);
}

int main(void)
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}
