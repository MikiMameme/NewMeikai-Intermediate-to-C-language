/* 警報\aと改行\nを出力 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	printf("こんにちは。\n初めまして。\n");
	printf("\a警告します。\n\n");
	printf("\a\a今度は２回警告します。\n");

	return 0;
}