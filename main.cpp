/* �����ăQ�[���i���̂S�F���͉񐔂ɐ�����݂���j */

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

    printf("�O�`�X�X�X�̐����𓖂ĂĂ��������B\n\n");

    do {
        printf("�c��%d��B�������� :", remain);
        scanf("%d", &no);
        remain--;

        if (no > ans)
            printf("\a�����Ə�������B\n");
        else if (no < ans)
            printf("\a�����Ƒ傫����B\n");
    } while (no != ans && remain > 0);

    if (no != ans)
        printf("\a�c�O�B������%d�ł����B\n", ans);
    else {
        printf("�����ł��B\n");
        printf("%d��œ�����܂����ˁB\n", max_stage - remain);
    }

    return 0;
}