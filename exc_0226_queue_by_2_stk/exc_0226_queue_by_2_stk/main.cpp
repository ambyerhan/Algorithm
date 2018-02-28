
# include <stdio.h>
# include <stdlib.h>
# include <stack>

# include "CQueue.h"

# define LEN 100

void test(int act, int exp)
{
	if (act == exp)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(void)
{
	CQueue<int> q;

	q.appendTail(1);
	q.appendTail(2);
	q.appendTail(3);

	int act;

	act = q.deleteHead();
	test(act, 1);

	act = q.deleteHead();
	test(act, 2);

	q.appendTail(4);

	act = q.deleteHead();
	test(act, 3);

	q.appendTail(5);

	act = q.deleteHead();
	test(act, 4);

	act = q.deleteHead();
	test(act, 5);

	system("pause");
	return 0;
}
