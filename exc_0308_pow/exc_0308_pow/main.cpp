
# include <stdio.h>
# include <stdlib.h>


double power(float num, int e)
{
	double rslt = 1;
	if (e == 0)
		rslt = 1.0; // assume that 0^0 = 1
	else if (e > 0)
	{
		for (int i = 0; i < e; ++i)
			rslt *= num;
	}
	else
	{
		if (num == 0)
		{
			printf("Error!\n");
			exit(-1);
		}

		e = -1 * e;
		for (int i = 0; i < e; ++i) // alert: what about num = 0
			rslt /= num;
	}

	return rslt;
}

void test(int n, float num, int e)
{
	printf("Test[%d] %.3f^%d = %.3f\n", n, num, e, power(num, e));
}

void test1()
{
	test(1, (float)2.0, 5);
}

void test2()
{
	test(2, (float)2.0, -2);
}

int main(int argc, int *argv[])
{
	test1();
	test2();

	system("pause");
	return 0;
}
