/*暗算能力チェック（０～９９の整数を４つ加算するのに要する時間を計測）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int a, b, c, d;
	int x;
	time_t start, end;

	srand(time(NULL));

	a = rand() % 100;
	b = rand() % 100;
	c = rand() % 100;
	d = rand() % 100;

	printf("%d + %d + %d + %dは何ですか :", a, b, c, d);

	start = time(NULL);

	while (1) {
		scanf("%d", &x);
		if (x == a + b + c + d)
			break;
		printf("\a違います、再入力してください :");
	}

	end = time(NULL);

	printf("%.01f秒かかりました。\n", difftime(end, start));

	return 0;
}