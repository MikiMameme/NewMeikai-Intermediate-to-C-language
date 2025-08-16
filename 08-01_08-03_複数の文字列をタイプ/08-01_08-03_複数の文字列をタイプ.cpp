/*複数文字列列によるキータイピング練習（その１）*/

#define _CRT_NONSTDC_NO_DEPRECATE

#include<time.h>
#include<stdio.h>
#include<string.h>
#include "getputch.h"

/*問題数*/
#define QNO 12

int main(void)
{
	const char* str[QNO] = { "book", "computer", "default", "comfort",
							"monday", "power", "light", "music",
							"programming", "dog", "video", "include" };

	int i, stage;
	clock_t start, end;

	init_getputch();
	printf("タイピング練習を開始します。\n");
	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < QNO; stage++) {
		int len = strlen(str[stage]);

		for (i = 0; i < len; i++) {

			/*str[stage][i]以降を表示してカーソルを先頭へ戻す*/
			printf("%s \r", &str[stage][i]);

			fflush(stdout);
			while (getch() != str[stage][i])
				;
		}
	}

	end = clock();

	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;
}

