#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"students_info.h"

Node*create_list(Node*head,int*save)
{
	int clear;  //ѯ���Ƿ����ѧ����Ϣ 
	
	if(head)  //����������溬��ѧ����Ϣ 
	{
		printf("��ǰ�����к���֮ǰѧ������Ϣ���Ƿ��������ע�⣬�ò��������棬�����ѡ��\n"
		"��Ȼ����˳�ʱҲ��ѡ�񲻱����������룬���ڻָ��ϴε�����\n");
		printf("�������ѡ��1����������ѡ��0��");
		scanf("%d",&clear);
		if(clear)
		{
			head=free_memory(head);
			head=input_info(head);
			*save=0;
			printf("\n��Ϣ¼�����\n");
			system("pause");
		}
	}
	else
	{
		head=input_info(head);
		*save=0;
		printf("\n��Ϣ¼�����\n");
		system("pause");
	}
	
	return head;
}

Node*input_info(Node*head)
{
	Node*tail,*pnode;
	int stu_num,i,j;
	char temp[LIMIT];
	
	printf("��������Ҫ�����ѧ��������(����Ϊ0�Ҳ�����100000)");
	scanf("%d",&stu_num);
	
	while(stu_num>100000||stu_num<0)
	{
		printf("ϵͳ�������ƣ�ѧ����������������ƻ�С����С���ƣ�ѧ����������Ϊ0�Ҳ�����1000!"
		"����������ѧ��������");
		scanf("%d",&stu_num);
	}
	
	for(i=0;i<stu_num;i++)
	{
		pnode=(Node*)malloc(sizeof(Node));
		if(pnode==NULL)
		{
			fprintf(stderr,"�ڴ�����ʧ�ܣ��������001\n");
			exit(EXIT_FAILURE);
		}
		
		get_clear();
		printf("�������%dλѧ����������",i+1);
		s_gets(temp);
		pnode->name=(char*)malloc(strlen(temp)+1);
		if(pnode->name==NULL)
		{
			fprintf(stderr,"�ڴ�����ʧ�ܣ��������002_1\n");
			exit(EXIT_FAILURE);
		}
		strncpy(pnode->name,temp,strlen(temp)+1);
		
		
		printf("�������ѧ����ѧ�ţ�");
		s_gets(temp);
		pnode->num=(char*)malloc(strlen(temp)+1);
		if(pnode->num==NULL)
		{
			fprintf(stderr,"�ڴ�����ʧ�ܣ��������002_2\n");
			exit(EXIT_FAILURE);
		}
		strncpy(pnode->num,temp,strlen(temp)+1);
		
		
		printf("�������ѧ���ĵ�ַ��");
		s_gets(temp);
		pnode->address=(char*)malloc(strlen(temp)+1);
		if(pnode->address==NULL)
		{
			fprintf(stderr,"�ڴ�����ʧ�ܣ��������002_3\n");
			exit(EXIT_FAILURE);
		}
		strncpy(pnode->address,temp,strlen(temp)+1);
		
		
		printf("�����������ѧ���ĳ����ꡢ�¡��գ�");
		for(j=0;j<SIZE;j++)
			scanf("%d",&pnode->birth[j]);
		
		
		printf("�����������ѧ���������Ӣ���ſγ̵ĳɼ���");
		for(j=0;j<SIZE;j++)
			scanf("%d",&pnode->grade[j]);
		
		for(j=0,pnode->tol=0;j<SIZE;j++)  //����ɼ��ܷ� 
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
