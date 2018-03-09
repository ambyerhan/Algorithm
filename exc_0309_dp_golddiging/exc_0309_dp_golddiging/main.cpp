
/*
question：
	   有一个国家发现了5座金矿，每座金矿的黄金储量不同，需要参与挖掘的工人数量也不同。
	参与挖矿工人的总数是10人。每座金矿要么全挖，要么不挖。要求用程序求解出，要想得到尽可能
	多的黄金，应该选择挖取哪几座金矿？

answer：
	N：金矿数量，     W：工人数量
	G：每座黄金储量，  P：每座黄金需人数

	 		  | 0,                                           N == 0 || W == 0 || (N == 1 && W < P[N]) （没有金矿|工人|有一个金矿但人数不够）
	F(N, W) = | G[0],                                        N == 1 && W >= P[N] （有一个金矿，且人数够挖）
			  | F(N - 1, W),                                 N > 1 && W < P[N] （有多个金矿， 且当前人数不够挖当前金矿，则等于不挖当前金矿时的情况）
			  | max{F(N - 1, W), F(N - 1, W - P[N]) + G[N]}, N > 1 && W >= P[N] （有多个金矿，且当前人数够挖当前金矿，则取“挖当前金矿”和“不挖当前金矿”时情况的较大者）
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define DEBUG true
# define LEN 100

/*
 G: the num of gold of every gold mine
 P: the num of worker, which need to dig a gold mine
 len: len of G and P
 N: num of gold mine
 W: num of worker
*/
int maxGoldDig(int *G, int *P, int len, int N, int W)
{
	if (!G || !P || len < 0 || N < 0 || W < 0)
	{
		printf("Error\n");
		return -1; // -1 means illegal input
	}

	int *mat = (int *)malloc(sizeof(int) * (N + 1) * (W + 1));
	memset(mat, 0, (W + 1) * (N + 1));

	int col = W + 1;
	for (int i = 0; i < N + 1; ++i) // gold mine num
	{
		for (int j = 0; j < W + 1; ++j) // worker num
		{
			if (i == 0 || j == 0 || (i == 1 && j < P[i - 1]))
				mat[i * col + j] = 0;
			else if (i == 1 && j >= P[i - 1])
			{
				mat[i * col + j] = G[i - 1];
			}
			else if (i > 1 && j < P[i - 1])
			{
				mat[i * col + j] = mat[(i - 1) * col + j];
			}
			else if (i > 1 && j >= P[i - 1])
			{
				mat[i * col + j] = (mat[(i - 1) * col + (j - P[i - 1])] + G[i - 1]) > (mat[(i - 1) * col + j]) ? \
					(mat[(i - 1) * col + (j - P[i - 1])] + G[i - 1]) : (mat[(i - 1) * col + j]);
			}
		}
	}
#if DEBUG
	for (int i = 0; i < N + 1; ++i)
	{
		for (int j = 0; j < W + 1; ++j)
		{
			printf("%3d ", mat[i * col + j]);
		}
		printf("\n");
	}
#endif

	int max_gold = mat[N * col + W];
	free(mat);
	return max_gold;
}

void test(int n, int *G, int *P, int N, int W)
{
	int max = maxGoldDig(G, P, N, N, W);
	printf("Test[%d] %d\n", n, max);
}

void test1()
{
	int G[LEN] = { 400, 500, 200, 300, 350 };
	int P[LEN] = { 5, 5, 3, 4, 3 };
	int N = 5;
	int W = 10;
	test(1, G, P, N, W);
}

int main(int argc, int *argv[])
{
	test1();

	system("pause");
	return 0;
}
