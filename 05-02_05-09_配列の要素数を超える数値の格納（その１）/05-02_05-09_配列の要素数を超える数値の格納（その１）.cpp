/*好きな個数だけ値を読み込んで要素数10の配列に最後の10個を格納（その１）*/
/*好きなだけ入力できるけど、最後の10個だけ格納する*/

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

	do {
		if (cnt >= MAX) {
			for (i = 0; i < MAX - 1; i++)
				a[i] = a[i + 1];
		}
		printf("%d個目の整数:", cnt + 1);
		scanf("%d", &a[cnt < MAX ? cnt: MAX - 1]);
		cnt++;

		printf("続けますか？（Yes…1 / No…0) :");
		scanf("%d", &retry);
	} while (retry == 1);

	if (cnt <= MAX)
		for (i = 0; i < cnt; i++)
			printf("%2d個目 :%d\n", i + 1, a[i]);
	else
		for (i = 0; i < MAX; i++)
			printf("%2d個目 :%d\n", cnt - MAX + 1 + i, a[i]);
	return 0;
}