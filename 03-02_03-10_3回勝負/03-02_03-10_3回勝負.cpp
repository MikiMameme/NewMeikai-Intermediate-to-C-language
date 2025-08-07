/*じゃんけんゲーム（その５：3回先勝したほうが勝ち）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int human;
int comp;
int win_no;
int lose_no;
int draw_no;

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期処理*/
void initialize(void)
{
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand(time(NULL));

	printf("じゃんけんゲーム開始\n");
}

/*じゃんけん実行（手の読み込み生成）*/
void jyanken(void)
{
	int i;

	comp = rand() % 3;
	do {
		printf("\n\aじゃん☆けん☆ぽん...");
		for (i = 0; i < 3; i++)
			printf(" (%d)%s", i, hd[i]);
		printf(":");
		scanf("%d", &human);
	} while (human < 0 || human > 2);
}

/*勝ち負け引き分け回数を更新*/
void count_no(int result)
{
	switch (result) {
	case 0: draw_no++; break;
	case 1: lose_no++; break;
	case 2: win_no++;  break;
	}
}

/*判定結果を表示*/
void disp_result(int result)
{
	switch (result) {
	case 0: puts("引き分けです。");       break;
	case 1: puts("あなたの負けです。");   break;
	case 2: puts("あなたの勝ちです。");   break;
	}
}

int main(void)
{
	int judge;

	initialize();

	do {
		jyanken();

		/*コンピューターと人間の手を表示*/
		printf("私は % sで、あたなは % sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;
		count_no(judge);
		disp_result(judge);

	} while (win_no < 3 && lose_no < 3);

	printf(win_no == 3 ? "\n□あなたの勝ちです。\n" : "\n■私の勝ちです。\n");

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);

	return 0;
}