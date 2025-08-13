/*プログラム名・プログラム仮引数をargcを使わずに表示*/

#include<stdio.h>

int main(int argc, char** argv)
{
	int i = 0;

	while (*argv)
		printf("argv[%d] = \"%s\"\n", i++, *argv++);

	return 0;
}