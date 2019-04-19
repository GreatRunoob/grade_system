#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"students_info.h"

Node*create_list(Node*head,int*save)
{
	int clear;  //询问是否清空学生信息 
	
	if(head)  //如果链表里面含有学生信息 
	{
		printf("当前链表中含有之前学生的信息，是否清空链表？注意，该操作不可逆，请谨慎选择！\n"
		"当然最后退出时也可选择不保留本次输入，用于恢复上次的输入\n");
		printf("清空链表选择1，保留链表选择0：");
		scanf("%d",&clear);
		if(clear)
		{
			head=free_memory(head);
			head=input_info(head);
			*save=0;
			printf("\n信息录入完成\n");
			system("pause");
		}
	}
	else
	{
		head=input_info(head);
		*save=0;
		printf("\n信息录入完成\n");
		system("pause");
	}
	
	return head;
}

Node*input_info(Node*head)
{
	Node*tail,*pnode;
	int stu_num,i,j;
	char temp[LIMIT];
	
	printf("请输入需要输入的学生数量：(至少为0且不超过100000)");
	scanf("%d",&stu_num);
	
	while(stu_num>100000||stu_num<0)
	{
		printf("系统保护机制：学生数量超过最大限制或小于最小限制，学生数量至少为0且不超过1000!"
		"请重新输入学生数量：");
		scanf("%d",&stu_num);
	}
	
	for(i=0;i<stu_num;i++)
	{
		pnode=(Node*)malloc(sizeof(Node));
		if(pnode==NULL)
		{
			fprintf(stderr,"内存请求失败！错误代码001\n");
			exit(EXIT_FAILURE);
		}
		
		get_clear();
		printf("请输入第%d位学生的姓名：",i+1);
		s_gets(temp);
		pnode->name=(char*)malloc(strlen(temp)+1);
		if(pnode->name==NULL)
		{
			fprintf(stderr,"内存请求失败！错误代码002_1\n");
			exit(EXIT_FAILURE);
		}
		strncpy(pnode->name,temp,strlen(temp)+1);
		
		
		printf("请输入该学生的学号：");
		s_gets(temp);
		pnode->num=(char*)malloc(strlen(temp)+1);
		if(pnode->num==NULL)
		{
			fprintf(stderr,"内存请求失败！错误代码002_2\n");
			exit(EXIT_FAILURE);
		}
		strncpy(pnode->num,temp,strlen(temp)+1);
		
		
		printf("请输入该学生的地址：");
		s_gets(temp);
		pnode->address=(char*)malloc(strlen(temp)+1);
		if(pnode->address==NULL)
		{
			fprintf(stderr,"内存请求失败！错误代码002_3\n");
			exit(EXIT_FAILURE);
		}
		strncpy(pnode->address,temp,strlen(temp)+1);
		
		
		printf("请依次输入该学生的出生年、月、日：");
		for(j=0;j<SIZE;j++)
			scanf("%d",&pnode->birth[j]);
		
		
		printf("请依次输入该学生的语、数、英三门课程的成绩：");
		for(j=0;j<SIZE;j++)
			scanf("%d",&pnode->grade[j]);
		
		for(j=0,pnode->tol=0;j<SIZE;j++)  //计算成绩总分 
			pnode->tol+=pnode->grade[j];
		
		pnode->next=NULL;
		
		if(head==NULL)
		{
			tail=head=pnode;
		}
		else
		{
			tail->next=pnode;
			tail=pnode;
		}
	}
	
	return head;
}
