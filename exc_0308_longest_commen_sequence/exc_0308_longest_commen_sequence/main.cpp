
/*
In the longest-common-subsequence problem, we are given two sequences
X=<x1,x2,...,xm> and Y=<y1,y2,...,yn> and wish to find a (not ¡°the¡±)
maximum-length common subsequence of X and Y . This section shows how
to efficiently solve the LCS problem using dynamic programming.

from : http://blog.csdn.net/so_geili/article/details/53737001
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define DEBUG false

# define LEN 100

int longest_commen_sequence(const char *str1, const char *str2, const int len1, const int len2)
{
	if (!str1 || !str2)
	{
		printf("Error!\n");
		return -1; // -1 means the unvalid input
	}

	int **mat = (int **)malloc(sizeof(int *) * (len1 + 1)); // mat store the lcs value of each sub-sequences
	for (int i = 0; i < len1 + 1; ++i)
		mat[i] = (int *)malloc(sizeof(int) * (len2 + 1));

	for (int i = 0; i < len1 + 1; ++i)
		mat[i][0] = 0;
	for (int i = 0; i < len2 + 1; ++i)
		mat[0][i] = 0;

	for (int i = 1; i < len1 + 1; ++i)
	{
		for (int j = 1; j < len2 + 1; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else // (str1[i - 1] != str2[i - 1])
				mat[i][j] = (mat[i][j - 1] > mat[i - 1][j] ? mat[i][j - 1] : mat[i - 1][j]);
		}
	}
#if DEBUG
	for (int i = 0; i < len1 + 1; ++i)
	{
		for (int j = 0; j < len2 + 1; ++j)
			printf("%3d ", mat[i][j]);
		printf("\n");
	}
#endif

	int lcs = mat[len1][len2];
	for (int i = 0; i < len1 + 1; ++i)
		free(mat[i]);
	free(mat);

	return lcs;
}

void test(int n, const char *str1, const char *str2, const int len1, const int len2)
{
	printf("[Test:%d] lcs = %d\n", n, longest_commen_sequence(str1, str2, len1, len2));
}

void test1()
{
	char *str1 = "elHso";
	char *str2 = "hello";
	test(1, str1, str2, strlen(str1), strlen(str2));
}

void test2()
{
	char *str1 = "Hello world";
	char *str2 = "world hello";
	test(2, str1, str2, strlen(str1), strlen(str2));
}

int main(int argc, int *argv[])
{
	test1();
	test2();

	system("pause");
	return 0;
}
