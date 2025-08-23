/*文字列を動的に確保*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char st[16];
	char *pt;

	printf("文字列stを入力してください :");
	scanf("%s", st);

	/*記憶域を動的に確保*/
	/*C++のコンパイラのため明示的なキャストが必要*/
	pt = (char *) malloc(strlen(st) + 1);

	if (pt) {
		strcpy(pt, st);
		printf("その文字列の複製ptを作りました\n");
		printf("st = %s\n", st);
		printf("pt = %s\n", pt);
		/*記憶域を開放*/
		free(pt);
	}

	return 0;
}