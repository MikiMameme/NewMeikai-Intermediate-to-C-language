/*演習9-7：ファイルのコピー（改良版）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

/*この大きさに分割してコピー*/
#define BSIZE 1024
#define FILENAME_MAX_LEN 256

/* ファイルの存在チェック */
int file_exists(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp) {
        fclose(fp);
        return 1;  /* 存在する */
    }
    return 0;  /* 存在しない */
}

/* 上書き確認 */
int confirm_overwrite(const char* filename) {
    char answer;
    printf("ファイル（%s）はすでに存在します、上書きしますか？Y/N: ", filename);
    scanf(" %c", &answer);
    return (answer == 'Y' || answer == 'y');
}

/* ファイル名を入力してもらう */
void get_filename(char* filename, const char* prompt) {
    printf("%s", prompt);
    scanf("%255s", filename);
}

int main(int argc, char* argv[]) {
    int n;
    FILE* src, * dst;
    unsigned char buf[BSIZE];
    char src_filename[FILENAME_MAX_LEN];
    char dst_filename[FILENAME_MAX_LEN];

    if (argc != 3) {
        /* ユーザー入力モード */
        printf("=== ファイルコピープログラム ===\n");

        /* コピー元ファイル名の入力 */
        get_filename(src_filename, "コピー元ファイル名を入力してください: ");

        /* コピー先ファイル名の入力 */
        get_filename(dst_filename, "コピー先ファイル名を入力してください: ");

        /* コピー先ファイルの存在チェック */
        if (file_exists(dst_filename)) {
            if (!confirm_overwrite(dst_filename)) {
                printf("コピーを中止しました。\n");
                return 0;
            }
        }
    }
    else {
        /* コマンドライン引数モード */
        strcpy(src_filename, argv[1]);
        strcpy(dst_filename, argv[2]);

        /* コピー先ファイルの存在チェック */
        if (file_exists(dst_filename)) {
            if (!confirm_overwrite(dst_filename)) {
                printf("コピーを中止しました。\n");
                return 0;
            }
        }
    }

    /* ファイルオープンとコピー処理 */
    if ((src = fopen(src_filename, "rb")) == NULL) {
        fprintf(stderr, "エラー: ファイル%sがオープンできませんでした\n", src_filename);
        return 1;
    }
    else if ((dst = fopen(dst_filename, "wb")) == NULL) {
        fprintf(stderr, "エラー: ファイル%sがオープンできませんでした\n", dst_filename);
        fclose(src);
        return 1;
    }
    else {
        printf("コピー中... %s → %s\n", src_filename, dst_filename);

        /* ファイルコピー */
        while ((n = fread(buf, 1, BSIZE, src)) > 0) {
            fwrite(buf, 1, n, dst);
        }

        fclose(src);
        fclose(dst);

        printf("コピーが完了しました！\n");
    }

    return 0;
}