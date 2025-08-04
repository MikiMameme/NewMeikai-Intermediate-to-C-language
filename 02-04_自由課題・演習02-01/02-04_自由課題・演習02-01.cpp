/*カウントダウン後にプログラム実行時間とクロック数をを表示する（演習2-1）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>

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
	int i;
	clock_t c;
	for (i = 10; i > 0; i--) {
		printf("\r%2d", i);
		fflush(stdout);
		sleep(1000);
	}

	printf("\r\aFIRE!\n");
	c = clock();

	printf("クロック数 :%ld\n", c);
	printf("プログラム開始から%.1f秒経過しました。\n",
		(double)c / CLOCKS_PER_SEC);
	return 0;
}