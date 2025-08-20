/*ラックナンバーサーチ・トレーニング（その３：前回の日時・最高得点を表示）*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<float.h>
#include "getputch.h"

/*挑戦回数*/
#define MAX_STAGE 10
#define swap(type, x, y)	do{type t = x; x = y; y = t; } while (0)

/*ファイル名*/
char dtfile[] = "LACKNUM.DAT";

/*前回のトレーニング情報を取得・表示して最高得点を返す*/
double get_data(void)
{
	FILE *fp;

	/*最高得点*/
	double best;

	if ((fp = fopen(dtfile, "r")) == NULL) {
		printf("本プログラムを実行するのは初めてですね\n\n");
		best = DBL_MAX;
	}
	else {
		int year, month, day, h, m, s;

		fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
		fscanf(fp, "%lf", &best);
		printf("前回の終了は%d年%d月%d日%d時%d分%d秒でした。\n",
			year, month, day, h, m, s);

		printf("っこれまでの最高得点（最短所要時間）は%.1f秒です。\n\n", best);
		fclose(fp);
	}
	return best;
}

/*今回のトレーニング情報を書き込む*/
void put_data(double best)
{
	FILE *fp;
	time_t t = time(NULL);
	struct tm* local = localtime(&t);

	if ((fp = fopen(dtfile, "w")) == NULL)
		printf("エラーが発生しました。");
	else {
		fprintf(fp, "%d %d %d %d %d %d\n",
			local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
			local->tm_hour, local->tm_min, local->tm_sec);

		fprintf(fp, "%f\n", best);
		fclose(fp);
	}
}

/*トレーニングを実行して得点（所要時間）を返す*/
double go(void)
{
	int i, j, stage;
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8];
	double jikan;
	clock_t start, end;

	printf("欠けている数字を入力してください。\n");
	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	start = clock();
	
	for (stage = 0; stage < MAX_STAGE; stage++) {
		/*０～８の乱数を生成*/
		int x = rand() % 9;
		/*読み込んだ値*/
		int no;

		i = j = 0;
		/*dgt[x]を飛ばしてコピー*/
		while (i < 9) {
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}
		for (i = 7; i > 0; i--) {
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		/*全要素を表示*/
		for (i = 0; i < 8; i++)
			printf("%d ", a[i]);
		printf(" : ");
		fflush(stdout);

		do {
			no = getch();
			/*表示可能であれば*/
			if (isprint(no)) {
				putch(no);
				if (no != dgt[x] + '0')
					putch('\b');
				else
					printf("\n");
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 30.0)
		printf("鈍すぎます。\n");
	else if (jikan > 25.0)
		printf("少し鈍いですね。\n");
	else if (jikan > 20.0)
		printf("まあまあですね。。\n");
	else
		printf("素早いですね。\n");

	return jikan;
}

int main(void)
{
	/*もう一度？*/
	int retry;
	/*得点（所要時間）*/
	double score;
	/*最高得点（最短所要時間）*/
	double best;

	/*前回までの最高得点を得る*/
	best = get_data();

	init_getputch();

	/*乱数の種を設定*/
	srand(time(NULL));

	do {
		/*トレーニン実行*/
		score = go();

		if (score < best) {
			printf("最高得点（所要時間）を更新しました。\n");
			/*最高得点更新*/
			best = score;
		}

		printf("もう一度しますか？... （０）いいえ　（１）はい :");
		scanf("%d", &retry);
	} while (retry == 1);

	/*今回の日付・時刻・得点を書き込む*/
	put_data(best);

	term_getputch();

	return 0;
}