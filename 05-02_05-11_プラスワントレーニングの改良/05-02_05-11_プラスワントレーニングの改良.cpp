/*プラスワントレーニング（その４）*/
/*最後のMAX＿RECORDステージの正解数を表示*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEVEL_MIN 2
#define LEVEL_MAX 5
#define MAX_RECORD 10

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
	int i, j, stage, stage2;
	int level;
	int success;
	int point[MAX_RECORD];
	int retry;
	clock_t start, end;

	srand(time(NULL));

	printf("数値を記憶して１を加えた値を入力しましょう。\n");

	do {
		printf("挑戦するレベル（%d～%d）:", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	success = stage = 0;
	start = clock();

	do {
		int no[LEVEL_MAX];
		int x[LEVEL_MAX];
		int seikai = 0;

		printf("\n第%dステージを開始します。\n", stage + 1);

		for (i = 0; i < level; i++) {
			no[i] = rand() % 90 + 10;
			printf("%d ", no[i]);
		}
		fflush(stdout);
		sleep(500 * level);
		printf("\r%*s\r", 3 * level, "");
		fflush(stdout);

		for (i = 0; i < level; i++) {
			printf("%d番目の数 :", i + 1);
			scanf("%d", &x[i]);

		}

		for (i = 0; i < level; i++) {
			if (x[i] != no[i] + 1)
				printf("× ");
			else {
				printf("○ ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++)
			printf("%2d ", no[i]);

		printf(" … %d個正解です。\n", seikai);

		point[stage++ % MAX_RECORD] = seikai;
		success += seikai;

		printf("続けますか？(Yes…1 / No…0) :");
		scanf("%d", &retry);
	} while (retry == 1);
	end = clock();


	printf("\n■□ 成績 □■\n");

	stage2 = stage - MAX_RECORD;
	if (stage2 < 0) stage2 = 0;
	
	for (i = level; i >= 1; i--) {
		for (j = stage2; j < stage; j++)
			if (point[j % MAX_RECORD] >= i)
				printf(" ★ ");
			else
				printf("    ");
		putchar('\n');
	}

	printf("----------------------------------------\n");

	for (j = stage2; j < stage; j++)
		printf("%02d ", j + 1);
	putchar('\n');

	printf("%d個中%d個正解しました。\n", level * stage, success);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}