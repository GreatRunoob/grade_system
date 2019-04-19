#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"students_info.h"

Node*change_list(Node*head,int*save)
{
	int choice;
	printf("             �Ӳ˵�\n\n");
	printf("1.�����Ϣ  2.ɾ����Ϣ  3.�޸���Ϣ\n");
	printf("������ѡ��[1/2/3]:");
	scanf("%d",&choice);
	
	putchar('\n');
	
	switch(choice)
	{
		case 1:
			head=add_list(head);
			printf("��Ϣ��ӳɹ�!\n");
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
			printf("�޷�ʶ���ѡ��밴Ҫ������ѡ��Ա����ִ����Ӧ������\n");
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
	
	printf("��������Ҫ��ӵ�ѧ������(����Ϊ0�Ҳ�����100):");
	scanf("%d",&num);
	
	while(num<0||num>100)
	{
		printf("ϵͳ�������ƣ�ѧ����������������ƻ�С����С���ƣ�ѧ����������Ϊ0�Ҳ�����100!"
		"����������ѧ��������");
		scanf("%d",&num);
	} 
	
	if(head==NULL)
	{
		for(i=0;i<num;i++)
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
		while(tail->next!=NULL)  //Ѱ�ҵ��������β�ڵ㣬����½ڵ� 
			tail=tail->next;
		
		for(i=0;i<num;i++)
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
		printf("����Ϊ�գ�û��ѧ����Ϣ���Ա�ɾ����");
	else
	{
		printf("��������Ҫɾ����ѧ����������");
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
			printf("û�в��ҵ�%sͬѧ����Ϣ��\n",temp);
		else
		{
			free(pnode->name);
			free(pnode->num);
			free(pnode->address);
			free(pnode);
			pnode=NULL;
			printf("��Ϣɾ���ɹ���\n");
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
		printf("����Ϊ�գ�û�п����޸ĵ�ѧ����Ϣ��\n");
	else
	{
		printf("��������Ҫ�޸���Ϣ��ͬѧ��������");
		s_gets(temp);
		
		while(pnode!=NULL)
		{
			if(strcmp(pnode->name,temp)==0)
				break;
			
			pnode=pnode->next;
		}
		
		if(pnode==NULL)
			printf("û�в��ҵ�%sͬѧ����Ϣ��\n",temp);
		else
		{
			printf("\n      �޸Ĳ˵�\n");
			printf("1.�޸�%sͬѧ��ѧ��\n",temp);
			printf("2.�޸�%sͬѧ��סַ\n",temp);
			printf("3.�޸�%sͬѧ��������Ϣ\n",temp);
			printf("4.�޸�%sͬѧ�����ĳɼ�\n",temp);
			printf("5.�޸�%sͬѧ����ѧ�ɼ�\n",temp);
			printf("6.�޸�%sͬѧ��Ӣ��ɼ�\n",temp);
			printf("������ѡ��[1/2/3/4/5/6]��");
			scanf("%d",&choice);
			
			get_clear();
			switch(choice)
			{
				case 1:
					printf("��ǰ%sͬѧ��ѧ��Ϊ%s���������޸ĺ��ѧ�ţ�",temp,pnode->num);
					s_gets(data);
					free(pnode->num);
					
					pnode->num=(char*)malloc(strlen(data)+1);
					if(pnode->num==NULL)
					{
						fprintf(stderr,"�ڴ�����ʧ�ܣ��������002_2\n");
						exit(EXIT_FAILURE);
					}
					strncpy(pnode->num,data,strlen(data)+1);
					break;
				case 2:
					printf("��ǰ%sͬѧ��סַΪ%s���������޸ĺ��סַ��",temp,pnode->address);
					s_gets(data);
					free(pnode->address);
					
					pnode->address=(char*)malloc(strlen(data)+1);
					if(pnode->address==NULL)
					{
						fprintf(stderr,"�ڴ�����ʧ�ܣ��������002_3\n");
						exit(EXIT_FAILURE);
					}
					strncpy(pnode->address,data,strlen(data)+1);
					break;
				case 3:
					printf("��ǰ%sͬѧ������Ϊ%d-%d-%d�������������޸ĺ�������գ�",temp,pnode->birth[0],pnode->birth[1],pnode->birth[2]);
					for(index=0;index<SIZE;index++)
					{
						scanf("%d",&pnode->birth[index]);
					}
					break;
				case 4:
					printf("��ǰ%sͬѧ�����ĳɼ�Ϊ%d���������޸ĺ�����ĳɼ���",temp,pnode->grade[0]);
					scanf("%d",&pnode->grade[0]);
					for(index=0,pnode->tol=0;index<SIZE;index++)  //����ѧ���ܳɼ� 
						pnode->tol+=pnode->grade[index];
					break;
				case 5:
					printf("��ǰ%sͬѧ����ѧ�ɼ�Ϊ%d���������޸ĺ����ѧ�ɼ���",temp,pnode->grade[1]);
					scanf("%d",&pnode->grade[1]);
					for(index=0,pnode->tol=0;index<SIZE;index++)  //����ѧ���ܳɼ� 
						pnode->tol+=pnode->grade[index];
					break;
				case 6:
					printf("��ǰ%sͬѧ��Ӣ��ɼ�Ϊ%d���������޸ĺ��Ӣ��ɼ���",temp,pnode->grade[2]);
					scanf("%d",&pnode->grade[2]);
					for(index=0,pnode->tol=0;index<SIZE;index++)  //����ѧ���ܳɼ� 
						pnode->tol+=pnode->grade[index];
					break;
				default:
					printf("�޷�ʶ���ѡ��밴Ҫ������ѡ��Ա����ִ����Ӧ������\n");
					break;
			}
		}
	}
	
	return head;
}
