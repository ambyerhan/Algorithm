/*
1.如果 a[m] === b[n]，那么问题转化为求解：a[1]a[2]...a[m-1] => b[1]b[2]...b[n-1] 的最小编辑距离
  因此 d[m][n] === d[m-1][n-1]。比如，"xyz" => "pqz" 的最小编辑距离等于 "xy" => "pq" 的最小编辑距离。
2.如果 a[m] !== b[n]，又分为三种情况：
	比如，"xyz" => "efg" 的最小编辑距离等于 "xy" => "efg" 的最小编辑距离 + 1
		（因为允许插入操作，插入一个 "z"），---------------------------------------抽象的描述便是 d[m][n] === d[m-1][n] + 1。
	比如，"xyz" => "efg" 的最小编辑距离等于 "xyzg" => "efg" 的最小编辑距离 + 1，且因为最后一个字符都是 "g"
		根据第一个判断条件，可以再等于 "xyz" => "ef" 的最小编辑距离 + 1，因此，得到结论："xyz" => "efg"
		的最小编辑距离等于 "xyz" => "ef" 的最小编辑距离 + 1，-----------------------抽象的描述便是：d[m][n] === d[m][n-1] + 1。
	比如，"xyz" => "efg" 的最小编辑距离等于 "xyg" => "efg" 的最小编辑距离 + 1（因为允许替换操作，可以把 "g" 换成 "z"）
		再等于 "xy" => "ef" 的编辑距离 + 1（根据第一个判断条件），-------------------抽象的描述便是： d[m][n] === d[m-1][n-1] + 1。
上述三种情况都有可能出现，因此，取其中的最小值便是整体上的最小编辑距离。
如果 a 的长度为 0，那么 a => b 的最小编辑距离为 b 的长度；反过来，如果 b 的长度为 0，那么 a => b 的最小编辑距离为 a 的长度。
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define DEBUG false

int editDistance(const char *str1, const char *str2)
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
		mat[i] = (int *)malloc(sizeof(int) * (l2 + 1));

	for (int i = 0; i < l1 + 1; ++i)
		mat[i][0] = i;
	for (int i = 0; i < l2 + 1; ++i)
		mat[0][i] = i;

	for (int i = 1; i < l1 + 1; ++i)
	{
		for (int j = 1; j < l2 + 1; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				mat[i][j] = mat[i - 1][j - 1];
			}
			else
			{
				int min = mat[i - 1][j - 1] < mat[i - 1][j] ? mat[i - 1][j - 1] : mat[i - 1][j]; // 
				mat[i][j] = (min < mat[i][j - 1] ? min : mat[i][j - 1]) + 1;
			}
		}
	}

#if DEBUG
	for (int i = 0; i < l1 + 1; ++i)
	{
		for (int j = 0; j < l2 + 1; ++j)
			printf("%3d", mat[i][j]);
		printf("\n");
	}
#endif

	int ed = mat[l1][l2];
	for (int i = 0; i < l1 + 1; ++i)
		free(mat[i]);
	free(mat);

	return ed;
}

void test(int n, const char *s1, const char *s2)
{
	printf("Test[%d] edit_distance = %d\n", n, editDistance(s1, s2));
}

void test1()
{
	char *s1 = "ace";
	char *s2 = "abcdef";

	test(1, s1, s2);
}

void test2()
{
	char *s1 = "a";
	char *s2 = "abcdef";

	test(2, s1, s2);
}

void test3()
{
	char *s1 = "abcdefgh";
	char *s2 = "adgcf";

	test(3, s1, s2);
}

int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}
