/* �����ăQ�[���i���̂P�F����Łj */

#include<stdio.h>

int main(void)
{
	int no;
	int ans = 7;
	
	printf("�O�`�X�̐����𓖂ĂĂ��������B\n\n");
	
	printf("��������: ");
	scanf("%d", &no);
	
	if(no > ans)
		printf("\a�����Ə�������B\n");
	
	else if(no < ans)
		printf("\a�����Ƒ傫����B\n");
	
	else
		printf("�����ł��B\n");
	
	return 0;
}