/*単純記憶トレーニング（数値を記憶：レベル＝桁数の設定あり）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_STAGE 10	/*ステージ数*/
#define LEVEL_MIN 3		/*桁数（最小レベル）*/
#define LEVEL_MAX 20	/*桁数（最大レベル）*/

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
	int i, stage;
	int level;			/*レベル（数値の桁数）*/
	int success = 0;	/*正解数*/
	clock_t start, end;	/*開始時刻・終了時刻*/

	srand(time(NULL));	/*乱数の種を設定*/

	printf("数値記憶トレーニング\n");

	do {
		printf("挑戦するレベル(%d～%d) :", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	printf("%d桁の数値を記憶しましょう。\n", level);

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char no[LEVEL_MAX + 1];		/*記憶すべき数字の並び*/
		char x[LEVEL_MAX * 2];		/*読み込んだ数字の並び*/

		no[0] = '1' + rand() % 9;	/*先頭文字は１～９*/
		for (i = 1; i < level; i++)
			no[i] = '0' + rand() % 10;	/*それ以降は０～９*/
		no[level] = '\0';

		printf("%s", no);
		fflush(stdout);
		sleep(200 * level);		/*問題提示は200×levelミリ秒*/

		printf("\r%*s\r入力せよ :", level, "");
		scanf("%s", x);

		if (strcmp(no, x) != 0)
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