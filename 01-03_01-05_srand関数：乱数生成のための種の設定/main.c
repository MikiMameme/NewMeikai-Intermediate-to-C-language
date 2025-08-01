/* 乱数を生成（その２：現在の時刻に基づいて乱数の種を設定） */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int retry;
	
	srand(time(NULL));
	
	printf("この処理系では0～%dの乱数が生成できます。\n", RAND_MAX);
	
	do{
		printf("\n乱数%dを生成しました。\n", rand());
		
		printf("もう一度？…(0)いいえ (1)はい :");
		scanf("%d", &retry);
	} while (retry == 1);
	
	return 0;
}