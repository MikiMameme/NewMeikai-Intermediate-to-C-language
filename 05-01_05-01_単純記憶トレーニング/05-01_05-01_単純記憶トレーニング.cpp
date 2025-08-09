/*単純記憶トレーニング（4桁の数値を記憶）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STAGE 10

/*xミリ秒経過するのを待つ*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;
	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int stage;
	int success = 0;
	clock_t start, end;

	srand(time(NULL));

	printf("4桁の数値を記憶しましょう\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x;
		int no = rand() % 9000 + 1000;

		printf("%d", no);
		fflush(stdout);
		sleep(500);

		printf("\r入力せよ :");
		fflush(stdout);
		scanf("%d", &x);

		if (x != no)
			printf("\a間違いです。\n");
		else {
			printf("正解です。\n");
			success++;
		}
	}
	end = clock();

	printf("%d回中%d回成功しました。\n", MAX_STAGE, success);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}