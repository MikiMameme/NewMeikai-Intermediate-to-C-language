/*可変個引数をアクセスする個数*/

#include<stdio.h>
#include<stdarg.h>

/*第一引数に応じてそれ以降の引数の和を求める*/
double vsum(int sw, ...)
{
	double sum = 0.0;
	va_list ap;

	/*可変引数アクセス開始*/
	va_start(ap, sw);

	switch (sw) {
	case 0: sum += va_arg(ap, int);
			sum += va_arg(ap, int);
		break;
	case 1: sum += va_arg(ap, int);
			sum += va_arg(ap, long);
			break;
	case 2: sum += va_arg(ap, int);
			sum += va_arg(ap, long);
			sum += va_arg(ap, double);
			break;
	}
	/*可変引数アクセス終了*/
	va_end(ap);

	return sum;
}

int main(void)
{
	printf("10 + 2         = %.2f\n", vsum(0, 10, 2));
	printf("57 + 300000L   = %.2f\n", vsum(1, 57, 300000L));
	printf("98 + 2L + 3.14 = %.2f\n", vsum(2, 98, 2L, 3.14));

	return 0;
}