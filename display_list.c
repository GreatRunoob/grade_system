#include<stdio.h>
#include<stdlib.h>
#include"students_info.h"

void display_list(Node*head)
{
	if(head==NULL)
		printf("����������ѧ����Ϣ����������ѧ����Ϣѡ�����ѧ����Ϣ\n");
	else
	{
		Node*pnode=head;
		while(pnode!=NULL)
		{
			printf("name:%s\nnum:%s\naddress:%s\n",pnode->name,pnode->num,pnode->address);
			printf("birthdate:%d-%d-%d\n",pnode->birth[0],pnode->birth[1],pnode->birth[2]);
			printf("chinese:%d\nmath:%d\nenglish:%d\n",pnode->grade[0],pnode->grade[1],pnode->grade[2]);
			printf("total:%d\n\n",pnode->tol);
			pnode=pnode->next;
		}
		printf("��Ϣ������\n");
	}
	
	system("pause");
} 
