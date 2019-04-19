#include<stdio.h>
#include<stdlib.h>
#include"students_info.h"

int main(void)
{
	Node*head=NULL;  //����ͷָ�� 
	int flag=1,save=1,choice;  //����Ƿ��˳����� 
	
	head=read_data(head);  //��ȡ֮ǰ��������� 
	
	while(flag)  //�ж��û��Ƿ���Ҫ�˳���ѯ���� 
	{
		switch(menu())  //����Ĳ˵�ѡ����� 
		{
			case 1:
				display_list(head);  //��ʾѧ��������Ϣ 
				break;
			case 2:
				head=create_list(head,&save);  //���´����µ�ѧ����Ϣ���� 
				break;
			case 3:
				head=change_list(head,&save);  //��ӡ�ɾ�����޸�ѧ����Ϣ 
				break;
			case 4:
				aver(head);  //����ѧ���ɼ�ƽ���� 
				break;
			case 5:
				find_grade(head);  //��ѯ����������ѧ���ĳɼ���Ϣ 
				break;
			case 6:
				save_data(head,&save);  //������������ 
				break;
			case 7:
				flag=0;  //�˳���ѯ���� 
				break;
			default:
				printf("�޷�ʶ���ѡ��밴Ҫ������ѡ��Ա����ִ����Ӧ������\n");  //����δʶ������ 
				system("pause");
				break;
		}
	}
	
	if(!save)  //�˳�����ǰ������û���δ�������ݣ�ȷ�������Ƿ���Ҫ���� 
	{
		printf("��ʾ������������δ���棬�Ƿ���Ҫ���棬��Ҫ����ѡ��1��������ѡ��0��");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("��ȷ������δ���棡\n");  //ѡ�񲻱������� 
				break;
			case 1:
				save_data(head,&save);  //ѡ�񱣴����� 
				break;
			default:
				printf("�޷�ʶ���ѡ��밴Ҫ������ѡ��Ա����ִ����Ӧ�����Ĭ��Ϊ���������ݣ�\n");  //����δʶ������ 
				break;
		}
		putchar('\n');
	}
	
	free_memory(head);  //�ͷŶ�̬���� 
	
	printf("���˳���ѯϵͳ��\n");
	system("pause");
	
	return 0;
}
