#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char num[15];
	char name[15];
	char major[10];
	int classNo;
	int score[3];
	struct student *next;
}STU;

STU* CreateList(void);
STU* CreateList_from_file(char* file_path);
void Output(STU* p);
void Output_all(STU* pHead);
int judge_file_name_txt(char* file_path);
int judge_file_name_dat(char* file_path);
STU* save(STU* pHead, char* file_path, char* num);
void save_all(STU* pHead, char* file_path);
STU* Fetch(char* file_path);
STU* Search_num(STU* pHead, char* num);
void InsertList(STU* pHead, STU* astu);
void Delete_num(STU* pHead, char* num);
STU* Search_major_subject_score(STU* pHead, char* major, int course, int score);
void Delete_class_subject_score(STU* pHead, int classNo, int course, int score);
STU* Max(STU* pHead, int course);

int main()
{
	printf("��ӭʹ��ѧ����Ϣ����ϵͳ!\n");
	STU* pHead = (STU*)malloc(sizeof(STU));
	int choice;
	while (1)
	{
		printf("0.���ı��ж�ȡѧ����Ϣ\n");
		printf("1.�Ӽ�������ѧ����Ϣ\n");
		printf("2.���ȫ��ѧ����Ϣ\n");
		printf("3.��ָ��ѧ��ѧ����Ϣ�����ļ�\n");
		printf("4.ȫ��ѧ����Ϣ�����ļ�\n");
		printf("5.��ȡ�������ļ���ѧ����Ϣ\n");
		printf("6.����ָ��ѧ�ŵ�ѧ��\n");
		printf("7.����ѧ����Ϣ\n");
		printf("8.ɾ��ָ��ѧ��ѧ����Ϣ\n");
		printf("9.����ĳ��רҵ�ġ�ĳ�ſγ̵ĳɼ�С��ĳ��������ѧ��\n");
		printf("10.ɾ��ĳ���༶�ġ�ĳ�ſγ̵ĳɼ�С��ĳ��������ѧ��\n");
		printf("11.����ĳ�ſγ̵���߳ɼ�\n");
		printf("��ѡ����:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
		{
			char file_path[50];
			printf("�������ı��ļ�·��:");
			scanf("%s", file_path);
			while (judge_file_name_txt(file_path) == 0)   //�ж������ļ�·���Ƿ���ȷ
			{
				printf("����������:");
				scanf("%s", file_path);
			}				
			pHead = CreateList_from_file(file_path);
			printf("\n\n\n\n");
			break;
		}
		case 1:
		{
			pHead = CreateList();
			printf("\n\n\n\n");
			break;
		}
		case 2:
		{
			Output_all(pHead);
			printf("\n\n\n\n");
			break;
		}
		case 3:
		{
			char num[15];
			char file_path[50];
			printf("������Ҫ�����ѧ��ѧ��:");
			scanf("%s", num);
			printf("�����뱣���ļ�·��:");
			scanf("%s", file_path);
			while (judge_file_name_dat(file_path) == 0)   //�ж������ļ�·���Ƿ���ȷ
				scanf("%s", file_path);
			STU* s = save(pHead, file_path, num);
			if (s == NULL)
				printf("û��ѧ��Ϊ%s��ѧ��", num);
			printf("\n\n\n\n");
			break;
		}
		case 4:
		{
			char file_path[50];
			printf("�����뱣���ļ�·��:");
			scanf("%s", file_path);
			while (judge_file_name_dat(file_path) == 0)   //�ж������ļ�·���Ƿ���ȷ
			{
				printf("����������:");
				scanf("%s", file_path);
			}
			save_all(pHead, file_path);
			printf("\n\n\n\n");
			break;
		}
		case 5:
		{
			char file_path[50];
			printf("�������ȡ�ļ�·��:");
			scanf("%s", file_path);
			while (judge_file_name_dat(file_path) == 0)   //�ж������ļ�·���Ƿ���ȷ
			{
				printf("����������:");
				scanf("%s", file_path);
			}
			STU* H = (STU*)malloc(sizeof(STU));
			H = Fetch(file_path);
			printf("������ѧ����ϢΪ:\n");
			Output_all(H);
			printf("\n\n\n\n");
			break;
		}
		case 6:
		{
			char num[15]; STU* s;
			printf("������Ҫ���ҵ�ѧ��:");
			scanf("%s", num);
			s = Search_num(pHead, num);
			if (s == NULL)
				printf("û��ѧ��Ϊ%s��ѧ��\n", num);
			else
			{
				printf("ѧ��\t\t����\t\tרҵ\t\t�༶\t�ɼ�1\t�ɼ�2\t�ɼ�3\n");
				Output(s);
			}
			printf("\n\n\n\n");
			break;
		}
		case 7:
		{
			STU* s = (STU*)malloc(sizeof(STU));
			printf("������ѧ��ѧ��:");
			scanf("%s", s->num);
			printf("������ѧ������:");
			scanf("%s", s->name);
			printf("������ѧ��רҵ:");
			scanf("%s", s->major);
			printf("������ѧ���༶:");
			scanf("%d", &s->classNo);
			for (int j = 0; j < 3; ++j)
			{
				printf("������ѧ����%d�ſεĳɼ���", j + 1);
				scanf("%d", &s->score[j]);
			}
			InsertList(pHead, s);
			printf("������ѧ����ϢΪ:\n");
			Output_all(pHead);
			printf("\n\n\n\n");
			break;
		}
		case 8:
		{
			char num[15];
			printf("������Ҫɾ����ѧ��ѧ��:");
			scanf("%s", num);
			Delete_num(pHead, num);
			printf("ɾ����ʣ���ѧ����ϢΪ:\n");
			Output_all(pHead);
			printf("\n\n\n\n");
			break;
		}
		case 9:
		{
			STU* H = (STU*)malloc(sizeof(STU));
			char major[10];
			int course, score;
			printf("������רҵ:");
			scanf("%s", major);
			printf("������γ̺�(1-3):");
			scanf("%d", &course);
			while (course < 1 || course>3)
			{
				printf("\n���벻�Ϸ�������������:");
				scanf("%d", &course);
			}
			printf("���������:");
			scanf("%d", &score);
			H = Search_major_subject_score(pHead, major, course - 1, score);
			if (H->next)
				printf("û���ҵ���ѧ��\n");
			else
			{
				printf("�ҵ���ѧ����:\n");
				Output_all(H);
			}
			printf("\n\n\n\n");
			break;
		}
		case 10:
		{
			int classNo;
			int course;
			int score;
			printf("������༶��(1��2):");
			scanf("%d", &classNo);
			while (classNo < 1 || classNo > 2)
			{
				printf("\n���벻�Ϸ�������������:");
				scanf("%d", &classNo);
			}
			printf("������γ̺�(1-3):");
			scanf("%d", &course);
			while (course < 1 || course > 3)
			{
				printf("\n���벻�Ϸ�������������:");
				scanf("%d", &course);
			}
			printf("������ɼ�:");
			scanf("%d", &score);
			Delete_class_subject_score(pHead, classNo, course - 1, score);
			printf("ɾ����ʣ��ѧ����:\n");
			Output_all(pHead);
			printf("\n\n\n\n");
			break;
		}
		case 11:
		{
			STU* max;
			int course;
			printf("������γ̺�(1-3):");
			scanf("%d", &course);
			while (course < 1 || course > 3)
			{
				printf("\n���벻�Ϸ�������������:");
				scanf("%d", &course);
			}
			max = Max(pHead, course - 1);
			printf("��ѧ����ϢΪ:\n");
			printf("ѧ��\t\t����\t\tרҵ\t\t�༶\t�ɼ�1\t�ɼ�2\t�ɼ�3\n");
			Output(max);
			break;
		}
		default:
			printf("\n�����д�����������:");
			scanf("%d", &choice);
			printf("\n\n\n\n");
			break;
		}
	}
	return 0;
}


STU* CreateList(void)
{	
	STU* pHead = (STU*)malloc(sizeof(STU));
	STU* first = NULL;    //�׽ڵ��ָ�룬ÿ�β嵽firstǰ��
	int n;
	printf("������ѧ������:");
	scanf("%d", &n);
	for(int i = 0;i<n;++i)
	{
		STU* p = (STU*)malloc(sizeof(STU));
		printf("������ѧ��ѧ��(�Ӵ�С):");
		scanf("%s", p->num);
		if (i > 0)     //�ж��Ƿ����ɴ�С�����
		{
			if (strcmp(first->num, p->num) <= 0)
			{
				printf("ѧ��Ӧ���ǴӴ�С����!\n");
				--i;
				continue;
			}
		}
		printf("\n������ѧ������:");
		scanf("%s", p->name);
		printf("\n������ѧ��רҵ:");
		scanf("%s", p->major);
		printf("\n������ѧ���༶:");
		scanf("%d", &p->classNo);
		for (int j = 0; j < 3; ++j)
		{
			printf("\n������ѧ����%d�ſεĳɼ���", j+1);
			scanf("%d", &p->score[j]);
		}
		p->next = first;
		first = p;   //�²���ı�Ϊ�׽ڵ�
		pHead->next = p;
	}
	return pHead;
}


STU* CreateList_from_file(char* file_path)
{
	FILE* fp = fopen(file_path, "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!");
		return NULL;
	}
	STU* pHead = (STU*)malloc(sizeof(STU));
	STU* first = NULL;
	while (!feof(fp))
	{
		STU* p = (STU*)malloc(sizeof(STU));
		fscanf(fp, "%s %s %s %d %d %d %d", p->num, p->name, p->major, &p->classNo, &p->score[0], &p->score[1], &p->score[2]);
		if (first)
		{
			if (strcmp(first->num, p->num) <= 0)
			{
				printf("�ļ��е�ѧ��Ӧ���ǴӴ�С��,���޸��ļ�!\n");
				free(p);
				return NULL;
			}
		}
		p->next = first;
		first = p;
		pHead->next = p;
	}
	return pHead;
}


void Output(STU *p) 
{
	printf("%-15s%-15s\t%-15s\t%d\t%d\t%d\t%d\n", p->num, p->name, p->major, p->classNo, p->score[0], p->score[1], p->score[2]);
}


void Output_all(STU * pHead)
{
	STU *p;
	p = pHead->next;
	printf("ѧ��\t\t����\t\tרҵ\t\t�༶\t�ɼ�1\t�ɼ�2\t�ɼ�3\n");
	while (p != NULL)
	{//�������ѧ����Ϣ
		Output(p);
		p = p->next;//��ָ��ָ����һ�����
	}
}


int judge_file_name_txt(char* file_path)
{
	int flag = 1;       //·����ȷ�ı�־����������0Ϊ����ȷ����������
	int tag = 0;        //��־�ַ����е�һ��'\'�ǵ�һ�����ǵڶ�����1Ϊ��һ����0Ϊ�ڶ���
	for (int i = 0; i < strlen(file_path) - 1; ++i)
	{
		if (file_path[i] == '\\')
			tag = 1 - tag;
		if (file_path[i] == '\\' && file_path[i + 1] != '\\' && tag)  //�ж��Ƿ���\\����
		{
			flag = 0;
			printf("·����Ҫ��\\����\n");
			break;
		}
	}
	//�жϺ�׺����Ӧ��Ϊ.txt����������
	if (file_path[strlen(file_path) - 1] != 't' || file_path[strlen(file_path) - 2] != 'x' || file_path[strlen(file_path) - 3] != 't' || file_path[strlen(file_path) - 4] != '.')
	{
		flag = 0;
		printf("��׺������\n");
	}
	return flag;
}


int judge_file_name_dat(char* file_path)
{
	int flag = 1;       //·����ȷ�ı�־����������0Ϊ����ȷ����������
	int tag = 0;        //��־�ַ����е�һ��'\'�ǵ�һ�����ǵڶ�����1Ϊ��һ����0Ϊ�ڶ���
	for (int i = 0; i < strlen(file_path) - 1; ++i)
	{
		if (file_path[i] == '\\')
			tag = 1 - tag;
		if (file_path[i] == '\\' && file_path[i + 1] != '\\' && tag)  //�ж��Ƿ���\\����
		{
			flag = 0;
			printf("·����Ҫ��\\����\n");
			break;
		}
	}
	//�жϺ�׺����Ӧ��Ϊ.dat����������
	if (file_path[strlen(file_path) - 1] != 't' || file_path[strlen(file_path) - 2] != 'a' || file_path[strlen(file_path) - 3] != 'd' || file_path[strlen(file_path) - 4] != '.')
	{
		flag = 0;
		printf("��׺������\n");
	}
	return flag;
}


STU* save(STU* pHead, char* file_path, char* num)
{
	FILE* fp = fopen(file_path, "ab");     //�ļ���׷��ģʽ
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!");
		return NULL;
	}
	STU* p = pHead->next;   //��ָ��p���������ҵ���Ӧѧ�Žڵ�
	while (p)
	{
		if (strcmp(p->num, num) == 0)
		{
			fwrite(p, sizeof(STU), 1, fp);
			fclose(fp);
			return p;
		}
		p = p->next;
	}
	fclose(fp);
	return NULL;
}


void save_all(STU* pHead, char* file_path)
{
	FILE* fp = fopen(file_path, "wb");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}
	STU* p = pHead->next;
	while (p)
	{
		fwrite(p, sizeof(STU), 1, fp);
		p = p->next;
	}
	fclose(fp);
}


STU* Fetch(char* file_path)
{
	STU* pHead = (STU*)malloc(sizeof(STU));
	STU* rear = pHead;   //βָ��
	STU* temp = (STU*)malloc(sizeof(STU));
	FILE* fp = fopen(file_path, "rb");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!");
		return NULL;
	}
	fread(temp, sizeof(STU), 1, fp);    //��Ҫ���ȶ�һ���������ж��ļ��Ƿ����
	while (!feof(fp))    //�ж��ļ��Ƿ��ȡ����
	{
		STU* p = (STU*)malloc(sizeof(STU));
		*p = *temp;
		p->next = NULL;  //˳��������
		rear->next = p;
		rear = p;
		fread(temp, sizeof(STU), 1, fp);
	}
	fclose(fp);
	return pHead;
}


STU* Search_num(STU* pHead, char* num)
{
	STU* p = pHead->next;
	while (p)
	{
		if (strcmp(num, p->num) == 0)
			return p;
		p = p->next;
	}
	return NULL;
}


void InsertList(STU* pHead, STU* astu)
{
	STU* p = pHead->next;
	if (strcmp(p->num, astu->num) > 0)   //��һ���ڵ�ѧ�žͱ�Ҫ����Ĵ󣬲�����ǰ��
	{
		astu->next = p;
		pHead->next = astu;
		return;
	}
	while (p->next)
	{
		if (strcmp(p->num, astu->num) < 0 && strcmp(p->next->num, astu->num) > 0)   //��ǰ�ڵ�ѧ�ű������С����һ��������Ĵ�����Ĳ����м�
		{
			astu->next = p->next;
			p->next = astu;
			return;
		}
		p = p->next;
	}
	p->next = astu;
	astu->next = NULL;
}


void Delete_num(STU* pHead, char* num)
{
	STU* pre = pHead;
	STU* p = pHead->next;
	while (p)
	{
		if (strcmp(p->num, num) == 0)
		{
			pre->next = p->next;
			free(p);
			return;
		}
		p = p->next;
		pre = pre->next;
	}
}


STU* Search_major_subject_score(STU* pHead, char* major, int course, int score)
{
	STU* H = (STU*)malloc(sizeof(STU));   //����һ��С�����ͷָ��
	H->next = NULL;
	STU* rear = H;    //βָ��
	STU* p = pHead->next;
	while (p)
	{   //�ҵ�һ������Ҫ���ѧ�������뵽��HΪͷָ���������
		if (strcmp(p->major, major) == 0 && p->score[course] < score)
		{
			STU* temp = (STU*)malloc(sizeof(STU));
			*temp = *p;    //����һ�����ѧ���ڵ㣬���뵽С������
			temp->next = NULL;
			rear->next = temp;
			rear = temp;
		}
		p = p->next;
	}
	return H;
}


void Delete_class_subject_score(STU* pHead, int classNo, int course, int score)
{
	STU* pre = pHead;   //p��ǰһ���ڵ�
	STU* p = pHead->next;   //p������������
	STU* front = pHead->next->next;    //frontָ��p�ĺ�һ���ڵ�
	while (p)
	{
		if (p->classNo == classNo && p->score[course] < score)
		{
			pre->next = front;
			free(p);   //�ͷ��ڴ�
			p = front;
			if(front)   //p�ߵ����ʱ��front=NULL����ʱ�����ƶ�front
				front = front->next;
		}
		else
		{
			p = p->next;
			if(front)
				front = front->next;
			pre = pre->next;
		}
	}
}

STU * Max(STU * pHead, int course)
{
	STU* p = pHead->next;
	STU* max = p;
	p = p->next;
	while (p)
	{
		if (p->score[course] > max->score[course])
			max = p;
		p = p->next;
	}
	return max;
}