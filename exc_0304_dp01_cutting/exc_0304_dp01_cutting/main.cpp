
# include <iostream>
# include <stdio.h>
# include <stdlib.h>

# define LEN 100

int maxCut_dp(int n)
{
	if (n <= 1)
	{
		printf("Error! Rope length must be longer than 1!\n");
		return -1;
	}
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;

	int *prod = new int[n + 1]; // when i >= 4 means, f(i)
	prod[0] = 0; // todo: why 0, 1, 2, 3 --> special
	prod[1] = 1;
	prod[2] = 2;
	prod[3] = 3;

	int max = 0;
	for (int i = 4; i < n + 1; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j) // todo: why i / 2 --> cuz it is symmetrical, 4 cut to 1,3 and 3,1 is the same
		{
			int pro = prod[j] * prod[i - j];
			if (pro > max)
				max = pro;
		}
		prod[i] = max;
	}

	max = prod[n];
	delete[] prod;
	return max;
}

int maxCut_gs(int n)
{
	if (n <= 1)
	{
		printf("Error! Rope length must be longer than 1!\n");
		return -1;
	}
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;

	// n >= 4
	int timesOf3 = n / 3;
	int rest = n % 3;

	if (rest == 0) 
	{
		return pow(3, timesOf3);
	}
	else if (rest == 1)
	{
		return pow(3, timesOf3 - 1) * 4;
	}
	else // rest == 2
	{
		return pow(3, timesOf3) * 2;
	}

	return 0;
}

// ====================≤‚ ‘¥˙¬Î====================
void test(const char* testName, int length, int expected)
{
	int result1 = maxCut_dp(length);
	if (result1 == expected)
		std::cout << "Solution1 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

	int result2 = maxCut_gs(length);
	if (result2 == expected)
		std::cout << "Solution2 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
	int length = 1;
	int expected = -1;
	test("test1", length, expected);
}

void test2()
{
	int length = 2;
	int expected = 1;
	test("test2", length, expected);
}

void test3()
{
	int length = 3;
	int expected = 2;
	test("test3", length, expected);
}

void test4()
{
	int length = 4;
	int expected = 4;
	test("test4", length, expected);
}

void test5()
{
	int length = 5;
	int expected = 6;
	test("test5", length, expected);
}

void test6()
{
	int length = 6;
	int expected = 9;
	test("test6", length, expected);
}

void test7()
{
	int length = 7;
	int expected = 12;
	test("test7", length, expected);
}

void test8()
{
	int length = 8;
	int expected = 18;
	test("test8", length, expected);
}

void test9()
{
	int length = 9;
	int expected = 27;
	test("test9", length, expected);
}

void test10()
{
	int length = 10;
	int expected = 36;
	test("test10", length, expected);
}

void test11()
{
	int length = 50;
	int expected = 86093442;
	test("test11", length, expected);
}

int main(int agrc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();

	system("pause");
	return 0;
}
