#include<stdio.h>
#include<stdlib.h>
#include"students_info.h"

Node*free_memory(Node*head)
{
	Node*pnode=head;
	
	while(pnode!=NULL)
	{
		head=pnode->next;
		free(pnode->name);
		free(pnode->num);
		free(pnode->address);
		free(pnode);
		pnode=head;
	}
	
	pnode=head=NULL;
	return head;  //返回空的头指针 
}
