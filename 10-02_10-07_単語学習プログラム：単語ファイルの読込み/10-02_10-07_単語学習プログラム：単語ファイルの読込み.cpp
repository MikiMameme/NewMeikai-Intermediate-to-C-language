/*単語学習プログラム（その４：単語をファイルから読み込む）*/

#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*選択肢の数*/
#define CNO 4

#define swap(type, x, y) do{type t = (x); (x) = (y); (y) = t;} while(0)

/*単語の数*/
int QNO;

/*日本語単語へのポインタの配列*/
char **jptr;

/*英語単語へのポインタの配列*/
char **eptr;

/*選択肢を表示*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d)%s ", i, sw ? jptr[c[i]] : eptr[c[i]]);
	printf(" : ");
}

/*選択肢を生成して正解の添字を返す*/
int make_cand(int c[], int n)
{
	int i, j, x;

	/*先頭要素に正解を入れる*/
	c[0] = n;

	for (i = 1; i < CNO; i++) {
		do {
			x = rand() % QNO;
			for (j = 0; j < i; j++)
				if (c[j] == x)
					break;
		} while (i != j);
		c[i] = x;
	}
	j = rand() % CNO;
	if (j != 0)
		/*正解を移動*/
		swap(int, c[0], c[j]);

	return j;
}

/*単語を読み込む*/
int read_tango(void)
{
	int i;
	FILE *fp;

	if ((fp = fopen("TANGO.txt", "r")) == NULL) return 1;
	
	/*単語数を読み込む*/
	fscanf(fp, "%d", &QNO);

	if ((jptr = (char**)calloc(QNO, sizeof(char *))) == NULL) return 1;
	if ((eptr = (char**)calloc(QNO, sizeof(char *))) == NULL) return 1;

	for (i = 0; i < QNO; i++) {
		char etemp[1024];
		char jtemp[1024];

		fscanf(fp, "%s%s", etemp, jtemp);
		if ((eptr[i] = (char*)malloc(strlen(etemp) + 1)) == NULL)return 1;
		if ((jptr[i] = (char*)malloc(strlen(jtemp) + 1)) == NULL)return 1;
		strcpy(eptr[i], etemp);
		strcpy(jptr[i], jtemp);
	}
	fclose(fp);

	return 0;
}

int main(void)
{
	int i;
	/*問題番号・前回の問題番号*/
	int nq, pq;
	/*正解の番号*/
	int na;
	/*正解の言語*/
	int sw;
	/*再挑戦？*/
	int retry;
	/*選択肢の番号*/
	int cand[CNO];

	if (read_tango() == 1) {
		printf("\a単語ファイルの読込みに失敗しました\n");
		return 1;
	}
	/*乱数の種を設定*/
	srand(time(NULL));

	/*前回の問題番号（存在しない番号）*/
	pq = QNO;

	do {
		int no;
		do {
			nq = rand() % QNO;
		} while (nq == pq);
		na = make_cand(cand, nq);
		sw = rand() % 2;

		printf("%sはどれですか\n", sw ? eptr[nq] : jptr[nq]);
		do {

			/*選択肢を表示*/
			print_cand(cand, sw);
			scanf("%d", &no);
			if (no != na)
				puts("違います");
		} while (no != na);
		puts("正解です");
		
		pq = nq;

		printf("もう一度しますか 0-いいえ / 1-はい :");
		scanf("%d", &retry);
	} while (retry == 1);
	for (i = 0; i < QNO; i++) {
		free(eptr[i]);
		free(jptr[i]);
	}
	free(jptr);
	free(eptr);

	return 0;
}