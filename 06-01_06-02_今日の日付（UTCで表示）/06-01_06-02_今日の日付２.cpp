/*現在の日付・時刻を協定世界時で表示*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>

/*日付・時刻を表示*/
void put_date(const struct tm* timer)
{
	const char* wday_name[] = { "日", "月", "火", "水", "木", "金", "土" };

	printf("%4d年%02d月%02d日（%s）%02d時%02d分%02d秒",
		timer->tm_year + 1900,
		timer->tm_mon + 1,
		timer->tm_mday,
		wday_name[timer->tm_wday],
		timer->tm_hour,
		timer->tm_min,
		timer->tm_sec
	);
}

int main(void)
{
	time_t current;
	struct tm* timer;

	time(&current);
	timer = gmtime(&current);

	printf("今日の日付・時刻はUTC(協定世界時)で");
	put_date(timer);
	printf("です。\n");

	return 0;
}