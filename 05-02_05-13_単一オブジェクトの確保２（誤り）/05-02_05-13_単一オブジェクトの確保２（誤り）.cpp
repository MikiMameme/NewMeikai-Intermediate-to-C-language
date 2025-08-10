/*動的に確保した整数にキーボードから読み込んだ値を格納（誤り）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int* x;

	x = (int*)calloc(1, sizeof(int));

	if (x == NULL)
		puts("記憶域の確保に失敗しました。");

	else {
		printf("*xに格納する値 :");
		scanf("%d", &x);
		printf("*x = %d\n", *x);
		free(x);
	}

	return 0;
}