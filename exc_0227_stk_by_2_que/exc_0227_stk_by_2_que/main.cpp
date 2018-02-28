
# include <stdio.h>
# include <stdlib.h>

# define LEN 100

bool first = true;

void test(int act, int exp)
{
	if (act == exp)
	{
		printf("passed!\n");
	}
	else
		printf("failed\n");
}

void push_stk(int *que1, int &h1, int &t1, int *que2, int &h2, int &t2, int num)
{
	if (first)
	{
		que1[h1++] = num;
		first = false;
	}
	else if (h1 == t1 && h2 != t2) // empty queue
	{
		if (h1 > LEN || h1 < t1)
		{
			printf("Out of mem!\n");
			system("pause");
			exit(-1);
		}
		que2[h2++] = num;
	}
	else if (h1 != t1 && h2 == t2)
	{
		if (h2 > LEN || h2 < t2)
		{
			printf("Out of mem!\n");
			system("pause");
			exit(-1);
		}
		que1[h1++] = num;
	}
	else
	{
		printf("Error, there must be at least one empty queue!\n");
		return;
	}
}

int pop_stk(int *que1, int &h1, int &t1, int *que2, int &h2, int &t2)
{
	if (h1 == t1 && h2 != t2)
	{
		while (t2 < h2 - 1)
		{
			que1[h1++] = que2[t2++];
		}
		return que2[t2++];
	}
	else if (h1 != t1 && h2 == t2)
	{
		while (t1 < h1 - 1)
		{
			que2[h2++] = que1[t1++];
		}
		return que1[t1++];
	}
	else if (h1 == t1 && h2 == t2)
	{
		printf("Stack is empty!\n");
		return -1;
	}
	else
	{
		printf("Error, there must be at least one empty queue!\n");
		return -2;
	}
}

int main(void)
{
	int q1[LEN], h1 = 0, t1 = 0;
	int q2[LEN], h2 = 0, t2 = 0;

	push_stk(q1, h1, t1, q2, h2, t2, 1);
	push_stk(q1, h1, t1, q2, h2, t2, 2);
	push_stk(q1, h1, t1, q2, h2, t2, 3);

	int n = pop_stk(q1, h1, t1, q2, h2, t2);
	test(n, 3);

	n = pop_stk(q1, h1, t1, q2, h2, t2);
	test(n, 2);

	push_stk(q1, h1, t1, q2, h2, t2, 4);

	n = pop_stk(q1, h1, t1, q2, h2, t2);
	test(n, 4);

	n = pop_stk(q1, h1, t1, q2, h2, t2);
	test(n, 1);

	n = pop_stk(q1, h1, t1, q2, h2, t2);
	printf("%d", n);
	test(n, -1);

	system("pause");
	return 0;
}
