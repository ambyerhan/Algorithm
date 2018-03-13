/*
longest commen sub-sequence
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define LEN 100
# define DEBUG true

int max(int a, int b)
{
	return a > b ? a : b;
}

int lcs_func(const char *s1, const char *s2)
{
	if (!s1 || !s2)
	{
		printf("Error!\n");
		return -1;
	}

	int l1 = strlen(s1);
	int l2 = strlen(s2);

	int **lcs_mat = (int **)malloc(sizeof(int *) * (l1 + 1));
	for (int i = 0; i < (l1 + 1); ++i)
	{
		lcs_mat[i] = (int *)malloc(sizeof(int) * (l2 + 1));
		memset(lcs_mat[i], 0, sizeof(int) * (l2 + 1));
	}

	// dp
	for (int i = 0; i < l1 + 1; ++i)
		lcs_mat[i][0] = 0;
	for (int i = 0; i < l2 + 1; ++i)
		lcs_mat[0][i] = 0;

	for (int i = 1; i < l1 + 1; ++i)
	{
		for (int j = 1; j < l2 + 1; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				lcs_mat[i][j] = lcs_mat[i - 1][j - 1] + 1;
			}
			else
			{
				lcs_mat[i][j] = max(lcs_mat[i - 1][j], lcs_mat[i][j - 1]);
			}
		}
	}
	//

#if DEBUG
	for (int i = 0; i < l1 + 1; ++i)
	{
		for (int j = 0; j < l2 + 1; ++j)
		{
			printf("%4d", lcs_mat[i][j]);
		}
		printf("\n");
	}
#endif

	int lcs_max = lcs_mat[l1][l2];
	for (int i = 0; i < l1 + 1; ++i)
		free(lcs_mat[i]);
	free(lcs_mat);

	return lcs_max;
}

void test(int i, const char *s1, const char *s2)
{
	printf("Test[%d] lcs = %d\n", i, lcs_func(s1, s2));
}

void test1()
{
	char s1[] = "ABCBDAB";
	char s2[] = "BDCABA";

	test(1, s1, s2);
}

int main(int argc, int *argv[])
{
	test1();

	system("pause");
	return 0;
}
