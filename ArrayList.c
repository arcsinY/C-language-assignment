#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char num[15];
	char name[15];
	char major[10];
	int classNo;
	int score[3];
}STU;

void Input(STU *p);  //����ѧ����Ϣ����
void Output(STU *p, char* num, int num_stu);    //�������ѧ����Ϣ
void Output_all(STU *p, int num_stu);  //�������ѧ����Ϣ
void Save_all(char* file_name, STU *p, int num_stu);    //��������ѧ����Ϣ
void Save(char* file_name, STU *p, char* num, int num_stu);   //����ָ��ѧ�ŵ�ѧ����Ϣ
void Fetch(char* file_name, STU *p, int n);   //��ȡ��n��ѧ����Ϣ
void Max(STU *p, int course, int num_stu);    //������ѧ��ĳ�ſγ̵���߷ֺͷ�����ߵ�ѧ��������
void Sort_select(STU *p, char* major_name, int num_stu);    // ��ĳ��רҵ��ѧ��������ƽ���ɼ��ɵ͵��߽��м�ѡ������
void Sort_buble(STU *p, int classNo, int num_stu);      //��ĳ���༶��ѧ��������ƽ���ɼ��ɸߵ��ͽ�����������
void Sort_insert(STU *p, int classNo, int course, int num_stu);   //��ĳ���༶��ѧ������ĳ�ſγ̳ɼ��ɵ͵��߽���ֱ�Ӳ�������
void Search(STU *p, int classNo, int score, int num_stu);      //ʵ�ְ༶�ͳɼ����ۺϲ��ң���1�࣬�ܷ�240������ͬѧ��
void Read_from_file(char *file_path, STU *p, int num_stu);    //���ı��ļ��ж�ȡ����ѧ����Ϣ

int main()
{
	STU *arr;       //ѧ������
	int num_stu;     //ѧ������
	int choice;
	while(1)
	{
		printf("0.��ָ���ı��ļ��ж�ȡȫ��ѧ����Ϣ\n");
		printf("1.����ѧ����Ϣ                     2.���ָ��ѧ�ŵ�ѧ����Ϣ\n");
		printf("3.���ȫ��ѧ����Ϣ                 4.ȫ��ѧ����Ϣ�����ļ�\n");
		printf("5.��ָ��ѧ�ŵ�ѧ����Ϣ�����ļ�        6.���ļ��������ȡĳ��ѧ������Ϣ\n");
		printf("7.������ѧ��ĳ�ſγ̵���߷ֺͷ�����ߵ�ѧ��������\n");
		printf("8.��ĳ��רҵ��ѧ��������ƽ���ɼ��ɵ͵��߽��м�ѡ������\n");
		printf("9.��ĳ���༶��ѧ��������ƽ���ɼ��ɸߵ��ͽ�����������\n");
		printf("10.��ĳ���༶��ѧ������ĳ�ſγ̳ɼ��ɵ͵��߽���ֱ�Ӳ�������\n");
		printf("11.ʵ�ְ༶�ͳɼ����ۺϲ��ң���1�࣬�ܷ�240������ͬѧ��\n");
		printf("��ѡ����:");
		scanf("%d", &choice);
		switch(choice)
		{
		case 0:
		{
			char file_path[100];
			printf("�������ı�·��:");
			scanf("%s", file_path);
			while (1)
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
				if (flag == 0)
				{
					printf("����������:");
					scanf("%s", file_path);
				}
				else
					break;
			}
			printf("������ѧ������:");
			scanf("%d", &num_stu);
			arr = (STU*)malloc(sizeof(STU)*num_stu);
			Read_from_file(file_path, arr, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 1:
		{
			printf("������ѧ������:");
			scanf("%d", &num_stu);
			arr = (STU*)malloc(sizeof(STU)*num_stu);
			for(int i = 0;i<num_stu;++i)
			{
				Input(&arr[i]);
			}
			Output_all(arr, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 2:
		{
			char num[15];      
			printf("������Ҫ�ҵ�ѧ��ѧ��:");
			scanf("%s", num);
			Output(arr, num, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 3:
		{
			Output_all(arr, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 4:
		{
			char file_path[100];
			printf("������洢·��(Ҫ��\\����):");
			scanf("%s", file_path);	
			while (1)
			{
				int flag = 1;       //·����ȷ�ı�־����������0Ϊ����ȷ����������
				int tag = 0;
				for (int i = 0; i < strlen(file_path) - 1; ++i)     //�ж��Ƿ���\\����
				{
					if (file_path[i] == '\\')
						tag = 1 - tag;
					if (file_path[i] == '\\' && file_path[i + 1] != '\\' && tag)
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
				if (flag == 0)
				{
					printf("����������:");
					scanf("%s", file_path);
				}
				else
					break;
			}
			Save_all(file_path, arr, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 5:
		{	
			char file_path[100];
			char num[15];
			printf("������洢·��(Ҫ��\\����):");
			scanf("%s", file_path);
			while (1)
			{
				int flag = 1;       //·����ȷ�ı�־����������0Ϊ����ȷ����������
				int tag = 0;
				for (int i = 0; i < strlen(file_path) - 1; ++i)     //�ж��Ƿ���\\����
				{
					if (file_path[i] == '\\')
						tag = 1 - tag;
					if (file_path[i] == '\\' && file_path[i + 1] != '\\' && tag)
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
				if (flag == 0)
				{
					printf("����������:");
					scanf("%s", file_path);
				}
				else
					break;
			}
			printf("������Ҫ�洢��ѧ��ѧ��:");
			scanf("%s", num);
			Save(file_path, arr, num, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 6:
		{	
			char file_path[100];
			int n;
			printf("�������ȡ�ļ�·��(Ҫ��\\����):");
			scanf("%s", file_path);
			while (1)
			{
				int flag = 1;       //·����ȷ�ı�־����������0Ϊ����ȷ����������
				int tag = 0;
				for (int i = 0; i < strlen(file_path) - 1; ++i)     //�ж��Ƿ���\\����
				{
					if (file_path[i] == '\\')
						tag = 1 - tag;
					if (file_path[i] == '\\' && file_path[i + 1] != '\\' && tag)
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
				if (flag == 0)
				{
					printf("����������:");
					scanf("%s", file_path);
				}
				else
					break;
			}
			printf("������Ҫ��ȡ��ѧ��λ��:");
			scanf("%d", &n);
			if(n > num_stu)
				printf("���벻�Ϸ�!\n");
			else
				Fetch(file_path, arr, n);
			printf("\n\n\n\n");
			break;
		}
		case 7:
		{
			int n;   //�γ����(1-3)
			printf("������γ̺�(1-3):");
			scanf("%d", &n);
			while (n < 1 || n>3)
			{
				printf("\n���벻�Ϸ�������������:");
				scanf("%d", &n);
			}
			Max(arr, n, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 8:
		{
			char major[10];
			printf("������רҵ����:");
			scanf("%s", major);
			Sort_select(arr, major, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 9:
		{
			int classNo;
			printf("������༶��(1��2):");
			scanf("%d", &classNo);
			while (classNo < 1 || classNo > 2)
			{
				printf("\n���벻�Ϸ�������������:");
				scanf("%d", &classNo);
			}
			Sort_buble(arr, classNo, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 10:
		{
			int classNo;
			int course;
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
			Sort_insert(arr, classNo, course-1, num_stu);
			printf("������ѧ����ϢΪ:\n");
			Output_all(arr, num_stu);
			printf("\n\n\n\n");
			break;
		}
		case 11:
		{
			int classNo;
			int score;
			printf("������༶��(1-2):");
			scanf("%d", &classNo);
			while (classNo < 1 || classNo > 2)
			{
				printf("\n���벻�Ϸ�������������:");
				scanf("%d", &classNo);
			}
			printf("������ɼ�:");
			scanf("%d", &score);
			Search(arr, classNo, score, num_stu);
			printf("\n\n\n\n");
			break;
		}
		default:
			printf("����ѡ������!\n");
			printf("\n\n\n\n");
			break;
		}
	}
	free(arr);
	return 0;
}

void Input(STU *p)
{
	printf("������ѧ��ѧ��:");
	scanf("%s", p->num);
	printf("������ѧ������:");
	scanf("%s", p->name);
	printf("������ѧ��רҵ:");
	scanf("%s", p->major);
	printf("������ѧ���༶(1��2):");
	scanf("%d", &p->classNo);
	printf("������ѧ�����ſγɼ�:");
	scanf("%d %d %d", &p->score[0], &p->score[1], &p->score[2]);
}


void Output(STU *p, char* num, int num_stu)
{
	for(int i = 0;i<num_stu;++i)
	{
		if(strcmp(p[i].num, num) == 0)
		{
			printf("ѧ��     ����       רҵ       �༶    �ɼ�1    �ɼ�2    �ɼ�3\n");
			printf("%s    %s      %s      %d       %d       %d      %d\n", p[i].num, p[i].name, p[i].major, p[i].classNo, p[i].score[0], p[i].score[1], p[i].score[2]);
			return;
		}
	}
	printf("û��ѧ��Ϊ%s��ѧ��", num);
}


void Output_all(STU *p, int num_stu)
{
		printf("ѧ��     ����       רҵ       �༶    �ɼ�1    �ɼ�2    �ɼ�3\n");
		for(int i = 0;i<num_stu;++i)
			printf("%s    %s      %s      %d       %d       %d      %d\n", p[i].num, p[i].name, p[i].major, p[i].classNo, p[i].score[0], p[i].score[1], p[i].score[2]);
}


void Save_all(char* file_name, STU *p, int num_stu)
{
		FILE* fp = fopen(file_name, "wb");
		if(fp == NULL)
		{
			printf("���ļ�����\n");
			return;
		}
		for(int i = 0;i<num_stu;++i)
			fwrite(&p[i], sizeof(STU), 1, fp);
		fclose(fp);
}


void Save(char* file_name, STU *p, char* num, int num_stu)
{
	FILE* fp = fopen(file_name, "wb");
	if(fp == NULL)
	{
		printf("���ļ�����\n");
		return;
	}
	for(int i = 0;i<num_stu;++i)
	{
		if(strcmp(p[i].num, num) == 0)
		{
			fwrite(&p[i], sizeof(STU), 1, fp);
			fclose(fp);
			return;
		}
	}
	printf("û��ѧ��Ϊ%s��ѧ��\n", num);
}


void Fetch(char* file_name, STU *p, int n)
{
	STU s;
	FILE* fp = fopen(file_name, "rb");
	if(fp == NULL)
	{
		printf("���ļ�����\n");
		return;
	}
	fseek(fp, (n-1) * sizeof(STU), 0);
	fread(&s, sizeof(STU), 1, fp);
	printf("ѧ��     ����    רҵ    �༶   �ɼ�1    �ɼ�2    �ɼ�3\n");
	printf("%s       %s     %s      %d     %d      %d       %d", s.num, s.name, s.major, s.classNo, s.score[0], s.score[1], s.score[2]);
	fclose(fp);
}


void Max(STU *p, int course, int num_stu)
{
	int max = 0;
	char name[15];
	for(int i = 0;i<num_stu;++i)
	{
		if(p[i].score[course-1]>max)
		{
			max = p[i].score[course - 1];
			strcpy(name, p[i].name);
		}
	}
	printf("��%d�ſγ���߳ɼ�ѧ��Ϊ:%s, �ɼ�Ϊ:%d", course, name, max);
}


void Sort_select(STU *p, char* major_name, int num_stu)
{
	double t, *aver;
	STU a;
	int count = 0;   //��ָ��רҵ��ѧ������
	STU* major_stu = (STU*)malloc(sizeof(STU)*num_stu);     //ָ��רҵ��ѧ����������һ��
	for(int i = 0;i<num_stu;++i)
	{ 
		if (strcmp(p[i].major, major_name) == 0)
		{
			major_stu[count++] = p[i];
		}
	}
	if (count == 0)
	{
		printf("\nû�����רҵ\n");
		return;
	}
	aver = (double*)malloc(sizeof(double)*count);
	for (int i = 0; i<count; i++)   //����ƽ����
	{
		aver[i] = (major_stu[i].score[0] + major_stu[i].score[1] + major_stu[i].score[2]) / 3.0;
	}
	for (int i = 0; i<count - 1; i++)
	{
		int k = i;       //ȷ��Ҫ�Ƚϵ�������ѡ���һ�������бȽϡ�
		for (int j = i; j < count; j++)
		{
			if (aver[k] > aver[j])
				k = j;  //�ҵ�Ϊ�������������С���λ��
		}
		t = aver[i]; aver[i] = aver[k]; aver[k] = t;      //aver[i]��aver[k]����
		a = p[i]; p[i] = p[k]; p[k] = a;          //������Ӧ�ṹ��
	} 
	printf("ѧ��     ����       רҵ     �༶   �ɼ�1   �ɼ�2   �ɼ�3   ƽ���ɼ�\n");
	for (int i = 0; i < count; i++)
		printf("%s     %s     %s    %d     %d      %d       %d      %.2lf\n", major_stu[i].num, major_stu[i].name, major_stu[i].major, major_stu[i].classNo, major_stu[i].score[0], major_stu[i].score[1], major_stu[i].score[2], aver[i]);
	free(aver);
	free(major_stu);
}


void Sort_buble(STU *p, int classNo, int num_stu)
{
	STU *stu_class_ave = (STU*)malloc(sizeof(STU) * num_stu);//��ƽ���ɼ�������ĳ���༶��ѧ����Ϣ
	STU temp;
	double t;
	double *aver;   //����ƽ���ֵ�����
	int count = 0;//ָ���༶��ѧ������
	for (int i = 0; i < num_stu; i++)    //�ҵ�ָ���༶������
	{
		if (p[i].classNo == classNo)
			stu_class_ave[count++] = p[i];
	}
	if (count == 0)
	{
		printf("\n����༶û��ѧ��\n");
		return;
	}
	aver = (double*)malloc(sizeof(double)*count);
	for (int i = 0; i<count; i++)//����ʵ��Ԫ�ص�ƽ����
		aver[i] = (stu_class_ave[i].score[0] + stu_class_ave[i].score[1] + stu_class_ave[i].score[2]) / 3.0;
	int flag = 1;
	for (int i = 0; i<count - 1 && flag == 1; i++) {
		flag = 0;    //��־������һ�αȽ����Ƿ�����˽���
		for (int j = 0; j<count - 1 - i; j++) {
			if (aver[j]<aver[j + 1])     //С�Ľ���������
			{
				temp = stu_class_ave[j];
				stu_class_ave[j] = stu_class_ave[j+1];
				stu_class_ave[j+1] = temp;
				t = aver[j];
				aver[j] = aver[j+1];
				aver[j+1] = t;
				flag = 1;
			}
		}
	}
	printf("ѧ��     ����       רҵ       �༶   �ɼ�1   �ɼ�2   �ɼ�3   ƽ���ɼ�\n");
	for (int i = 0; i < count; ++i)
	{
		printf("%s     %s     %s      %d     %d      %d       %d     %.2lf\n", stu_class_ave[i].num, stu_class_ave[i].name, stu_class_ave[i].major, stu_class_ave[i].classNo, stu_class_ave[i].score[0], stu_class_ave[i].score[1], stu_class_ave[i].score[2], aver[i]);
	}
	free(aver);
	free(stu_class_ave);
}


void Sort_insert(STU *p, int classNo, int course, int num_stu)
{
	int count = 0;  //ʵ��Ԫ�ظ���
	STU temp;
	STU *stu_class_subject = (STU*)malloc(sizeof(STU) * num_stu);   //��ĳ�ſγ̳ɼ�������ĳ���༶��ѧ����Ϣ
	for (int i = 0; i<num_stu; i++) 
		if (p[i].classNo == classNo)          //����
			stu_class_subject[count++] = p[i];
	if (count == 0)
	{
		printf("\n����༶û��ѧ��\n");
		return;
	}
	for (int i = 1; i<count; ++i)     //��������
	{
		temp = stu_class_subject[i];     //��ʱ�洢Ҫ�����Ԫ��
		int j = i - 1;       //j��������õ�Ԫ�������һ��Ԫ�ص��±�
		while (j >= 0 && temp.score[course] < stu_class_subject[j].score[course])
		{
			stu_class_subject[j + 1] = stu_class_subject[j];
			--j;
		}
		if(j >= 0 || stu_class_subject[0].score[course] > temp.score[course])
			stu_class_subject[j + 1] = temp;    //����
	}
	Output_all(stu_class_subject, count);
	free(stu_class_subject);
}


void Search(STU *p, int classNo, int score, int num_stu)
{
	int count = 0;  //ʵ��Ԫ�ظ���
	STU *search = (STU*)malloc(sizeof(STU) * num_stu);
	for (int i = 0; i < num_stu; ++i)
	{
		if (p[i].classNo == classNo)
			search[count++] = p[i];
	}
	if (count == 0)
	{
		printf("\n����༶û��ѧ��\n");
	}
	int *sum = (int*)malloc(sizeof(int) * count);
	printf("ѧ��    ����       רҵ    �༶  �ɼ�1   �ɼ�2   �ɼ�3    �ܷ�\n");
	for (int i = 0; i < count; ++i)     //�����ܷ�
	{
		sum[i] = search[i].score[0] + search[i].score[1] + search[i].score[2];
		if (sum[i] > score)
			printf("%s   %s     %s     %d      %d      %d      %d     %d\n", search[i].num, search[i].name, search[i].major, search[i].classNo, search[i].score[0], search[i].score[1], search[i].score[2], sum[i]);
	}
}


void Read_from_file(char* file_path, STU *p, int num_stu)
{
	FILE* fp = fopen(file_path, "r");
	if (fp == NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}
	for (int i = 0; i < num_stu; ++i)
	{
		fscanf(fp, "%s %s %s %d %d %d %d", p[i].num, p[i].name, p[i].major, &p[i].classNo, &p[i].score[0], &p[i].score[1], &p[i].score[2]);
	}
	fclose(fp);
}
