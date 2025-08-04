/*数字文字を1桁ずつずらしながら表示（その２）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	int i;
	int x;

	printf("何段表示しますか :");
	scanf("%d", &x);

	for (i = 1; i <= x; i++) {
		printf("%*d\n", i, i % 10);
	}

	return 0;
}