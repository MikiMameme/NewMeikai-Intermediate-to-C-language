/*配列をコピーして表示（要素を一つ飛ばす）*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int i, j, x;
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8] = {0};

	srand(time(NULL));

	x = rand() % 9;

	i = j = 0;
	while (i < 9) {
		if (i != x)
			a[j++] = dgt[i];
		i++;
	}

	for (i = 0; i < 8; i++)
		printf("%d", a[i]);

	putchar('\n');

	return 0;
}