/*記憶力トレーニング（4桁の数値を逆順で入力）*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_STAGE 10

/*数値を逆順にする関数*/
int reverse_number(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

/*xミリ秒経過するのを待つ*/
int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;
    do {
        if ((c2 = clock()) == (clock_t)-1)
            return 0;
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void)
{
    int stage;
    int success = 0;
    clock_t start, end;
    srand(time(NULL));
    printf("4桁の数値を記憶し、逆順で入力しましょう\n");
    printf("例：5892が表示されたら2985と入力\n\n");
    start = clock();
    for (stage = 0; stage < MAX_STAGE; stage++) {
        int x;
        int no = rand() % 9000 + 1000;              /*1000～9999の4桁数値*/
        int reversed_no = reverse_number(no);       /*正解（逆順）*/

        printf("第%d問：%d", stage + 1, no);
        fflush(stdout);
        sleep(2000);                                /*2秒表示*/
        printf("\r逆順で入力せよ：");
        fflush(stdout);
        scanf("%d", &x);

        if (x != reversed_no) {
            printf("\a間違いです。正解は%dでした。\n", reversed_no);
        }
        else {
            printf("正解です！\n");
            success++;
        }
    }
    end = clock();
    printf("\n%d回中%d回成功しました。\n", MAX_STAGE, success);
    printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}