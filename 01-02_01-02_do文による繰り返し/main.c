/* �����ăQ�[���i���̂Q�F������܂ŌJ��Ԃ� =do���𗘗p�j */

#include<stdio.h>

int main(void)
{
	int no;				/* �ǂݍ��񂾐� */
	int ans = 7;		/* ���Ă����鐔 */
	
	printf("�O�`�X�̐����𓖂ĂĂ��������B\n\n");
	
	do{
		printf("��������:");
		scanf("%d", &no);
		
		if(no > ans)
			printf("\a�����Ə�������B\n");
		else if(no < ans)
			printf("\a�����Ƒ傫����\n");
	} while (no != ans);
	
	printf("�����ł��B\n");
	
	return 0;
}