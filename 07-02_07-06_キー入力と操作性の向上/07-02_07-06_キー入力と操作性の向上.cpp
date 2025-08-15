/*getchの活用例
 Visual C++などのMS-DOS / Windowsで動作*/

#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<conio.h>
#include<ctype.h>

int main(void)
{
	int ch;
	int retry;

	do {
		printf("キーを押してください。");
		ch = getch();

		printf("\n押されたキーは%cで値は%dです。\n", 
											isprint(ch) ? ch : ' ', ch);

		printf("もう一度？(Y/N) :");
		retry = getch();
		if (isprint(retry))
		putch(retry);

		putchar('\n');
	} while (retry == 'Y' || retry == 'y');

	return 0;
}