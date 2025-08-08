/*整数値の読込みと表示*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	int x;

	printf("整数を入力してください:");
	scanf("%d", &x);

	printf("%dと入力しましたね。\n", x);

	return 0;
}