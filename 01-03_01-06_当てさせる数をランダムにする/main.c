/* �����ăQ�[���i���̂R�F���Ă����鐔��0�`999�̗����j */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int no;
	int ans;
	
	srand(time(NULL));
	ans = rand() % 1000;
	
	printf("0�`999�̐����𓖂ĂĂ��������B\n\n");
	
	do {
		printf("�������� :");
		scanf("%d", &no);
		
		if(no > ans)
			printf("\a�����Ə�������B\n");
		else if (no < ans)
			printf("\a�����Ƒ傫����B\n");
	} while(no != ans);
	
	printf("�����ł��B\n");
	
	return 0;
}