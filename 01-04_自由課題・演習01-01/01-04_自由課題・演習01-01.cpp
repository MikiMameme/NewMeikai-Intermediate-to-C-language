/* おみくじプログラム（配列を使用） */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int fortune;
	char choice;

	/* おみくじの結果を配列で管理 */
	const char *omikuji[] = {
		"大吉", "中吉", "小吉", "吉", "末吉", "凶", "大凶"
	};

	/* それぞれのメッセージも配列で管理 */
	const char *message[] = {
		"とても良い一日になりそうです！",
		"良いことがありそうです。",
		"小さな幸せが見つかりそう。",
		"穏やかな一日になりそうです。",
		"後半にいいことがありそう。",
		"気を付けて過ごしましょう。",
		"今日は慎重に行動しましょう。"
	};

	printf("=== おみくじプログラム ===\n\n");
	printf("おみくじを引きますか？");
	printf("( はい:y  いいえ:n ) \n");
	printf("選択してください:");

	scanf("%c", &choice);

	if (choice == 'y' || choice == 'Y') {
		srand((unsigned int)time(NULL));

		/*０～６の乱数を生成*/
		fortune = rand() % 7;

		printf("\n=== 今日のおみくじ ===\n\n");

		/* 配列のインデックスでアクセス */
		printf("%s\n", omikuji[fortune]);
		printf("%s\n", message[fortune]);

		printf("\n 良い一日をお過ごしください♪\n");
	}

	else if (choice == 'n' || choice == 'N') {
		printf("\nまたのご利用をお待ちしております。\n");

	}

	else {
		printf("\n無効な選択です、プログラムを終了します。");
	}


	return 0;
}