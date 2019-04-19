#include<stdio.h>
#include<stdlib.h>
#include"students_info.h"

void save_data(Node*head,int*save)
{
	if(head!=NULL)
	{
		Node*pnode=head;
		FILE*fp;
		if((fp=fopen("data.txt","w"))==NULL)
		{
			fprintf(stderr,"数据库文件打开失败！错误代码：003\n");
			exit(EXIT_FAILURE);
		}
		
		while(pnode!=NULL)
		{
			fprintf(fp,"%s %s %s %d %d %d %d %d %d %d\n",pnode->name,pnode->num,pnode->address,pnode->birth[0],
			pnode->birth[1],pnode->birth[2],pnode->grade[0],pnode->grade[1],pnode->grade[2],pnode->tol);
			
			if(ferror(fp))
			{
				printf("数据保存失败，错误代码：004\n");
				exit(EXIT_FAILURE);
			}
			
			pnode=pnode->next;
		}
		
		fclose(fp);
	}
	
	*save=1;
	printf("数据保存成功！\n");
	system("pause");
}
