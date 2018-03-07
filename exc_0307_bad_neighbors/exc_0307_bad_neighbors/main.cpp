/*
Problem Statement

The old song declares "Go ahead and hate your neighbor", and the residents
of Onetinville have taken those words to heart. Every resident hates his
next-door neighbors on both sides. Nobody is willing to live farther away
from the town's well than his neighbors, so the town has been arranged in
a big circle around the well. Unfortunately, the town's well is in disrepair
and needs to be restored. You have been hired to collect donations for the
Save Our Well fund.

Each of the town's residents is willing to donate a certain amount, as specified
in the int[] donations, which is listed in clockwise order around the well.
However, nobody is willing to contribute to a fund to which his neighbor has also
contributed. Next-door neighbors are always listed consecutively in donations,
except that the first and last entries in donations are also for next-door neighbors.
You must calculate and return the maximum amount of donations that can be collected.

from: https://community.topcoder.com/stat?c=problem_statement&pm=2402&rd=5009
*/


# include <stdio.h>
# include <stdlib.h>

# define LEN 100

int findMax(int a, int b)
{
	return a > b ? a : b;
}

int findMin(int a, int b)
{
	return a > b ? b : a;
}

int badNeighbours(int *a, int size) {

	if (size == 2) {
		int sum = findMax(a[0], a[1]);
		return sum;
	}

	int i, j;
	int *s = (int *)malloc(sizeof(int)*size);
	int *b = (int *)malloc(sizeof(int)*size);
	s[0] = a[0];
	s[1] = a[1];
	b[0] = 1;
	b[1] = 0;
	for (i = 2; i<size; i++) {
		s[i] = 0;
		b[i] = 0;
	}

	for (i = 2; i<size; i++) {
		for (j = 0; j<i - 1; j++) {
			if (s[i]<s[j] + a[i]) {
				s[i] = s[j] + a[i];
				b[i] = b[j];
			}
		}
	}

	if (b[size - 1] == 0) {
		return s[size - 1];
	}
	else {
		int min = findMin(a[0], a[size - 1]);
		int sum = findMax(s[size - 2], s[size - 1] - min);
		return sum;
	}
	return 0;
}

int badNeighbours_(int *a, int n) // todo: the right answer
{
	if (!a)
	{
		printf("Error!");
		return -1;
	}

	if (n == 0)
		return 0;
	if (n == 1)
		return a[0];
	if (n == 2)
		return findMax(a[0], a[1]);

	int (*mat)[2] = new int[n][2]; // mat[i][0]: start from 0, 2, ..., mat[i][1]: start from 1, ...
	mat[1][0] = a[0];
	mat[1][1] = a[1];
	mat[2][0] = findMax(a[0], a[1]);
	mat[2][1] = findMax(a[1], a[2]);

	for (int i = 3; i < n; ++i)
	{
		mat[i][0] = findMax(mat[i - 1][0], mat[i - 2][0] + a[i - 1]);
		mat[i][1] = findMax(mat[i - 1][1], mat[i - 2][1] + a[i]);
	}

	return findMax(mat[n - 1][0], mat[n - 1][1]);
}

void test(int n, int *a, int len)
{
	printf("[%d] %d\n", n, badNeighbours_(a, len));
}

void test1()
{
	int arr[LEN] = {100, 1, 1, 100, 1};
	int len = 5;
	test(1, arr, len);
}

void test2()
{
	int arr[LEN] = { 10, 3, 2, 5, 7, 8 };
	int len = 6;
	test(2, arr, len);
}

void test3()
{
	int arr[LEN] = { 11, 15 };
	int len = 2;
	test(3, arr, len);
}

void test4()
{
	int arr[LEN] = { 7, 7, 7, 7, 7, 7, 7 };
	int len = 7;
	test(4, arr, len);
}

void test5()
{
	int arr[LEN] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	int len = 10;
	test(5, arr, len);
}

void test6()
{
	int arr[LEN] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
		6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
		52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
	int len = 40;
	test(6, arr, len);
}

int main(int argc, int *argv[])
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
