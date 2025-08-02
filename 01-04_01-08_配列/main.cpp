/* 数あてゲーム（その５：入力履歴を表示） */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_STAGE 10

int main(void)
{
	int i;
	int stage;
	int no;
	int ans;
	int num[MAX_STAGE];

	srand(time(NULL));
	ans = rand() % 1000;

	printf("０～９９９の整数を当ててください。\n\n");

	stage = 0;
	do {
		printf("残り%d回。いくつかな:", MAX_STAGE - stage);
		scanf("%d", &no);
		num[stage++] = no;

		if (no > ans)
			printf("\aもっと小さいよ。\n");
		else if (no < ans)
			printf("\aもっと大きいよ。\n");
	} while (no != ans && stage < MAX_STAGE);

	if (no != ans)
		printf("\a残念。正解は%dでした。\n", ans);
	else {
		printf("正解です。\n");
		printf("%d回で当たりましたね。\n", stage);
	}

	puts("\n--- 入力履歴 ---");
	for (i = 0; i < stage; i++)
		printf(" %2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);

	return 0;
}