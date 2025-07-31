/* 数あてゲーム（その２：当たるまで繰り返す =do文を利用） */

#include<stdio.h>

int main(void)
{
	int no;				/* 読み込んだ数 */
	int ans = 7;		/* 当てさせる数 */
	
	printf("０～９の整数を当ててください。\n\n");
	
	do{
		printf("いくつかな:");
		scanf("%d", &no);
		
		if(no > ans)
			printf("\aもっと小さいよ。\n");
		else if(no < ans)
			printf("\aもっと大きいよ\n");
	} while (no != ans);
	
	printf("正解です。\n");
	
	return 0;
}