/* �����𐶐��i���̂Q�F���݂̎����Ɋ�Â��ė����̎��ݒ�j */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int retry;
	
	srand(time(NULL));
	
	printf("���̏����n�ł�0�`%d�̗����������ł��܂��B\n", RAND_MAX);
	
	do{
		printf("\n����%d�𐶐����܂����B\n", rand());
		
		printf("������x�H�c(0)������ (1)�͂� :");
		scanf("%d", &retry);
	} while (retry == 1);
	
	return 0;
}