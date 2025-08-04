/*左右方向視野拡大訓練を兼ねた暗算トレーニング*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int stage;
	int a, b, c;
	int x;
	int n;
	clock_t start, end;

	srand(time(NULL));

	printf("視野拡大暗算トレーニング開始\n");
	start = clock();

	for (stage = 0; stage < 10; stage++) {
		a = 10 + rand() % 90;
		b = 10 + rand() % 90;
		c = 10 + rand() % 90;
		n = rand() % 17;

		printf("%d%*s+%*s%d%*s+%*s%d:", a, n, "", n, "", b, n, "", n, "", c);

		do {
			scanf("%d", &x);
			if (x == a + b + c)
				break;
			printf("\a違います、再入力してください :");
		} while (1);
	}

	end = clock();

	printf("%.1f秒かかりました。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}