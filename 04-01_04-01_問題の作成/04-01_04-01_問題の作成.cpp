/*相異なる4つの数字の並びを生成して配列xに格納(コードのみ)*/

void make4digits(int x[])
{
	int i, j, val;

	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 10;
			for (j = 0; j < i; i++)
				if (val == x[j])
					break;
		} while (j < i);
	}
}
