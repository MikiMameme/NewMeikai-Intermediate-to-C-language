/*文字列の配列を動的に確保*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num;
	char (*p)[15];

	printf("文字列は何個ですか :");
	scanf("%d", &num);

	p = (char(*)[15])malloc(num * 15);
	if (p == NULL)
		puts("記憶域の確保に失敗しました");
	else {
		int i;
		for (i = 0; i < num; i++) {
			printf("p[%d] :", i);
			scanf("%s", p[i]);
		}
		for (i = 0; i < num; i++)
			printf("p[%d] = %s\n", i, p[i]);

		free(p);
	}

	return 0;
}