/*整数配列を動的に確保*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int* x;
	int n;

	printf("確保する配列の要素 :");
	scanf("%d", &n);

	x = (int*)calloc(n, sizeof(int));

	if (x == NULL)
		puts("記憶域の確保に失敗しました。");
	else {
		int i;

		for (i = 0; i < n; i++)
			x[i] = i;

		for (i = 0; i < n; i++)
			printf("x[%d] = %d\n", i, x[i]);

		free(x);
	}

	return 0;
}