
# include <iostream>
# include <stdio.h>
# include <stdlib.h>

# define LEN 100

int num = 0;

int sumOfDig(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

bool isSatisfied(int r, int c, int k)
{
	return sumOfDig(r) + sumOfDig(c) <= k ? true : false;
}

// we dont need mat actually
void move(int *mat, int row, int col, int r, int c, int k, bool *visited)
{
	if (row <= 0 || col <= 0 || k < 0) // k should be checked
	{
		printf("Error!\n");
		system("pause");
		exit(-1);
	}

	if (r >= 0 && r < row && c >= 0 && c < col
		&& !visited[r * col + c]
		&& isSatisfied(r, c, k))
	{
		visited[r * col + c] = true;
		num += 1;

		move(mat, row, col, r, c - 1, k, visited);
		move(mat, row, col, r - 1, c, k, visited);
		move(mat, row, col, r, c + 1, k, visited);
		move(mat, row, col, r + 1, c, k, visited);
	}
}

void test_(int n, int *mat, int row, int col, int k)
{
	bool *visited = new bool[row * col];
	memset(visited, 0, row * col);

	num = 0;
	move(mat, row, col, 0, 0, k, visited);
	printf("Test%d: there are %d grids\n", n, num);
	delete[] visited;
}

void test(char* testName, int threshold, int rows, int cols, int expected)
{
	if (testName == nullptr)
		printf("%s begins: ", testName);
	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);
	num = 0;
	move(NULL, rows, cols, 0, 0, threshold, visited);
	if (num == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
	delete[] visited;
}

// ������ж���
void test1()
{
	test("Test1", 5, 10, 10, 21);
}

// ������ж���
void test2()
{
	test("Test2", 15, 20, 20, 359);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test3()
{
	test("Test3", 10, 1, 100, 29);
}

// ����ֻ��һ�У��������ܵ������з���
void test4()
{
	test("Test4", 10, 1, 10, 10);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test5()
{
	test("Test5", 15, 100, 1, 79);
}

// ����ֻ��һ�У��������ܵ������з���
void test6()
{
	test("Test6", 15, 10, 1, 10);
}

// ����ֻ��һ��һ��
void test7()
{
	test("Test7", 15, 1, 1, 1);
}

// ����ֻ��һ��һ��
void test8()
{
	test("Test8", 0, 1, 1, 1);
}

// �����˲��ܽ�������һ������
void test9()
{
	test("Test9", -10, 10, 10, 0);
}

int main(void)
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

	system("pause");
	return 0;
}
