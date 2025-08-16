/*ラックナンバーサーチ（その２：リアルタイム入力版）*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include "getputch.h"

/*挑戦回数*/
#define MAX_STAGE 10
#define swap(type, x, y)	do{type t = x; x = y; y = t; } while (0)

int main(void)
{
	int i, j, stage;
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8];
	/*時間*/
	double jikan;
	/*開始時刻・終了時刻*/
	clock_t start, end;

	init_getputch();
	/*乱数の種を設定*/
	srand(time(NULL));

	printf("欠けている数字を入力してください。\n");
	printf("スペースキーで開始します。\n");
	fflush(stdout);

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

		/*配列aをシャッフル*/
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
			if (isprint(no)) {
				putch(no);
				if (no != dgt[x] + '0')
					putch('\b');  /*間違いの場合はバックスペース*/
				else
					putch('\n');  /*正解の場合は改行*/
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
		printf("まあまあですね。\n");
	else
		printf("素早いですね。\n");

	term_getputch();
	return 0;
}