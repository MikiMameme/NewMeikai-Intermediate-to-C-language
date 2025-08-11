/*time_t型による時刻をctime関数に準じて変換（関数部分のみ、改行文字は付加しない）*/
char* ctime2(const time_t* timer)
{
	return asctime2(localtime(timer))
}