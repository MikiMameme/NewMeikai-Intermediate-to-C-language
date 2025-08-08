/*入力された文字列sの妥当性をチェック(関数のみ)*/
int check(const char s[])
{
	int i, j;

	if(strlen(s)) != 4)
	return 1;
	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;
		for (j = 0; j < 1; j++)
			if (s[i] == s[j])
				return 3;
	}
	return 0;
}
