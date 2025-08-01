/* 乱数を生成（その１） */

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int retry;
	
	printf("この処理系では0～%dの乱数が生成できます。\n", RAND_MAX);
	do {
		printf("\n乱数%dを生成しました。\n", rand());
		
		printf("もう一度？ … (0)いいえ (1)はい :");
		scanf("%d", &retry);
	} while(retry == 1);
	
	return 0;
}