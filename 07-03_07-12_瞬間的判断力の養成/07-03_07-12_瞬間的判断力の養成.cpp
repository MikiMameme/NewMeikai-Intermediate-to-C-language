/*トライグラフ連想トレーニング（数字・英字の3文字の並びを完成させる）*/

#define _CRT_NONSTDC_NO_DEPRECATE

#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "getputch.h"

#define MAX_STAGE 20	/*挑戦回数*/
#define swap(type, x, y)	do{type t = x; x = y; y = t; } while (0)

int main(void)
{
	const char *qstr[] = { "0123456789",
						"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
						"abcdefghijklmnopqrstuvwxyz",
						};
	int chmax[] = { 10, 26, 26 };
	int i, stage;
	int key;
	double jikan;
	clock_t start, end;

	init_getputch();

	srand(time(NULL));	/*乱数の種を設定*/

	printf("□連続する三つの数字あるいは英字から\n");
	printf("□隠されている文字を入力してください。\n");
	printf("□たとえば A ? C : と表示されたらBを\n");
	printf("□         4 5 ? : と表示されたら6を\n");
	printf("□入力します。\n");
	printf("★スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int qtype = rand() % 3;
		int nhead = rand() % (chmax[qtype] - 2);
		int x = rand() % 3;

		putchar('\r');
		/*問題を表示*/
		for(i = 0; i < 3; i++) {
			if (i != x)
				printf(" %c", qstr[qtype][nhead + i]);
			else
				printf(" ?");
		}
		printf(" : ");
		fflush(stdout);

		do {
			key = getch();
			if (isprint(key)) {
				putch(key);
				if (key != qstr[qtype][nhead + x])
					putch('\b');
				
				/*改行*/
				else
					putch('\n');
			}
		} while (key != qstr[qtype][nhead + x]);
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\n%.1f秒かかりました\n", jikan);

	if (jikan > 60)
		printf("鈍すぎます。\n");
	else if (jikan > 50)
		printf("少し鈍いですね。\n");
	else if (jikan > 40)
		printf("まあまあですね。\n");
	else
		printf("素早いですね。\n");

	term_getputch();

	return 0;
 
}