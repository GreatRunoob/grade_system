#ifndef INFO
#define INFO

#define LIMIT 50  //字符串最大输入限制 
#define SIZE 3  //最大学科限制 

typedef struct students{
	char*name;
	char*num;
	char*address;
	int birth[SIZE];
	int grade[SIZE];
	int tol;
	struct students*next;
}Node;  //学生信息存储结构 

Node*read_data(Node*head);  //读取数据文件内容 

int menu(void);  //菜单界面 

Node*create_list(Node*head,int*save);  //重新创建新的链表 
Node*input_info(Node*head);  //create_list()函数的附属函数，处理学生信息的输入 

void display_list(Node*head);  //显示学生的所有信息 

Node*change_list(Node*head,int*save);  //修改学生信息 
Node*add_list(Node*head);  //附属函数，添加学生信息 
Node*delete_list(Node*head);  //附属函数，删除学生信息 
Node*change(Node*head);  //附属函数，修改指定学生的信息 

void aver(Node*head);  //计算学生成绩平均分 

void find_grade(Node*head);  //查找指定学生的成绩信息 

void save_data(Node*head,int*save);  //保存当前的链表数据 

Node*free_memory(Node*head);  //释放动态内存 

char*s_gets(char*str);  //自制的整行字符串读入函数 
void get_clear(void);  //刷新缓冲区的字符 

#endif 
