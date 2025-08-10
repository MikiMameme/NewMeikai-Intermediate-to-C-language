/*最大10個の値を読み込んで要素数10の配列に格納*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 10

int main(void)
{
	int i;
	int a[MAX];
	int cnt = 0;
	int retry;

	printf("整数を入力してください。\n");
	printf("入力できるのは最大で%d個です。\n", MAX);

	do {
		printf("%d個目の整数:", cnt + 1);
		scanf("%d", &a[cnt++]);

		if (cnt == MAX)
			break;

		printf("続けますか？(Yes…1 / No…0):");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < cnt; i++)
		printf("%2d個目 : %d\n", i + 1, a[i]);

	return 0;
}