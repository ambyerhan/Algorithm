
/*
平面上有N*M个格子，每个格子中放着一定数量的苹果。你从左上角的格子开始，
每一步只能向下走或是向右走，每次走到一个格子上就把格子里的苹果收集起来，
这样下去，你最多能收集到多少个苹果

from: http://www.hawstein.com/posts/dp-novice-to-advanced.html

!!! use the malloc/free function to allocate or release the mem
*/

# include <stdio.h>
# include <stdlib.h>

# define LEN 100

int getMaxApple(int arr[][LEN], int r, int c)
{
	if (!arr)
	{
		printf("Error!");
		return -1;
	}

	if (r == 1 && c == 1)
		return arr[0][0];

	//int **mat = new int*[r];
	//for (int i = 0; i < r; ++i)
	//	mat[i] = new int[c];
	int **mat = (int **)malloc(sizeof(int *) * r);
	for (int i = 0; i < r; ++i)
		mat[i] = (int *)malloc(sizeof(int) * c);

	mat[0][0] = arr[0][0];
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (i == 0 && j == 0) // the first
				continue;

			if (i == 0 && j > 0) // the horizential edge
				mat[i][j] = mat[i][j - 1] + arr[i][j];
			else if (i > 0 && j == 0) // the vertical edge
				mat[i][j] = mat[i - 1][j] + arr[i][j];
			else // i > 0 && j > 0
				mat[i][j] = (mat[i - 1][j] > mat[i][j - 1] ? mat[i - 1][j] : mat[i][j - 1]) + arr[i][j];
		}
	}

	int max = mat[r - 1][c - 1];

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			printf("%d ", mat[i][j]);
		printf("\n");
	}

	for (int i = 0; i < r; ++i)
		free(mat[i]);
	free(mat);
		//delete[] mat[i];
	//delete[] mat;

	return max;
}

void test()
{
	int arr[LEN][LEN] = { {1, 2, 3, 4, 5},
				          {5, 3, 2, 8, 6},
				          {4, 3, 4, 1, 7} };

	int max = getMaxApple(arr, 3, 5);

	printf("%d\n", max);
}

int main(int argc, int *argv[])
{
	test();

	system("pause");
	return 0;
}
