/* 数あてゲーム（その３：当てさせる数は0～999の乱数） */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int no;
	int ans;
	
	srand(time(NULL));
	ans = rand() % 1000;
	
	printf("0～999の整数を当ててください。\n\n");
	
	do {
		printf("いくつかな :");
		scanf("%d", &no);
		
		if(no > ans)
			printf("\aもっと小さいよ。\n");
		else if (no < ans)
			printf("\aもっと大きいよ。\n");
	} while(no != ans);
	
	printf("正解です。\n");
	
	return 0;
}