// ������39�������г��ִ�������һ�������
// ��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���
// ������һ������Ϊ9������{1, 2, 3, 2, 2, 2, 5, 4, 2}����������2��������
// ������5�Σ��������鳤�ȵ�һ�룬������2��

# include <stdio.h>
# include <stdlib.h>

# define LEN 100

bool isValid = true;

bool checkMoreThanHalf(int *arr, int len, int rslt)
{
	int times = 0;
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == rslt)
			times += 1;
	}
	if (times * 2 <= len)
		return false;
	return true;
}

int MoreThanHalfNum(int *arr, int len)
{
	if (!arr || len <= 0)
	{
		printf("Empty array or illegal length!\n");
		isValid = false;
		return -1;
	}

	int rslt = arr[0];
	int times = 1;
	for (int i = 1; i < len; ++i)
	{
		if (times == 0)
		{
			rslt = arr[i];
			times = 1;
		}
		else if (arr[i] == rslt)
			times += 1;
		else
			times -= 1;
	}

	if (!checkMoreThanHalf(arr, len, rslt))
	{
		printf("No such number!\n");
		isValid = false;
		return -1;
	}

	return rslt;
}

// ====================���Դ���====================
void Test(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
	isValid = true;
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
		copy[i] = numbers[i];

	printf("Test for solution1: ");
	int result = MoreThanHalfNum(numbers, length);
	if (result == expectedValue && !isValid == expectedFlag)
		printf("Passed.\n");
	else
		printf("Failed.\n");

	//printf("Test for solution2: ");
	//result = MoreThanHalfNum(copy, length);
	//if (result == expectedValue && isValid == expectedFlag)
	//	printf("Passed.\n");
	//else
	//	printf("Failed.\n");

	delete[] copy;
}

// ���ڳ��ִ����������鳤��һ�������
void Test1()
{
	int numbers[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// �����ڳ��ִ����������鳤��һ�������
void Test2()
{
	int numbers[] = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), -1, true);
}

// ���ִ����������鳤��һ������ֶ������������ǰ�벿��
void Test3()
{
	int numbers[] = { 2, 2, 2, 2, 2, 1, 3, 4, 5 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// ���ִ����������鳤��һ������ֶ�����������ĺ�벿��
void Test4()
{
	int numbers[] = { 1, 3, 4, 5, 2, 2, 2, 2, 2 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// �����ָ��
void Test5()
{
	int numbers[] = { 1 };
	Test("Test5", numbers, 1, 1, false);
}

// �����ָ��
void Test6()
{
	Test("Test6", nullptr, 0, -1, true);
}

int main(int argc, int *argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	system("pause");
	return 0;
}
