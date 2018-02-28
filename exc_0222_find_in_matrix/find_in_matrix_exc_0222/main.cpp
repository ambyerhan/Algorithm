
# include <stdio.h>
# include <stdlib.h>

# define NUM 4

bool findNum(int mat[NUM][NUM], int num)
{
	// some check
	if (mat == NULL)
	{
		printf("Error! The matrix is NULL\n");
		exit(-1);
	}

	int i = 0, j = NUM - 1;
	while (i < NUM && j > -1)
	{
		if (mat[i][j] == num)
			return true;
		else if (mat[i][j] > num)
			--j;
		else
			++i;
	}

	return false;
}

bool findNumLowerleft(int mat[NUM][NUM], int num)
{
	// some check

	int i = NUM - 1;
	int j = 0;

	while (i > -1 && j < NUM)
	{
		if (mat[i][j] == num)
			return true;
		else if (mat[i][j] > num)
			--i;
		else
			++j;
	}
	return false;
}

void test(int n, int mat[NUM][NUM], int num)
{
	if (findNumLowerleft(mat, num))
		printf("Test%2d: Yes\n", n);
	else
		printf("Test%2d: No\n", n);
}

void test1()
{
	int mat[NUM][NUM] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	int num = 7;

	test(1, mat, num);
}

void test2()
{
	int mat[NUM][NUM] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	int num = 5;

	test(2, mat, num);
}

int main(void)
{
	test1();
	test2();

	system("pause");
	return 0;
}
