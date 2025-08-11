/*曜日を求める（その１：mktime関数を利用）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>

/*year年month月day日の曜日を求める*/
int dayofweek(int year, int month, int day)
{
	struct tm t;

	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	t.tm_hour = 0;
	t.tm_min =  0;
	t.tm_sec =  0;
	t.tm_isdst = -1;

	if (mktime(&t) == (time_t)-1)
		return -1;
	return t.tm_wday;
}

int main(void)
{
	int y, m, d, w;
	const char* ws[] = { "日", "月", "火", "水", "木", "金", "土" };

	printf("曜日を求めます。\n");
	printf("年 :");	scanf("%d", &y);
	printf("月 :");	scanf("%d", &m);
	printf("日 :");	scanf("%d", &d);

	w = dayofweek(y, m, d);

	if (w != -1)
		printf("それは%s曜日です。\n", ws[w]);
	else
		printf("求められませんでした。\n");

	return 0;
}