/*entab...水平タブ文字を展開する*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

/*srcからの入力の空白文字をタブ化してdstへ出力*/
void entab(FILE* src, FILE* dst, int width)
{

/*デバッグ用
void entab(FILE* src, FILE* dst, int width)  // ← 名前も修正
{
	printf("entab関数が呼び出されました！\n");  // デバッグ用
	*/
	
	int ch;
	int count = 0;
	int ntab = 0;
	int pos = 0;

	for (; (ch = fgetc(src)) != EOF; pos++)
		if (ch == ' ') {
			if (pos % width != 0)
				count++;
			else{
				count = 0;
			ntab++;
			}
		}
		else {
			for (; ntab > 0; --ntab)
				fputc('\t', dst);
			if (ch == '\t')
				count = 0;
			else
				for (; count > 0; count--)
					fputc(' ', dst);
			fputc(ch, dst);
			if (ch == '\n')
				pos = 0;
			else if (ch == '\t')
				pos += width - (pos - 1) % width - 1;
		}
}

int main(int argc, char* argv[])
{
	int width = 8;
	FILE* fp;

	if (argc < 2)
		/*標準入力→標準出力*/
		entab(stdin, stdout, width);
	else {
		while (--argc > 0) {
			if (**(++argv) == '-') {
				if (*++(*argv) == 't')
					width = atoi(++*argv);
				else {
					fputs("パラメータが不正です\n", stderr);
					return 1;
				}
			}
			else if ((fp = fopen(*argv, "r")) == NULL) {
				fprintf(stderr, "ファイル%sが正しくオープンできませんでした\n",
					*argv);
				return 1;
			}
			else {
				/*ストリームfp→標準出力*/
				entab(fp, stdout, width);
				fclose(fp);
			}
		}
	}
	return 0;
}