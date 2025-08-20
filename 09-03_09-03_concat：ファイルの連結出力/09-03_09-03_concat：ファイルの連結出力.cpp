/*concat...ファイルのコピー*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

/*srcからの入力をdstへ出力*/
void copy(FILE* src, FILE* dst)
{
	int ch;

	while ((ch = fgetc(src)) != EOF)
		fputc(ch, dst);
}

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
		copy(stdin, stdout);
	else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "ファイル%sが正しくオープンできませんでした。\n",
					*argv);
				return 1;
			}
			else {
				/*ストリームfp→標準出力*/
				copy(fp, stdout);
				fclose(fp);
			}
		}
	}
	return 0;
}