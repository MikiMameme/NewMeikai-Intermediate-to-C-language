/*演習6-7：日付当てゲーム（ゲームの流れは1章「数当てゲーム」と同様）*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int is_leap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int monthdays(int year, int month) {
    if (month-- != 2) return mday[month];
    return mday[month] + is_leap(year);
}

int main(void) {
    int year = 2025;
    int ans_m, ans_d; // 正解の月・日
    int guess_m, guess_d; // 入力の月・日

    srand(time(NULL));
    ans_m = rand() % 12 + 1;
    ans_d = rand() % monthdays(year, ans_m) + 1;

    printf("%d年の日付を当ててください！（月と日）\n\n", year);

    do {
        printf("月 : ");
        scanf("%d", &guess_m);
        printf("日 : ");
        scanf("%d", &guess_d);

        if (guess_m > ans_m) {
            printf("\aもっと早い月です。\n");
        }
        else if (guess_m < ans_m) {
            printf("\aもっと遅い月です。\n");
        }
        else {
            if (guess_d > ans_d)
                printf("\aもっと前の日です。\n");
            else if (guess_d < ans_d)
                printf("\aもっと後の日です。\n");
        }

    } while (guess_m != ans_m || guess_d != ans_d);

    printf("正解です！ %d年%d月%d日 です！\n", year, ans_m, ans_d);

    return 0;
}