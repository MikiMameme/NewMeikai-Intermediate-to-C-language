/*bcopy...ファイルのコピー*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

/*この大きさに分割してコピー*/
#define BSIZE 1024

int main(int argc, char *argv[])
{
	int n;
	FILE  *src, *dst;
	unsigned char buf[BSIZE];

	if (argc != 3) {
		fprintf(stderr, "コマンドライン引数がないか、パラメータが不正です\n");
		fprintf(stderr, "bcopy コピー元ファイル名 コピー先ファイル名\n", *argv);
	}
	else {
		if ((src = fopen(*++argv, "rb")) == NULL) {
			fprintf(stderr, "ファイル%sがオープンできませんでした\n", *argv);
				return 1;
		}
		else if ((dst = fopen(*++argv, "wb")) == NULL) {
			fprintf(stderr, "ファイル%sがオープンできませんでした\n", *argv);
			fclose(src);
			return 1;
		}
		else {
			while ((n = fread(buf, BSIZE, 1, src)) > 0)
				fwrite(buf, n, 1, dst);
			fclose(src);
			fclose(dst);
		}
	}
	return 0;
}