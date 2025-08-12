/*曜日の公式（その２：ツェラーの公式を利用）*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

/*year年month月day日の曜日を求める*/
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return(year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
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

		printf("それは%s曜日です。\n", ws[w]);

		return 0;
}