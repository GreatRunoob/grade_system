#include<stdio.h>
#include<stdlib.h>

int menu(void)
{
	int choice; //��¼�û���ѡ�� 
	
	system("cls"); 
	
	printf("               �˵�ѡ��            \n\n");
	printf("1.��ʾѧ����Ϣ          2.��������ѧ����Ϣ\n");
	printf("3.���/ɾ��/�޸���Ϣ    4.ƽ���ɼ� \n");
	printf("5.�ɼ���ѯ              6.������Ϣ \n");
	printf("7.�˳����� \n");
	
	printf("\n��ѡ��[1/2/3/4/5/6/7]�⼸��ѡ��Ա����ִ����Ӧ�Ĺ��ܣ�");
	scanf("%d",&choice);
	
	putchar('\n');
	
	return choice; //�����û���ѡ�� 
} 
