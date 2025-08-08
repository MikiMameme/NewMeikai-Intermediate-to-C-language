/*文字列として読み込んだ整数を変換して表示*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char temp[20];

	printf("整数を入力してください:");
	scanf("%s", temp);

	printf("%dと入力しましたね。\n", atoi(temp));

	return 0;
}