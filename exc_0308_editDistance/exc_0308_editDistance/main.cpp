/*
1.��� a[m] === b[n]����ô����ת��Ϊ��⣺a[1]a[2]...a[m-1] => b[1]b[2]...b[n-1] ����С�༭����
  ��� d[m][n] === d[m-1][n-1]�����磬"xyz" => "pqz" ����С�༭������� "xy" => "pq" ����С�༭���롣
2.��� a[m] !== b[n]���ַ�Ϊ���������
	���磬"xyz" => "efg" ����С�༭������� "xy" => "efg" ����С�༭���� + 1
		����Ϊ����������������һ�� "z"����---------------------------------------������������� d[m][n] === d[m-1][n] + 1��
	���磬"xyz" => "efg" ����С�༭������� "xyzg" => "efg" ����С�༭���� + 1������Ϊ���һ���ַ����� "g"
		���ݵ�һ���ж������������ٵ��� "xyz" => "ef" ����С�༭���� + 1����ˣ��õ����ۣ�"xyz" => "efg"
		����С�༭������� "xyz" => "ef" ����С�༭���� + 1��-----------------------������������ǣ�d[m][n] === d[m][n-1] + 1��
	���磬"xyz" => "efg" ����С�༭������� "xyg" => "efg" ����С�༭���� + 1����Ϊ�����滻���������԰� "g" ���� "z"��
		�ٵ��� "xy" => "ef" �ı༭���� + 1�����ݵ�һ���ж���������-------------------������������ǣ� d[m][n] === d[m-1][n-1] + 1��
��������������п��ܳ��֣���ˣ�ȡ���е���Сֵ���������ϵ���С�༭���롣
��� a �ĳ���Ϊ 0����ô a => b ����С�༭����Ϊ b �ĳ��ȣ������������ b �ĳ���Ϊ 0����ô a => b ����С�༭����Ϊ a �ĳ��ȡ�
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
