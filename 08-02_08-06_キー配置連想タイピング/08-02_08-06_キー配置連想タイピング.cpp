/*キー配置連想タイピング練習（タイプする文字を考える）
  A?DFGと表示されたらSをタイプ
  qwe?tと表示されたらrをタイプ*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "getputch.h"

/*練習回数*/
#define NO 30

/*ブロック数*/
#define KTYPE 16

int main(void)
{
	const char* kstr[] = { "12345", "67890-^\\",
						  "!\"#$%", "&'() =~|",
						  "qwert", "yuiop@[",
						  "QWERT", "YUIOP`{",
						  "asdfg", "hjkl;:]",
						  "ASDFG", "HJKL+*}",
						  "zxcvb", "nm,./\\",
						  "ZXCVB", "NM<> _",
	};
	int i, stage;

	/*開始時刻・終了時刻*/
	clock_t start, end;

	init_getputch();

	/*乱数の種を設定*/
	srand(time(NULL));

	printf("キー位置連想タイピング練習を始めます。\n");
	printf("？で隠された文字をタイプしてください。\n");
	printf("スペースキーで開始します。\n");
	fflush(stdout);
	while (getch() != ' ')
		;

	/*開始時刻*/
	start = clock();

	for (stage = 0; stage < NO; stage++) {
		int k, p, key;
		char temp[10];

		do {
			k = rand() % KTYPE;
			p = rand() % strlen(kstr[k]);
			key = kstr[k][p];
		} while (key == ' ');

		strcpy(temp, kstr[k]);
		temp[p] = '?';

		printf("%s", temp);
		fflush(stdout);

		while (getch() != key)
			;
		putchar('\n');
	}

	/*終了時刻*/
	end = clock();

	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;

}