
/*
Learning and testing of STL
*/

# include <stdio.h>
# include <stdlib.h>

# include <iostream>

# include <vector>
# include <queue>
# include <stack>
# include <map>

using namespace std;

/*
push_back(value)	: append to the lsit
pop_back()			: pop the latest one
size()				: get the size
[idx]				: get value on idx
*/
void VectorTest()
{
	vector<int> vec1;

	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);

	int len = vec1.size();
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", vec1[i]);
	}
	printf("\n");

	vec1.push_back(40);
	for (int i = 0; i < vec1.size(); ++i)
	{
		printf("%d ", vec1[i]);
	}
	printf("\n");

	vec1.pop_back();
	vec1.pop_back();
	for (int i = 0; i < vec1.size(); ++i)
	{
		printf("%d ", vec1[i]);
	}
	printf("\n");
}

/*
push:		: append a value to queue
pop:		: del the head value, only delete from head, but can get the head&tail by front&back
back:		: get the tail value
front:		: get the head value
size()		: get the size
*/
void QueueTest()
{
	queue<int> q;

	for (int i = 1; i < 5; ++i)
		q.push(i * 10);

	printf("size : %d\n", q.size());
	printf("front: %d\n", q.front());
	printf("back : %d\n", q.back());
	q.pop();
	printf("size : %d\n", q.size());
	printf("front: %d\n", q.front());
	printf("back : %d\n", q.back());
}

/*
top : get the top value
push: push the value to the top
pop : del the top value
size: get the size
*/
void StackTest()
{
	stack<int> stk;

	stk.push(10);
	stk.push(20);
	stk.push(30);

	int len = stk.size();
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", stk.top());
		stk.pop();
	}
	printf("\n");
}

/*
[key] : get the value of key
count : check if there is a value
*/
void MapTest()
{
	map<int, string> m;

	m[10] = "zero";
	m[20] = "one";
	m[30] = "two";

	printf("map[%d] = %s\n", 0, m[10]);
	printf("map[%d] = %s\n", 1, m[20]);
	printf("map[%d] = %d\n", 4, m.count(30));
	//printf("first: %d, second: %s\n");
}

int main(void)
{
	//VectorTest();
	//QueueTest();
	//StackTest();
	MapTest();

	system("pause");
	return 0;
}