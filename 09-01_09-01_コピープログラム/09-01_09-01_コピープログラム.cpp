/*入力された文字をそのまま出力*/

#include<stdio.h>

int main(void)
{
	int ch;

	while ((ch = getchar()) != EOF)
		putchar(ch);

	return 0;
}