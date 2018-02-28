
# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	char str1[] = "hello world";
	char str2[] = "hello world";

	char *str3 = "hello world";
	char *str4 = "hello world";

	if (str1 == str2)
		printf("str1 == str2\n");
	else
		printf("str1 != str2\n");

	if (str3 == str4)
		printf("str3 == str4\n");
	else
		printf("str3 != str4\n");

	if (str1 == str3) // cuz the str1 and str2 are the array, which means they have their own mem
		printf("str1 == str3");
	if (str2 == str3)
		printf("str2 == str3");

	system("pause");
	return 0;
}
