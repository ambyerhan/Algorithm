
# include <stdio.h>
# include <stdlib.h>
# define NUM 7

void getRepeat(int arr[], int len)
{
	if (arr == NULL || len <= 0) // err1: no checking
	{
		printf("Error\n");
		return;
	}

	for (int i = 0; i < len; ++i) // err2: no checking
	{
		if (arr[i] >= len || arr[i] < 0)
		{
			printf("Error2\n");
			return;
		}
	}

	for (int i = 0; i < len; )
	{
		if (arr[i] == i)
		{
			++i;
			continue;
		}
		else
		{
			if (arr[arr[i]] == arr[i])
			{
				printf("%d is a repeated num\n", arr[i]);
				break;
			}
			else
			{
				int tmp = arr[arr[i]];
				arr[arr[i]] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

 // the answer
bool duplicate(int numbers[], int len, int *duplication)
{
	if (numbers == NULL || len <= 0)
	{
		return false;
	}
	
	for (int i = 0; i < len; ++i)
	{
		if (numbers[i] < 0 || numbers[i] >= len)
		{
			return false;
		}
	}

	for (int i = 0; i < len; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}

			int tmp = numbers[numbers[i]];
			numbers[numbers[i]] = numbers[i];
			numbers[i] = tmp;
		}
	}
	return false;
}

// get the repeat num without modifing the array
void getRepeat_v2(int arr[], int len)
{
	int *tmp_arr = (int *)malloc(sizeof(int) * len);
	for (int i = 0; i < len; ++i)
	{
		if (tmp_arr[arr[i]] != arr[i])
			tmp_arr[arr[i]] = arr[i];
		else
		{
			printf("find a repeat num %d\n", arr[i]);
			break;
		}
	}
}

int main(void)
{
	int arr[] = { 2, 3, 1, 0, 2, 5, 3 };

	//
	//getRepeat(arr, NUM);
	//

	getRepeat_v2(arr, NUM);

	system("pause");
	return 0;
}
