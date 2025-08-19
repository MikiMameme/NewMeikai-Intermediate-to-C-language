/*総合タイピング練習*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "getputch.h"

/*トレーニング回数*/
#define NO 15

/*ブロック数*/
#define KTYPE 16

/*ポジショントレーニングの文字数*/
#define POS_LEN 10

/*練習メニュー*/
typedef enum {Term, KeyPos, KeyPosComp, Clang, Conversation, InValid} Menu;

/*各ブロックのキー*/
const char *kstr[] = { 
	"12345", "67890-^\\", /*第1段*/
	"!\"#$%", "&'() =~|", /*第1段(SHIFT)*/
	"qwert", "yuiop@[", /*第2段*/
	"QWERT", "YUIOP`{", /*第2段(SHIFT)*/
	"asdfg", "hjkl;:]", /*第3段*/
	"ASDFG", "HJKL+*}", /*第3段(SHIFT)*/
	"zxcvb", "nm,./\\", /*第4段*/
	"ZXCVB", "NM<> _", /*第4段(SHIFT)*/
};

/*Ｃ言語のキーワードとライブラリ関数*/
const char* cstr[] = {
	"auto", "break", "case", "char", "const", "continue",
	"default", "do", "double", "else", "enum", "extern",
	"float", "for", "goto", "if", "int", "long",
	"register", "return", "short", "signed", "sizeof", "static",
	"struct", "switch", "typedef", "union", "unsigned", "void",
	"volatile", "while",
	"abort", "abs", "acos", "asctime", "asin", "assert",
	"atan", "atan2", "atexit", "atof", "atoi", "atol",
	"bsearch", "calloc", "ceil", "clearerr", "clock", "cos",
	"cosh", "ctime", "difftime", "div", "exit", "exp",
	"fabs", "fclose", "feof", "ferror", "fflush", "fgetc",
	"fgetpos", "fgets", "floor", "fmod", "fopen", "fprintf",
	"fputc", "fputs", "fread", "free", "freopen", "frexp",
	"fscanf", "fseek", "fsetpos", "ftell", "fwrite", "getc",
	"getchar", "getenv", "gets", "gmtime", "isalnum", "isalpha",
	"iscntrl", "isdigit", "isgraph", "islower", "isprint", "ispunct",
	"isspace", "isupper", "isxdigit", "labs", "ldexp", "ldiv",
	"localeconv", "localtime", "log", "log10", "longjmp",
	"malloc", "memchr", "memcmp", "memcpy", "memmove", "memset",
	"mktime", "modf", "perror", "pow", "printf", "putc",
	"putchar", "puts", "qsort", "raise", "rand", "realloc",
	"remove", "rename", "rewind", "scanf", "setbuf", "setjmp",
	"setlocale", "setvbuf", "signal", "sin", "sinh", "sprintf",
	"sqrt", "srand", "sscanf", "strcat", "strchr", "strcmp",
	"strcoll", "strcpy", "strcspn", "strerror", "strftime", "strlen",
	"strncat", "strncmp", "strncpy", "strpbrk", "strrchr", "strspn",
	"strstr", "strtod", "strtok", "strtol", "strtoul", "strxfrm",
	"system", "tan", "tanh", "time", "tmpfile", "tmpnam",
	"tolower", "toupper", "ungetc", "va_arg", "va_end", "va_start",
	"vfprintf", "vprintf", "vsprintf"
};

/*英会話*/
const char* vstr[] = {

	"Hello", /*こんにちは*/
	"How are you", /*お元気ですか*/
	"Fine thanks", /*はい元気です*/
	"I can't complain thanks", /*まあ、なんとか*/
	"How do you do",/*はじまめして*/
	"Good bye", /*さようなら*/
	"Good morning", /*おはよう*/
	"Good afternoon", /*こんにちは*/
	"Good evening", /*こんばんは*/
	"See you later", /*さようなら（またね）*/
	"Go ahead plese", /*お先にどうぞ*/
	"Thank you", /*ありがとう*/
	"No thank you", /*いいえ結構です*/
	"May I have your name", /*お名前は*/
	"I'm glad to meet you", /*お目にかかれて光栄です*/
	"What time is it now", /*何時ですか*/
	"It's about seven", /*7時くらいです*/
	"I must go now", /*もう行かないと*/
	"How much", /*いくらですか*/
	"Where is the restroom", /*お手洗いはどこですか*/
	"Excuse me", /*失礼します（一人）*/
	"Excuse us", /*失礼します（二人以上）*/
	"I'm sorry", /*ごめんなさい*/
	"I don't know", /*さあ、知らないよ*/
	"I have no change with me", /*小銭がないのよ*/
	"I will be back", /*また来ます*/
	"Are you going out", /*出かけるの*/
	"I hope I'm not disturbing you", /*お邪魔じゃなければ良いのですが*/
	"I'll offer no excuse", /*弁解するつもりはありません*/
	"Shall we dance", /*踊りませんか*/
	"Will you do me a favor", /*ちょっとお願いしたいのですが*/
	"It's very unseasonable", /*それは季節外れだ*/
	"You are always welcome", /*いつでも歓迎します*/
	"Hold still", /*じっとしてて*/
	"Follow me", /*ついてきて*/
	"Just follow me lead", /*僕のする通りにやるだけだ*/
	"To be honest with you", /*正直に言うと*/
};

/*文字列strをタイプ練習（ミス回数を返す）*/
int go(const char* str)
{
	int i;
	int len = strlen(str);
	int mistake = 0;

	for (i = 0; i < len; i++) {
		printf("%s \r", &str[i]);
		fflush(stdout);
		while (getch() != str[i]) {
			mistake++;
		}
	}
	return mistake;
}

/*単純ポジショニングトレーニング*/
void pos_training(void)
{
	int i;
	int stage;
	int temp, line;
	int len;
	int qno, pno;
	int tno, mno;
	clock_t start, end;

	printf("\n単純ポジショニングトレーニングを行います。\n");
	printf("練習するブロックを選択してください。\n");
	printf("第1段（１）左 %-8s （２）右 %-8s\n", kstr[0], kstr[1]);
	printf("第2段（３）左 %-8s （４）右 %-8s\n", kstr[4], kstr[5]);
	printf("第3段（５）左 %-8s （６）右 %-8s\n", kstr[8], kstr[9]);
	printf("第4段（７）左 %-8s （８）右 %-8s\n", kstr[12], kstr[13]);

	/*ブロックを選択させる*/
	do {
		printf("番号（練習中止は99） :");
		scanf("%d", &temp);
		if (temp == 99) return;
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("%sの問題を%d回練習します。\n", kstr[line], NO);

	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;
	len = strlen(kstr[line]);

	/*開始時刻*/
	start = clock();

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++)
			str[i] = kstr[line][rand() % len];
		str[i] = '\0';

		/*練習実行*/
		mno += go(str);
		tno += strlen(str);
	}
	/*終了時刻*/
	end = clock();

	printf("問題:%d文字/ミス:%d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*複合ポジショントレーニング*/
void pos_training2(void)
{
	int i;
	int stage;
	int temp, line;
	int sno;
	int select[KTYPE];
	int len[KTYPE];
	int tno, mno;
	clock_t start, end;
	const char* format = "第%d段(%2d) 左 %-8s (%2d) 右 %-8s "
						"(%2d)[左] %-8s (%2d)[右] %-8s\n";

	printf("\n複合ポジショントレーニングを行います。\n");
	printf("練習するブロックを選択してください（複数選べます）\n");

	for (i = 0; i < 4; i++) {
		int k = i * 4;
		printf(format, i + 1, k + 1, kstr[k], k + 2, kstr[k + 1],
			k + 3, kstr[k + 2], k + 4, kstr[k + 3]);
	}

	/*ブロックを重複させずに選択させる*/
	sno = 0;
	while (1) {
		printf("番号（選択終了は50 / 練習中止は99）:");

		do {
			scanf("%d", &temp);

			if (temp == 99) return;
		} while ((temp < 1 || temp > KTYPE) && temp != 50);

		if (temp == 50)
			break;
		for (i = 0; i < sno; i++)
			if (temp == select[i]) {
				printf("\aその段はすでに選ばれています。\n");
				break;
			}
		if (i == sno)
			select[sno++] = temp;
	}

	if(sno == 0)
	return;

	printf("以下のブロックの問題を%d回練習します。\n", NO);

	for (i = 0; i < sno; i++)
		printf("%s", kstr[select[i] - 1]);

	printf("\nスペースキーで開始します。\n");
	while (getch() != ' ')
		;
	
	/*文字数・ミス回数をクリア*/
	tno = mno = 0;
	for (i = 0; i < sno; i++)
		/*ブロックのキー数*/
		len[i] = strlen(kstr[select[i] - 1]);

	/*開始時刻*/
	start = clock();

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		/*問題文字列を作成*/
		for (i = 0; i < POS_LEN; i++) {
			int q = rand() % sno;
			str[i] = kstr[select[q] - 1][rand() % len[q]];
		}
		str[i] = '\0';

		/*練習実行*/
		mno += go(str);
		tno += strlen(str);
		printf("\n");
	}

	end = clock();

	printf("問題: %d文字 / ミス: %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*C言語/英会話トレーニング*/
void word_training(const char* mes, const char* str[], int n)
{
	int stage;
	int qno, pno;
	int tno, mno;
	clock_t start, end;

	printf("\n%sを%d個練習します。\n", mes, NO);
	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;
	pno = n;

	/*開始時刻*/
	start = clock();

	/*同じ問題を連続して出題しない*/
	for (stage = 0; stage < NO; stage++) {
		do {
			qno = rand() % n;
		} while (qno == pno);

		/*問題はstr[qno]*/
		mno += go(str[qno]);
		tno += strlen(str[qno]);
		pno = qno;
		printf("\n");
	}

	/*終了時刻*/
	end = clock();

	printf("問題: %d文字 / ミス: %d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*メニュー選択*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n練習を選択してください。\n");
		printf("（１）単純ポジション （２）複合ポジション\n");
		printf("（３）C言語の単語    （４）英会話    （０）終了 :");
		scanf("%d", &ch);
	} while (ch < Term || ch >= InValid);

	return(Menu)ch;
}

int main(void)
{
	/*メニュー*/
	Menu menu;
	/*C言語の単語数*/
	int cn = sizeof(cstr) / sizeof(cstr[0]);
	/*英単語の文書数*/
	int vn = sizeof(vstr) / sizeof(vstr[0]);

	init_getputch();

	srand(time(NULL));

	do {
		switch (menu = SelectMenu()) {

		/*単純ポジショントレーニング*/
		case KeyPos :
			pos_training();
			break;

		/*複合ポジショントレーニング*/
		case KeyPosComp :
			pos_training2();
			break;

		/*Ｃ言語の単語*/
		case Clang :
			word_training("Ｃ言語の単語", cstr, cn);
			break;

		/*英会話*/
		case Conversation :
			word_training("英会話の文書", vstr, vn);
			break;
		}
	} while (menu != Term);

	term_getputch();

	return 0;
}