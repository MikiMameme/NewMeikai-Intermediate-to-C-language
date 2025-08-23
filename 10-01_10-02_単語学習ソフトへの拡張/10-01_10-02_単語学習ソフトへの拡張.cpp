/*英単語学習ソフト(試作版：日本語の単語・英単語をランダムに表示)*/

#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

/*単語の数*/
#define QNO 12
/*選択肢の数*/
#define CNO 4

/*日本語*/
const char* jptr[] = {
	"動物", "車", "花", "家", "机", "本",
	"椅子", "父", "母", "愛", "平和", "雑誌",
};

/*英語*/
const char* eptr[] = {
	"animal", "car", "flower", "house", "desk", "book",
	"chair", "father", "mother", "love", "peace", "magazine",
};

/*選択肢を表示*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d) %s ", i, sw ? jptr[c[i]] : eptr[c[i]]);
	printf(" : ");
}

/*選択肢を生成して正解の添字を返す*/
int make_cand(int c[], int n)
{
	int i;
	/*先頭要素に正解を入れて*/
	c[0] = n;
	/*それ以降の要素は*/
	for (i = 1; i < CNO; i++)
		/*0以上QNO未満の値*/
		c[i] = rand() % QNO;

	return 0;
}

int main(void)
{
	int nq, pq;
	int na;
	int sw;
	int retry;
	int cand[CNO];

	/*乱数の種を設定*/
	srand(time(NULL));

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
			print_cand(cand, sw);
			scanf("%d", &no);
			if (no != na)
				puts("\a違います");
		} while (no != na);
		puts("正解です");

		pq = nq;

		printf("もう一度しますか 0-いいえ / 1-はい :");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}