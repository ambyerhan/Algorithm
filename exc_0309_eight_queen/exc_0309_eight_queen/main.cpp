
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# define LEN 100
# define N 8 // eight queen

int total = 0;

void eight_queen(int *queen, int idx)
{
	if (idx == N)
	{
		total += 1;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (queen[i] == j)
					printf("* ");
				else
					printf(". ");
			}
			printf("\n");
		}
		printf("-------------------\n");
		return;
	}

	for (int j = 0; j < N; ++j) // check from first col to last col
	{
		bool canBeSet = true;
		for (int i = 0; i < idx; ++i) // check pre queens from first row to current row(not include current row)
		{
			if (queen[i] == j || (abs(queen[i] - j) == abs(idx - i)) || (queen[i] + i) == (j + idx)) // not in a col or slash or back slash
			{
				canBeSet = false;
				break; // position(idx, j) is not work
			}
		}
		if (canBeSet)
		{
			queen[idx] = j; // set current queen and go next row
			eight_queen(queen, idx + 1);
		}
	}
}

int main(int argc, int *argv[])
{
	int *queen = (int *)malloc(sizeof(int) * N);
	memset(queen, 0, N);

	eight_queen(queen, 0);

	printf("total = %d\n", total);
	system("pause");
	return 0;
}
