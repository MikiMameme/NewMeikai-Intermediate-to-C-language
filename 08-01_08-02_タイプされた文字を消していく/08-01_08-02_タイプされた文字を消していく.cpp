/*一つの文字列によるキータイピング練習（その２：打った文字が消えていく）*/

#define _CRT_NONSTDC_NO_DEPRECATE

#include<time.h>
#include<stdio.h>
#include<string.h>
#include "getputch.h"

int main(void)
{
	int i;

	/*タイプする文字列*/
	const char *str = "How do you do?";

	/*文字列strの文字数*/
	int len = strlen(str);

	/*開始時刻・終了時刻*/
	clock_t start, end;

	init_getputch();

	printf("このとおりタイプしてください。\n");
	printf("%s\n", str);
	fflush(stdout);

	/*開始時刻*/
	start = clock();

	for (i = 0; i < len; i++) {

		/*str[i]以降を表示してカーソルを先頭へ戻す*/
		printf("%s \r", &str[i]);

		fflush(stdout);
		while (getch() != str[i])
			;
	}

	/*終了時刻*/
	end = clock();

	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;
}