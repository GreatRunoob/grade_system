#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"students_info.h"

void find_grade(Node*head)
{
	get_clear();
	
	if(head==NULL)
		printf("����Ϊ�գ���ѡ������ѧ����Ϣ��\n");
	else
	{
		Node*pnode=head;
		char temp[LIMIT];
		printf("��������Ҫ����ѧ����������");
		s_gets(temp);
		
		while(pnode!=NULL)
		{
			if(strcmp(pnode->name,temp)==0)  //����ҵ�ָ����ѧ�� 
				break;
			
			pnode=pnode->next;
		}
		
		if(pnode==NULL)
			printf("û�в��ҵ�%sͬѧ����Ϣ��\n",temp);
		else
			printf("name:%s  CHN:%d  MATH:%d  ENG:%d  TOL:%d\n",
			pnode->name,pnode->grade[0],pnode->grade[1],pnode->grade[2],pnode->tol);
	}
	
	system("pause");
}
