/*英単語学習ソフト(試作版：日本語の単語・英単語をランダムに表示)*/

#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

/*単語の数*/
#define QNO 12

/*日本語*/
const char *jptr[] = {
	"動物", "車", "花", "家", "机", "本",
	"椅子", "父", "母", "愛", "平和", "雑誌",
};

/*英語*/
const char* eptr[] = {
	"animal", "car", "flower", "house", "desk", "book",
	"chair", "father", "mother", "love", "peace", "magazine",
};

int main(void)
{
	int nq, pq;
	int sw;
	int retry;

	/*乱数の種を設定*/
	srand(time(NULL));

	pq = QNO;

	do {
		do {
			nq = rand() % QNO;
		} while (nq == pq);

		/*日本語or英語*/
		sw = rand() % 2;

		printf("%s\n", sw ? eptr[nq] : jptr[nq]);

		pq = nq;

		printf("もう一度しますか？ 0-いいえ / 1-はい");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}