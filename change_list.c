#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"students_info.h"

Node*change_list(Node*head,int*save)
{
	int choice;
	printf("             子菜单\n\n");
	printf("1.添加信息  2.删除信息  3.修改信息\n");
	printf("请输入选择[1/2/3]:");
	scanf("%d",&choice);
	
	putchar('\n');
	
	switch(choice)
	{
		case 1:
			head=add_list(head);
			printf("信息添加成功!\n");
			*save=0;
			break;
		case 2:
			head=delete_list(head);
			*save=0;
			break;
		case 3:
			head=change(head);
			*save=0;
			break;
		default:
			printf("无法识别的选项，请按要求输入选项，以便程序执行相应的命令\n");
			break;
	}
	
	system("pause");
	return head;
}


Node*add_list(Node*head)
{
	Node*pnode,*tail;
	char temp[LIMIT];
	int num,i,j; 
	
	printf("请输入需要添加的学生数量(至少为0且不超过100):");
	scanf("%d",&num);
	
	while(num<0||num>100)
	{
		printf("系统保护机制：学生数量超过最大限制或小于最小限制，学生数量至少为0且不超过100!"
		"请重新输入学生数量：");
		scanf("%d",&num);
	} 
	
	if(head==NULL)
	{
		for(i=0;i<num;i++)
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
				tail=head=pnode;
			else
			{
				tail->next=pnode;
				tail=pnode;
			}
		}
	}
	else
	{
		tail=head;
		while(tail->next!=NULL)  //寻找到该链表的尾节点，添加新节点 
			tail=tail->next;
		
		for(i=0;i<num;i++)
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
			
			tail->next=pnode;
			tail=pnode;
		}
	}
	
	
	return head;
}


Node*delete_list(Node*head)
{
	Node*pnode,*form;
	char temp[LIMIT];
	
	get_clear();
	if(head==NULL)
		printf("链表为空，没有学生信息可以被删除！");
	else
	{
		printf("请输入需要删除的学生的姓名：");
		s_gets(temp);
		
		if(strcmp(head->name,temp)==0)
		{
			pnode=head;
			head=head->next;
		}
		else
		{
			pnode=head->next;
			form=head;
			while(pnode!=NULL)
			{
				if(strcmp(pnode->name,temp)==0)
				{
					form->next=pnode->next;
					break;
				}
				
				form=pnode;
				pnode=pnode->next;
			}
		}
		
		if(pnode==NULL)
			printf("没有查找到%s同学的信息！\n",temp);
		else
		{
			free(pnode->name);
			free(pnode->num);
			free(pnode->address);
			free(pnode);
			pnode=NULL;
			printf("信息删除成功！\n");
		}
	}
	
	return head;
}


Node*change(Node*head)
{
	Node*pnode=head,*cur;
	char temp[LIMIT],data[LIMIT];
	int choice,index;
	
	get_clear();
	if(head==NULL)
		printf("链表为空，没有可以修改的学生信息！\n");
	else
	{
		printf("请输入需要修改信息的同学的姓名：");
		s_gets(temp);
		
		while(pnode!=NULL)
		{
			if(strcmp(pnode->name,temp)==0)
				break;
			
			pnode=pnode->next;
		}
		
		if(pnode==NULL)
			printf("没有查找到%s同学的信息！\n",temp);
		else
		{
			printf("\n      修改菜单\n");
			printf("1.修改%s同学的学号\n",temp);
			printf("2.修改%s同学的住址\n",temp);
			printf("3.修改%s同学的生日信息\n",temp);
			printf("4.修改%s同学的语文成绩\n",temp);
			printf("5.修改%s同学的数学成绩\n",temp);
			printf("6.修改%s同学的英语成绩\n",temp);
			printf("请输入选项[1/2/3/4/5/6]：");
			scanf("%d",&choice);
			
			get_clear();
			switch(choice)
			{
				case 1:
					printf("当前%s同学的学号为%s，请输入修改后的学号：",temp,pnode->num);
					s_gets(data);
					free(pnode->num);
					
					pnode->num=(char*)malloc(strlen(data)+1);
					if(pnode->num==NULL)
					{
						fprintf(stderr,"内存请求失败！错误代码002_2\n");
						exit(EXIT_FAILURE);
					}
					strncpy(pnode->num,data,strlen(data)+1);
					break;
				case 2:
					printf("当前%s同学的住址为%s，请输入修改后的住址：",temp,pnode->address);
					s_gets(data);
					free(pnode->address);
					
					pnode->address=(char*)malloc(strlen(data)+1);
					if(pnode->address==NULL)
					{
						fprintf(stderr,"内存请求失败！错误代码002_3\n");
						exit(EXIT_FAILURE);
					}
					strncpy(pnode->address,data,strlen(data)+1);
					break;
				case 3:
					printf("当前%s同学的生日为%d-%d-%d，请依次输入修改后的年月日：",temp,pnode->birth[0],pnode->birth[1],pnode->birth[2]);
					for(index=0;index<SIZE;index++)
					{
						scanf("%d",&pnode->birth[index]);
					}
					break;
				case 4:
					printf("当前%s同学的语文成绩为%d，请输入修改后的语文成绩：",temp,pnode->grade[0]);
					scanf("%d",&pnode->grade[0]);
					for(index=0,pnode->tol=0;index<SIZE;index++)  //更新学生总成绩 
						pnode->tol+=pnode->grade[index];
					break;
				case 5:
					printf("当前%s同学的数学成绩为%d，请输入修改后的数学成绩：",temp,pnode->grade[1]);
					scanf("%d",&pnode->grade[1]);
					for(index=0,pnode->tol=0;index<SIZE;index++)  //更新学生总成绩 
						pnode->tol+=pnode->grade[index];
					break;
				case 6:
					printf("当前%s同学的英语成绩为%d，请输入修改后的英语成绩：",temp,pnode->grade[2]);
					scanf("%d",&pnode->grade[2]);
					for(index=0,pnode->tol=0;index<SIZE;index++)  //更新学生总成绩 
						pnode->tol+=pnode->grade[index];
					break;
				default:
					printf("无法识别的选项，请按要求输入选项，以便程序执行相应的命令\n");
					break;
			}
		}
	}
	
	return head;
}
