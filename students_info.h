#ifndef INFO
#define INFO

#define LIMIT 50  //�ַ�������������� 
#define SIZE 3  //���ѧ������ 

typedef struct students{
	char*name;
	char*num;
	char*address;
	int birth[SIZE];
	int grade[SIZE];
	int tol;
	struct students*next;
}Node;  //ѧ����Ϣ�洢�ṹ 

Node*read_data(Node*head);  //��ȡ�����ļ����� 

int menu(void);  //�˵����� 

Node*create_list(Node*head,int*save);  //���´����µ����� 
Node*input_info(Node*head);  //create_list()�����ĸ�������������ѧ����Ϣ������ 

void display_list(Node*head);  //��ʾѧ����������Ϣ 

Node*change_list(Node*head,int*save);  //�޸�ѧ����Ϣ 
Node*add_list(Node*head);  //�������������ѧ����Ϣ 
Node*delete_list(Node*head);  //����������ɾ��ѧ����Ϣ 
Node*change(Node*head);  //�����������޸�ָ��ѧ������Ϣ 

void aver(Node*head);  //����ѧ���ɼ�ƽ���� 

void find_grade(Node*head);  //����ָ��ѧ���ĳɼ���Ϣ 

void save_data(Node*head,int*save);  //���浱ǰ���������� 

Node*free_memory(Node*head);  //�ͷŶ�̬�ڴ� 

char*s_gets(char*str);  //���Ƶ������ַ������뺯�� 
void get_clear(void);  //ˢ�»��������ַ� 

#endif 
