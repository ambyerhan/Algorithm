
# include <stdio.h>
# include <stdlib.h>

# include <string.h>

# define DEBUG true

int max(int a, int b)
{
	return a > b ? a : b;
}

int lcs(const char *str1, const char *str2)
{
	if (!str1 || !str2)
	{
		printf("Error!\n");
		return -1; 
	}

	int l1 = strlen(str1);
	int l2 = strlen(str2);

	int **mat = (int **)malloc(sizeof(int *) * (l1 + 1));
	for (int i = 0; i < l1 + 1; ++i)
	{
		mat[i] = (int *)malloc(sizeof(int) * (l2 + 1));
		memset(mat[i], 0, sizeof(int) * (l2 + 1));
	}

	// dp
	for (int i = 1; i < l1 + 1; ++i)
	{
		for (int j = 1; j < l2 + 1; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				mat[i][j] = mat[i - 1][j - 1] + 1;
			}
			else
			{
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
			}
		}
	}
	//

#if DEBUG
	for (int i = 0; i < l1 + 1; ++i)
	{
		for (int j = 0; j < l2 + 1; ++j)
			printf("%3d", mat[i][j]);
		printf("\n");
	}
#endif

	int max = mat[l1][l2];
	for (int i = 0; i < l1 + 1; ++i)
		free(mat[i]);
	free(mat);

	return max;
}

void test(int i, const char *s1, const char *s2)
{
	printf("Test[%d] lcs = %d\n", i, lcs(s1, s2));
}

void test1()
{
	char *s1 = "Hello world";
	char *s2 = "worhello d";

	test(1, s1, s2);
}

int main(void)
{
	test1();

	system("pause");
	return 0;
}
