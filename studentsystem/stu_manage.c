#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct stu
{
	int num;
	float score[3];
	float ave;
	struct stu *next;
} STU;

STU *H = NULL; // 全局链表头
static int n;

void help();
void type(STU *head);
void list(STU *head);
void average(STU *head);
void sort(STU *head);
void search();
void add();
void del();
void modify();

STU *LLCreate()
{
	STU *head = (STU *)malloc(sizeof(STU));
	if (head == NULL)
	{
		printf("LLCreate 失败，分配内存失败。\n");
		exit(1);
	}
	head->next = NULL;
	return head;
}

int main(int argc, const char *argv[])
{
	char order;
	H = LLCreate(); // 使用全局变量
	help();
	while (1)
	{
		printf("请输入命令=");
		scanf("%c", &order);
		switch (order)
		{
		case 'H':
			help();
			break;
		case 'T':
			//if(n == 0)
			//	type();
			//else
			add();
			break;
		case 'A':
			if (n == 0)
				puts("成绩表为空！请先使用命令T录入学生成绩。");
			else
				average(H); // 传入链表头指针作为参数
			break;

		case 'L':
			if (n == 0)
				puts("成绩表为空！请先使用命令T录入学生成绩。");
			else
				list(H);
			break;
		case 'P':
			if (n == 0)
				puts("成绩表为空！请先使用命令T录入学生成绩。");
			else
				sort(H);
			break;
		case 'S':
			if (n == 0)
				puts("成绩表为空！请先使用命令T录入学生成绩。");
			else
				search();
			break;
		case 'C':
			system("clear");
			break;
		case 'D':
			if (n == 0)
				puts("成绩表为空！请先使用命令T录入学生成绩。");
			else
				del(H);
			break;
		case 'X':
			if (n == 0)
				puts("成绩表为空！请先使用命令T录入学生成绩。");
			else
				modify();
			break;
		case 'E':
			if (n == 0)
				puts("成绩表为空！请先使用命令T录入学生成绩。");
			else
				add();
			break;
		case 'Q':
			exit(1);
		}
		getchar(); //用scanf输入字符时，会同时把回车接受到，放在
				   //缓存区中，执行下次while循环时，会打印两次输出语句，
				   //所以使用getcahr来接收垃圾字符
	}

	return 0;
}

//******帮助菜单*******
void help()
{
	printf("**************************************\n");
	printf("*     学生成绩管理系统--帮助菜单     *\n");
	printf("**************************************\n");
	printf("*        H = 显示帮助菜单            *\n");
	printf("*        T = 成绩录入                *\n");
	printf("*        A = 计算学生平均成绩        *\n");
	printf("*        L = 列出成绩表              *\n");
	printf("*        P = 按平均成绩由高到低排序  *\n");
	printf("*        S = 按学号查询学生成绩      *\n");
	printf("*        C = 清屏                    *\n");
	printf("*        D = 删除学生                *\n");
	printf("*        X = 修改成绩                *\n");
	printf("*        E = 继续添加学生             *\n");
	printf("*        Q = 退出系统                *\n");
	printf("**************************************\n");
	printf("*   Copyright <C> 2023.7.15 By lyj  *\n");
	printf("**************************************\n");
}

//*****成绩录入*******
void type(STU *head)
{
	int i;
	printf("请输入学生人数：");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		STU *newStudent = (STU *)malloc(sizeof(STU));
		if (newStudent == NULL)
		{
			printf("内存分配失败。\n");
			exit(1);
		}

		printf("请输入第%d名学生的学号和三门课成绩：\n", i + 1);
		scanf("%d %f %f %f", &newStudent->num, &newStudent->score[0], &newStudent->score[1], &newStudent->score[2]);

		newStudent->next = head->next;
		head->next = newStudent;
	}
}

void list(STU *head)
{
	STU *current = head->next; // 跳过头结点，从第一个学生节点开始遍历

	printf("学生成绩如下：\n");
	printf("学号    语文    数学    外语    平均分\n");

	while (current != NULL)
	{
		printf("%d     %.1f     %.1f     %.1f     %.1f\n", current->num, current->score[0], current->score[1], current->score[2], current->ave);
		current = current->next; // 移动到下一个学生节点
	}
}

//*****求出平均值******
void average(STU *head)
{
	STU *current = head->next;

	while (current != NULL)
	{
		int sum = current->score[0] + current->score[1] + current->score[2];
		current->ave = sum / 3.0;

		current = current->next;
	}

	printf("平均分已计算。请使用命令L查看。\n");
}

//*****按平均分从高到低排序*****
void sort(STU *head)
{
	int swapped;
	STU *ptr1;
	STU *lptr = NULL;

	// 检查是否为空链表
	if (head->next == NULL)
	{
		printf("成绩表为空！\n");
		return;
	}

	// 外层循环，控制排序迭代
	while (lptr != head->next)
	{
		swapped = 0;
		ptr1 = head->next;

		// 内层循环，遍历链表并比较相邻节点的平均分
		while (ptr1->next != lptr)
		{
			if (ptr1->ave < ptr1->next->ave)
			{
				// 交换节点的数据
				STU tmp = *ptr1;
				*ptr1 = *(ptr1->next);
				*(ptr1->next) = tmp;

				swapped = 1;
			}
			ptr1 = ptr1->next;
		}

		// 如果没有发生交换，表示已排序完成
		if (!swapped)
			break;

		lptr = ptr1; // 更新已排序部分的末尾节点
	}

	printf("完成排序。请使用命令L查看\n");
}

void del(STU *head)
{
	int targetNum;
	printf("请输入要删除的学生学号：");
	scanf("%d", &targetNum);

	STU *PDel = NULL;	  // 用于标记待删除的节点
	STU *previous = head; // 指向当前节点的前一个节点

	while (previous->next != NULL)
	{
		if (previous->next->num == targetNum)
		{
			PDel = previous->next;
			previous->next = PDel->next; // 删除节点
			free(PDel);					 // 释放节点内存
			PDel = NULL;
			printf("删除成功\n");
			return;
		}
		else
		{
			previous = previous->next;
		}
	}

	printf("未找到该学生学号\n");
}

//*****按学号查询******
void search()
{
	int targetNum;
	printf("请输入要查找的学生学号：");
	scanf("%d", &targetNum);

	// 遍历链表查找学号匹配的学生
	STU *current = H->next;
	int found = 0; // 标记是否找到匹配的学生

	while (current != NULL)
	{
		if (current->num == targetNum)
		{
			printf("学号\t语文\t数学\t外语\t平均分\n");
			printf("%d\t%.1f\t%.1f\t%.1f\t%.1f\n", current->num, current->score[0], current->score[1], current->score[2], current->ave);
			found = 1; // 找到匹配的学生
			break;	   // 不需要继续遍历
		}
		current = current->next;
	}

	if (!found)
	{
		printf("未找到该学生学号\n");
	}
}

//*****新增学生的成绩录入******
void add()
{
	int addnum, i;
	printf("请输入学生人数：");
	scanf("%d", &addnum);

	// 循环添加新的学生节点
	for (i = 0; i < addnum; i++)
	{
		STU *newStudent = (STU *)malloc(sizeof(STU));
		if (newStudent == NULL)
		{
			printf("内存分配失败。\n");
			exit(1);
		}

		printf("请输入第%d名学生的学号和三门课成绩：\n", i + 1);
		scanf("%d %f %f %f", &newStudent->num, &newStudent->score[0], &newStudent->score[1], &newStudent->score[2]);

		newStudent->next = H->next;
		H->next = newStudent;
		n++; // 更新学生数量
	}

	printf("新增学生信息完成。\n");
}
void modify()
{
	int targetNum;
	printf("请输入要修改的学生学号：");
	scanf("%d", &targetNum);

	STU *current = H->next;
	int found = 0; // 标记是否找到匹配的学生

	while (current != NULL)
	{
		if (current->num == targetNum)
		{
			found = 1; // 找到匹配的学生

			int num; // 用于switch函数的子菜单
			printf("***************************************************\n");
			printf("*----1.修改语文--------  -  -----2.修改数学-------*\n");
			printf("*----3.修改外语--------  -  -----4.退出本菜单--*\n");
			printf("***************************************************\n\n");
			printf("请输入子菜单：");
			scanf("%d", &num);

			switch (num)
			{
			case 1:
				printf("请输入新的语文成绩:\n");
				scanf("%f", &(current->score[0]));
				break;
			case 2:
				printf("请输入新的数学成绩:\n");
				scanf("%f", &(current->score[1]));
				break;
			case 3:
				printf("请输入新的外语成绩:\n");
				scanf("%f", &(current->score[2]));
				break;
			case 4:
				return; // 结束函数
			default:
				printf("请在1--4之间选择！\n");
			}

			printf("修改成功\n");
			return; // 找到学生并修改成功后，结束函数
		}
		current = current->next;
	}

	if (!found)
	{
		printf("没有找到该学生，请重新输入需要修改信息的学生学号：\n");
	}
}
