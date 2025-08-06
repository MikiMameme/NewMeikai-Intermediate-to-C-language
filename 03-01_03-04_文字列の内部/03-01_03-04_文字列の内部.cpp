/*文字列内の文字を１６進数と２進数で表示*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<ctype.h>
#include<limits.h>

/*文字列内の文字を１６進数と２進数で表示*/
void strdump(const char* s)
{
	while (*s) {
		int i;
		unsigned char x = (unsigned char)*s;

		printf("%c  ", isprint(x) ? x : ' ');
		printf("%0*x ", (CHAR_BIT + 3) / 4, x);
		for (i = CHAR_BIT - 1; i >= 0; i--)
			putchar(((x >> i) & 1U) ? '1' : '0');
		putchar('\n');
		s++;
	}
}

int main(void)
{
	puts("漢字");        strdump("漢字");        putchar('\n');
	puts("12日本語AB");  strdump("12日本語AB");  putchar('\n');

	return 0;
}