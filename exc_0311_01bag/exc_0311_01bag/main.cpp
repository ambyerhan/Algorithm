
# include <stdio.h>
# include <stdlib.h>

# define DEBUG true

int max(int a, int b)
{
	return a > b ? a : b;
}

/*
itemNum: the number of items, i.e., len of V&W
Weight : the max weight of bag can handle
V      : the values of items
W      : the weights of items
*/
int maxValue(int itemNum, int Weight, int *V, int *W)
{
	if (itemNum <= 0 || Weight <= 0 || !V || !W)
	{
		printf("Error!\n");
		return -1; // -1 means illegal inputs
	}

	int **mat = (int **)malloc(sizeof(int *) * itemNum);
	for (int i = 0; i < itemNum; ++i)
	{
		mat[i] = (int *)malloc(sizeof(int) * (Weight + 1));
	}

	for (int i = 0; i < itemNum; ++i)
	{
		for (int j = 0; j < Weight + 1; ++j)
		{
			if (i == 0 && j < W[i]) // the first row
			{
				mat[i][j] = 0;
			}
			else if (i == 0 && j >= W[i]) // the first row, if the mat's shape is [itemNum + 1, Weight + 1], then this is not necessary
			{
				mat[i][j] = V[i];
			}
			else if (i >= 1 && j < W[i])
			{
				mat[i][j] = mat[i - 1][j];
			}
			else if (i >= 1 && j >= W[i])
			{
				mat[i][j] = max(mat[i - 1][j], mat[i - 1][j - W[i]] + V[i]);
			}
			else
				;
		}
	}

#if DEBUG
	for (int i = 0; i < itemNum; ++i)
	{
		for (int j = 0; j < Weight + 1; ++j)
		{
			printf("%3d ", mat[i][j]);
		}
		printf("\n");
	}
#endif

	int maxV = mat[itemNum - 1][Weight];
	for (int i = 0; i < itemNum; ++i)
		free(mat[i]);
	free(mat);

	return maxV;
}

void test(int n, int itemNum, int Weight, int *V, int *W)
{
	printf("Test[%d] %d\n", n, maxValue(itemNum, Weight, V, W));
}

void test1()
{
	int v[] = { 6, 3, 5, 4, 6 };
	int w[] = { 2, 2, 6, 5, 4 };
	int in = 5;
	int we = 10;

	test(1, in, we, v, w);
}

int main(void)
{
	test1();

	system("pause");
	return 0;
}
