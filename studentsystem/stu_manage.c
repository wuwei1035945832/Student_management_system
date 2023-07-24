#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct stu
{
	int num;
	float score[3];
	float ave;
}STU;

STU st[N];
static int n;

void help();
void type();
void list();
void average();
void sort();
void search();
void add();
void del();
void modify();

int main(int argc, const char *argv[])
{
	char order;
	
	help();
	while(1)
	{
		printf("请输入命令=");
		scanf("%c", &order);
		switch(order)
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
				if(n == 0)
					puts("成绩表为空！请先使用命令T录入学生成绩。");
				else
					average();
				break;
			case 'L':
				if(n == 0)
					puts("成绩表为空！请先使用命令T录入学生成绩。");
				else
					list();
				break;
			case 'P':
				if(n == 0)
					puts("成绩表为空！请先使用命令T录入学生成绩。");
				else
					sort();
				break;
			case 'S':
				if(n == 0)
					puts("成绩表为空！请先使用命令T录入学生成绩。");
				else
					search();
				break;
			case 'C':
				system("clear");
				break;
			case 'D':
				if(n == 0)
					puts("成绩表为空！请先使用命令T录入学生成绩。");
				else
					del();
				break;
			case 'X':
				if(n == 0)
					puts("成绩表为空！请先使用命令T录入学生成绩。");
				else
					modify();
				break;				
			case 'Q':
				exit(1);
			
		}
		getchar();//用scanf输入字符时，会同时把回车接受到，放在
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
	printf("*        Q = 退出系统                *\n");
	printf("*        D = 删除学生                *\n");
	printf("*        X = 修改成绩                *\n");
	printf("**************************************\n");
	printf("*   Copyright <C> 2023.7.15 By lyj  *\n");
	printf("**************************************\n");
}
void del() //删除学生信息
{
	int i, j, a;
	int flag=0;
	printf("请输入要删除的学生学号：");
	scanf("%d", &a);
	for(i = 0; i < n; i++)
	{
		if(st[i].num == a)
		{
			flag = 1;
			for (j = i; j < n - 1; j++)
			{
				st[j] = st[j + 1];//直接把后面的学生都往前移动一位 
			}
		}
		if (flag == 1) break;//说明已经找到了需要删除的学生，结束循环 
	}
	if (0 == flag)
	{
		printf("该学号不存在！！！\n");
	}

	if (1 == flag)
	{
		printf("删除成功\n");
		n--;
	}
}

void modify()
{
    int i, flag = 0;
    char a[20]; // 学号应该是字符串类型
    float score1;
    printf("请输入要修改的学生学号：");
    scanf("%s", a); // 使用%s读取学号

    while (1)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (st[i].num == atoi(a)) // 将学号字符串转换为整数进行比较
            {
                flag = 1;
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
                    scanf("%f", &score1);
                    st[i].score[0] = score1;
                    break;
                case 2:
                    printf("请输入新的高数成绩:\n");
                    scanf("%f", &score1);
                    st[i].score[1] = score1;
                    break;
                case 3:
                    printf("请输入新的英语成绩:\n");
                    scanf("%f", &score1);
                    st[i].score[2] = score1;
                    break;
                case 4:
                    return; // 结束函数
                default:
                    printf("请在1--4之间选择！\n");
                }
                if (num > 0 && num < 4)
                    printf("修改成功\n");

                return; // 找到学生并修改成功后，结束函数
            }
        }
        if (flag == 0)
        {
            printf("没有找到该学生，请重新输入需要修改信息的学生学号：\n");
            // 使用 getchar 来清除输入缓冲区中的换行符
            while (getchar() != '\n')
                continue;
            scanf("%s", a); // 使用%s读取学号
        }
    }
}


//*****成绩录入*******
void type()
{
	int i;
	printf("请输入学生人数：");
	scanf("%d", &n);
	printf("请输入%d名学生的三门课成绩：\n", n);
	printf("学号	语文	数学	外语\n");

	for(i = 1; i <= n; i++)
	{
		scanf("%d	%f	%f	%f", &st[i-1].num, &st[i-1].score[0], &st[i-1].score[1], &st[i-1].score[2]);
	}
}
//*****列出成绩******
void list()
{
	int i;
	printf("学生成绩如下：\n");
	printf("学号	语文	数学	外语	平均分\n");
	for(i = 1; i <= n; i++)
	{
		printf("%d	%.1f %.1f	%.1f	%.1f\n", st[i-1].num, st[i-1].score[0], st[i-1].score[1], st[i-1].score[2], st[i-1].ave);
	}
}
//*****求出平均值******
void average()
{
	int sum = 0, i;
	for(i = 0; i < n; i++)
	{
		sum = st[i].score[0] + st[i].score[1] + st[i].score[2];
		st[i].ave = sum / 3;
	}
	printf("平均分已计算。请使用命令L查看。\n");
}
//*****按平均分从高到低排序*****
void sort()
{
	int i, j;
	STU tmp;
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			if(st[j].ave < st[j+1].ave)
			{
				tmp = st[j];
				st[j] = st[j+1];
				st[j+1] = tmp;
			}
		}
	}
	printf("完成排序。请使用命令L查看\n");
}
//*****按学号查询******
void search()
{
	int i, j;
	printf("请输入要查找的学生学号：");
	scanf("%d", &i);
	for(j = 0; j < n; j++)
	{
		if(st[j].num == i)
		{
			printf("学号	语文	数学	外语	平均分\n");
			printf("%d	%.1f	%.1f	%.1f	%.1f\n", i, st[j].score[0], st[j].score[1], st[j].score[2], st[j].ave);
		}
	}
}
//*****新增学生的成绩录入******
void add()
{
	int addnum, i;
	printf("请输入学生人数：");
	scanf("%d", &addnum);
	printf("请输入%d名学生的三门课成绩：\n", addnum);
	printf("学号	语文	数学	外语\n");
	n = n + addnum;
	for(i = n - addnum; i < n; i++)
	{
		scanf("%d	%f	%f	%f", &st[i].num, &st[i].score[0], &st[i].score[1], &st[i].score[2]);
	}
 

}
