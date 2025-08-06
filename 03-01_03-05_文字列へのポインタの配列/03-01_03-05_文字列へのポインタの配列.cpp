/*文字列の配列（2次元配列）*/

#include<stdio.h>

int main(void)
{
	int i;
	char a[][6] = {
		"Super", "X", "TRY"
	};

	for (i = 0; i < 3; i++)
		printf("%s\n", a[i]);

	return 0;
}