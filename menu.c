#include<stdio.h>
#include<stdlib.h>

int menu(void)
{
	int choice; //记录用户的选项 
	
	system("cls"); 
	
	printf("               菜单选项            \n\n");
	printf("1.显示学生信息          2.重新输入学生信息\n");
	printf("3.添加/删除/修改信息    4.平均成绩 \n");
	printf("5.成绩查询              6.保存信息 \n");
	printf("7.退出程序 \n");
	
	printf("\n请选择[1/2/3/4/5/6/7]这几个选项，以便程序执行相应的功能：");
	scanf("%d",&choice);
	
	putchar('\n');
	
	return choice; //返回用户的选择 
} 
