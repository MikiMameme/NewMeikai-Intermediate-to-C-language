/* �����ăQ�[���i���̂Q�u�ʉ��v�F������܂ŌJ��Ԃ� = while���𗘗p����j */

#include<stdio.h>

int main(void)
{
	int no;
	int ans = 7;
	
	printf("�O�`�X�̐����𓖂ĂĂ��������B\n\n");
	
	while(1) {
		printf("�������� :");
		scanf("%d", &no);
		
		if(no > ans)
			printf("\a�����Ə�������B\n");
		else if(no < ans)
			printf("\a�����Ƒ傫����B\n");
		else
			break;
	}
	
	printf("�����ł��B\n");
	
	return 0;
}