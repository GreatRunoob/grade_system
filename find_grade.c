#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"students_info.h"

void find_grade(Node*head)
{
	get_clear();
	
	if(head==NULL)
		printf("链表为空，请选择输入学生信息！\n");
	else
	{
		Node*pnode=head;
		char temp[LIMIT];
		printf("请输入需要查找学生的姓名：");
		s_gets(temp);
		
		while(pnode!=NULL)
		{
			if(strcmp(pnode->name,temp)==0)  //如果找到指定的学生 
				break;
			
			pnode=pnode->next;
		}
		
		if(pnode==NULL)
			printf("没有查找到%s同学的信息！\n",temp);
		else
			printf("name:%s  CHN:%d  MATH:%d  ENG:%d  TOL:%d\n",
			pnode->name,pnode->grade[0],pnode->grade[1],pnode->grade[2],pnode->tol);
	}
	
	system("pause");
}
