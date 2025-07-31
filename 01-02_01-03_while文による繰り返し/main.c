/* 数あてゲーム（その２「別解」：当たるまで繰り返す = while文を利用する） */

#include<stdio.h>

int main(void)
{
	int no;
	int ans = 7;
	
	printf("０～９の整数を当ててください。\n\n");
	
	while(1) {
		printf("いくつかな :");
		scanf("%d", &no);
		
		if(no > ans)
			printf("\aもっと小さいよ。\n");
		else if(no < ans)
			printf("\aもっと大きいよ。\n");
		else
			break;
	}
	
	printf("正解です。\n");
	
	return 0;
}