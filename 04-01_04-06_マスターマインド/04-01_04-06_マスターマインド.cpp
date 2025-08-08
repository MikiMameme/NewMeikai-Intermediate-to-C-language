/*マスターマインド*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

/*相異なる4つの数字の並びを生成して配列xに格納*/
void make4digits(int x[])
{
	int i, j, val;

	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 10;
			for (j = 0; j < i; j++)
				if (val == x[j])
					break;
		} while (j < i);
		x[i] = val;
	}
}

/*入力された文字列sの妥当性をチェック*/
int check(const char s[])
{
	int i, j;

	if(strlen(s) != 4)
	return 1;

	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;
		for (j = 0; j < i; j++)
			if (s[i] == s[j])
				return 3;
	}
	return 0;
}

/*ビットとフローの判定(関数のみ)*/
void judge(const char s[], int no[], int* hit, int* blow)
{
	int i, j;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j])
				if (i == j)
					(*hit)++;
				else
					(*blow)++;
		}
	}
}

/*判定結果を表示*/
void print_result(int snum, int spos)
{
	if (spos == 4)
		printf("正解です");
	else if (snum == 0)
		printf("     それらの数字は全く含まれません。\n");
	else {
		printf("    それらの数字中%d個の数字が含まれています。\n", snum);

		if (spos == 0)
			printf(" ただし位置もあっている数字はありません。\n");
		else
			printf(" その中に%d個は位置もあっています。\n", spos);
	}
	putchar('\n');
}

int main(void)
{
	int try_no = 0;
	int chk;
	int hit;
	int blow;
	int no[4];
	char buff[10];
	clock_t start, end;

	srand(time(NULL));

	puts("■　マスターマインドをしましょう。");
	puts("■　4つの数字の並びを当ててください。");
	puts("■　同じ数字が複数含まれることはありません。");
	puts("■　4307のように連続して入力してください。");
	puts("■　スペース文字などを入力してはいけません。");

	make4digits(no);

	start = clock();

	do {
		do {
			printf("入力してください:");
			scanf("%s", buff);

			chk = check(buff);

			switch (chk) {
			case 1: puts("\aきちんと４文字で入力してください。"); break;
			case 2: puts("\a数字以外の文字を入力しないでください。"); break;
			case 3: puts("\a同一の数字を複数入力しないでください。"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, no, &hit, &blow);
		print_result(hit + blow, hit);

	} while (hit < 4);

	end = clock();

	printf("%d回かかりました。\n所要時間は%.1f秒でした。\n",
		try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}