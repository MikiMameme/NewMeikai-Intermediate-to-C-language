/*月名学習プログラム（改良版：大小文字対応・正解表示機能付き）*/

#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*単語の数*/
int QNO;
/*日本語単語へのポインタの配列*/
char** jptr;
/*英語単語へのポインタの配列*/
char** eptr;

/*文字列を小文字に変換*/
void to_lowercase(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

/*大文字小文字を無視して文字列を比較*/
int strcasecmp_custom(const char* s1, const char* s2) {
    char temp1[256], temp2[256];
    strcpy(temp1, s1);
    strcpy(temp2, s2);
    to_lowercase(temp1);
    to_lowercase(temp2);
    return strcmp(temp1, temp2);
}

/*単語を読み込む*/
int read_tango(void) {
    int i;
    FILE* fp;
    if ((fp = fopen("TANGO.txt", "r")) == NULL) return 1;

    /*単語数を読み込む*/
    fscanf(fp, "%d", &QNO);
    if ((jptr = (char**)calloc(QNO, sizeof(char*))) == NULL) return 1;
    if ((eptr = (char**)calloc(QNO, sizeof(char*))) == NULL) return 1;

    for (i = 0; i < QNO; i++) {
        char etemp[1024];
        char jtemp[1024];
        fscanf(fp, "%s%s", etemp, jtemp);
        if ((eptr[i] = (char*)malloc(strlen(etemp) + 1)) == NULL) return 1;
        if ((jptr[i] = (char*)malloc(strlen(jtemp) + 1)) == NULL) return 1;
        strcpy(eptr[i], etemp);
        strcpy(jptr[i], jtemp);
    }
    fclose(fp);
    return 0;
}

int main(void) {
    int i;
    int nq, pq;
    int sw;
    int retry;
    char user_answer[256];
    int show_answer;

    if (read_tango() == 1) {
        printf("\a単語ファイルの読込みに失敗しました\n");
        return 1;
    }

    srand(time(NULL));
    pq = QNO;

    printf("=== 月名学習プログラム ===\n");
    printf("英語は大文字でも小文字でも構いません\n\n");

    do {
        /* 前回と異なる問題を選択 */
        do {
            nq = rand() % QNO;
        } while (nq == pq);

        /* 日本語→英語 or 英語→日本語 */
        sw = rand() % 2;

        printf("問題: %s\n", sw ? eptr[nq] : jptr[nq]);
        printf("答え: ");
        scanf("%s", user_answer);

        /* 正解判定 */
        int correct = 0;
        if (sw) {
            /* 英語問題の場合：日本語での回答 */
            if (strcmp(user_answer, jptr[nq]) == 0) {
                correct = 1;
            }
        }
        else {
            /* 日本語問題の場合：英語での回答（大文字小文字無視） */
            if (strcasecmp_custom(user_answer, eptr[nq]) == 0) {
                correct = 1;
            }
        }

        if (correct) {
            printf("正解です\n");
        }
        else {
            printf("違います。");
            printf("正解を見ますか？ 0-いいえ / 1-はい: ");
            scanf("%d", &show_answer);

            if (show_answer == 1) {
                printf("正解: %s は %s です\n",
                    sw ? eptr[nq] : jptr[nq],
                    sw ? jptr[nq] : eptr[nq]);
            }
        }

        pq = nq;
        printf("\nもう一度しますか？ 0-いいえ / 1-はい: ");
        scanf("%d", &retry);
        printf("\n");

    } while (retry == 1);

    printf("お疲れ様でした\n");

    /* メモリ解放 */
    for (i = 0; i < QNO; i++) {
        free(eptr[i]);
        free(jptr[i]);
    }
    free(jptr);
    free(eptr);
    return 0;
}