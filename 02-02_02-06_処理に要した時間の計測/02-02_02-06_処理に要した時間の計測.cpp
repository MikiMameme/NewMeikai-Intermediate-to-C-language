/*暗算トレーニング（3桁の整数を3つ加える）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int a, b, c;
	int x;
	clock_t start, end;
	double req_time;

	srand(time(NULL));

	a = 100 + rand() % 900;
	b = 100 + rand() % 900;
	c = 100 + rand() % 900;

	printf("%d + %d + %dはなんですか :", a, b, c);

	start = clock();

	while (1) {
		scanf("%d", &x);
		if (x == a + b + c)
			break;
		printf("\a違います、\n再入力してください :");
	}

	end = clock();

	req_time = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%1f秒かかりました。\n", req_time);

	if (req_time > 30.0)
		printf("時間がかかりすぎです。\n");

	else if (req_time > 17.0)
		printf("まあまあですね。\n");

	else
		printf("素早いですね。\n");

	return 0;

}