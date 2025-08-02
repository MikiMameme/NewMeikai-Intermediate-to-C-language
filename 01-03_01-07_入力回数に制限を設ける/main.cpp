/* 数あてゲーム（その４：入力回数に制限を設ける） */

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int no;
    int ans;
    const int max_stage = 10;
    int remain = max_stage;

    srand(time(NULL));
    ans = rand() % 1000;

    printf("０～９９９の整数を当ててください。\n\n");

    do {
        printf("残り%d回。いくつかな :", remain);
        scanf("%d", &no);
        remain--;

        if (no > ans)
            printf("\aもっと小さいよ。\n");
        else if (no < ans)
            printf("\aもっと大きいよ。\n");
    } while (no != ans && remain > 0);

    if (no != ans)
        printf("\a残念。正解は%dでした。\n", ans);
    else {
        printf("正解です。\n");
        printf("%d回で当たりましたね。\n", max_stage - remain);
    }

    return 0;
}