#include<stdio.h>
#include<stdlib.h>
#include"students_info.h"

void aver(Node*head)
{
	if(head==NULL)
		printf("链表为空，请选择输入学生信息！\n");
	else  //如果链表不为空 
	{
		Node*pnode=head;
		int i;
		double average,sum;
		
		printf("name      CHN  MATH ENG  AVR\n");
		while(pnode!=NULL)
		{
			for(i=0,sum=0;i<SIZE;i++)
				sum+=pnode->grade[i];
			
			average=sum/SIZE;
			
			printf("%-10s%-5d%-5d%-5d%-5.2f\n",pnode->name,pnode->grade[0],pnode->grade[1],pnode->grade[2],average);
			
			pnode=pnode->next;
		}
	}
	
	system("pause");
}
