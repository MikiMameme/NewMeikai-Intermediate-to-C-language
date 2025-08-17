/*複数文字列によるキータイピング練習（その２：出題順序ランダム「手法２」）*/

#define _CRT_NONSTDC_NO_DEPRECATE

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "getputch.h"

/*問題数*/
#define QNO 12

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

int main(void)
{
	const char* str[QNO] = { "book", "computer", "default", "comfort",
							"monday", "power", "light", "music",
							"programming", "dog", "video", "include" };

	int i, stage;
	int qno[QNO];
	clock_t start, end;

	init_getputch();
	srand(time(NULL));

	/*配列strをシャッフル*/
	for (i = QNO - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		if (i != j)
			swap(const char*, str[i], str[j]);
	}

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

	/*終了時刻*/
	end = clock();

	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;
}