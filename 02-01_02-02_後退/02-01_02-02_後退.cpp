/* 後退\bの利用例:１秒毎ごとに１文字ずつ消去 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>

/* xミリ秒経過するのを待つ */
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
	int i;

	printf("ABCDEFG");

	for (i = 0; i < 7; i++) {
		sleep(1000);
		printf("\b \b");
		fflush(stdout);
	}

	return 0;
}