/*現在の日付・時刻を表示（その３：ctime関数を利用）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>

int main(void)
{
	time_t current = time(NULL);

	printf("現在の日付・時刻 :%s", ctime(&current));

	return 0;
}