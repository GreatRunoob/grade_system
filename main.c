#include<stdio.h>
#include<stdlib.h>
#include"students_info.h"

int main(void)
{
	Node*head=NULL;  //链表头指针 
	int flag=1,save=1,choice;  //标记是否退出程序 
	
	head=read_data(head);  //读取之前保存的数据 
	
	while(flag)  //判断用户是否想要退出查询界面 
	{
		switch(menu())  //精简的菜单选择代码 
		{
			case 1:
				display_list(head);  //显示学生所有信息 
				break;
			case 2:
				head=create_list(head,&save);  //重新创建新的学生信息链表 
				break;
			case 3:
				head=change_list(head,&save);  //添加、删除、修改学生信息 
				break;
			case 4:
				aver(head);  //计算学生成绩平均分 
				break;
			case 5:
				find_grade(head);  //查询现有链表中学生的成绩信息 
				break;
			case 6:
				save_data(head,&save);  //保存链表数据 
				break;
			case 7:
				flag=0;  //退出查询界面 
				break;
			default:
				printf("无法识别的选项，请按要求输入选项，以便程序执行相应的命令\n");  //处理未识别命令 
				system("pause");
				break;
		}
	}
	
	if(!save)  //退出程序前，如果用户尚未保存数据，确认数据是否需要保存 
	{
		printf("提示：本次数据尚未保存，是否需要保存，需要保存选择1，不保存选择0：");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("已确认数据未保存！\n");  //选择不保存数据 
				break;
			case 1:
				save_data(head,&save);  //选择保存数据 
				break;
			default:
				printf("无法识别的选项，请按要求输入选项，以便程序执行相应的命令，默认为不保存数据！\n");  //处理未识别命令 
				break;
		}
		putchar('\n');
	}
	
	free_memory(head);  //释放动态链表 
	
	printf("已退出查询系统！\n");
	system("pause");
	
	return 0;
}
