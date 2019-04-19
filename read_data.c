#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"students_info.h"

Node*read_data(Node*head)
{
	Node*pnode,*tail;
	FILE*fp;
	char temp[SIZE][LIMIT];
	int birth[SIZE],grade[SIZE],tol,i;
	
	if((fp=fopen("data.txt","r"))==NULL)
	{
		printf("数据文件没有记录！您可以选择输入学生信息！");
	}
	else
	{
		while(fscanf(fp,"%s %s %s %d %d %d %d %d %d %d",
		temp[0],temp[1],temp[2],&birth[0],&birth[1],&birth[2],
		&grade[0],&grade[1],&grade[2],&tol)&&!feof(fp))
		{
			
			if(ferror(fp))
			{
				printf("数据文件读取错误！\n");
				break;
			}
			
			pnode=(Node*)malloc(sizeof(Node));
			if(pnode==NULL)
			{
				fprintf(stderr,"内存请求失败！错误代码001\n");
				exit(EXIT_FAILURE);
			}
			
			pnode->name=(char*)malloc(strlen(temp[0])+1);
			if(pnode->name==NULL)
			{
				fprintf(stderr,"内存请求失败！错误代码002_1\n");
				exit(EXIT_FAILURE);
			}
			strncpy(pnode->name,temp[0],strlen(temp[0])+1);
			
			pnode->num=(char*)malloc(strlen(temp[1])+1);
			if(pnode->num==NULL)
			{
				fprintf(stderr,"内存请求失败！错误代码002_2\n");
				exit(EXIT_FAILURE);
			}
			strncpy(pnode->num,temp[1],strlen(temp[1])+1);
			
			pnode->address=(char*)malloc(strlen(temp[2])+1);
			if(pnode->address==NULL)
			{
				fprintf(stderr,"内存请求失败！错误代码002_3\n");
				exit(EXIT_FAILURE);
			}
			strncpy(pnode->address,temp[2],strlen(temp[2])+1);
			
			for(i=0;i<SIZE;i++)
			{
				pnode->birth[i]=birth[i];
				pnode->grade[i]=grade[i];
			}
			
			pnode->tol=tol;
			
			pnode->next=NULL;
			
			if(head==NULL)
				tail=head=pnode;
			else
			{
				tail->next=pnode;
				tail=pnode;
			}
		}
		
		printf("数据文件读取成功！\n");
		
		fclose(fp);
			
	}
	
	system("pause");
	
	return head;
} 
