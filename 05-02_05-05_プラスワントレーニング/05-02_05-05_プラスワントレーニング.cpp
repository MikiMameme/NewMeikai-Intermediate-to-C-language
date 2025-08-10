/*プラスワントレーニング（複数の数値を記録して１を加えた値を入力）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STAGE 10
#define LEVEL_MIN 2
#define LEVEL_MAX 6

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
	int level;
	int success;
	int score[MAX_STAGE];
	clock_t start, end;

	srand(time(NULL));

	printf("プラスワントレーニングを開始します\n");
	printf("２桁の数値を記憶します。\n");
	printf("１を加えた値を入力してください。\n");

	do {
		printf("挑戦するレベル（%d～%d）:", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	success = 0;
	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
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

		for(i = 0; i < level; i++) {
			if (x[i] != no[i] + 1)
				printf("✕ ");
			else {
				printf("◯ ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++)
			printf("%2d ", no[i]);

		printf(" … %d個正解です。\n", seikai);
		score[stage] = seikai;
		success += seikai;
	}
	end = clock();

	printf("%d個中%d個正解しました。\n", level * MAX_STAGE, success);

	for (stage = 0; stage < MAX_STAGE; stage++)
		printf("第%2dステージ : %d\n", stage + 1, score[stage]);

	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}