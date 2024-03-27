/*2253744 林觉凯 软工*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（全局只读变量或宏定义不受此限制）
   3、不允许添加其它函数
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;		//某课程的成绩（百分制）
	float weight;	//某课程的学分（权重）
	int   gpa;		//某课程的绩点（同济规则，[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5）
};

struct student {
	int   no;               //学号（虽然用int不够合理，此处不考虑）
	char  name[9];          //假设姓名最长4个汉字
	struct course score[3]; //数组放三门课的成绩（未使用宏定义，函数实现时，直接写3即可）
	float avg_gpa;                     //可增加其它你认为需要增加的结构体成员（限一个），不要则删除本行
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：此处最多允许添加一个函数，且函数的形参、自动变量等都必须是简单变量（即不允许[]形式）
***************************************************************************/
int GPA(float value)
{
	if (value >= 90)
		return 5;
	if (value >= 80)
		return 4;
	if (value >= 70)
		return 3;
	if (value >= 60)
		return 2;
	return 0;
}
/***************************************************************************
  函数名称：
  功    能：输入10个学生的信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* 除这两个整型变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	int i, j;
	for (i = 0; i < num; i++)
	{
		stu[i].avg_gpa = 0;
		printf("请输入第%2d个学生的信息：", i + 1);
		scanf("%d %s", &stu[i].no, &stu[i].name);
		for (j = 0; j < 3; j++)
		{
			scanf("%f %f", &stu[i].score[j].value, &stu[i].score[j].weight);
			stu[i].score[j].gpa = GPA(stu[i].score[j].value);
			stu[i].avg_gpa += stu[i].score[j].gpa * stu[i].score[j].weight;
		}
		stu[i].avg_gpa /= (stu[i].score[0].weight + stu[i].score[1].weight + stu[i].score[2].weight);
	}
	/* 函数的实现部分 */
}

/***************************************************************************
  函数名称：
  功    能：输出基本信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* 除这两个指针变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	struct student* ps;

	/* 函数的实现部分，不允许任何形式的[]出现 */
	printf("\n10个学生的成绩\n");
	printf("序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点\n");
	printf("==================================================================\n");
	for (ps = stu; ps < stu + num; ps++)
		printf("%-4d %-7d %-8s %-5d %-5g %-5d %-5g %-5d %-5g %-5.3f\n", 
			ps - stu + 1,ps->no,ps->name,ps->score[0].gpa, ps->score[0].weight, ps->score[1].gpa, ps->score[1].weight, ps->score[2].gpa, ps->score[2].weight,ps->avg_gpa);
}

/***************************************************************************
  函数名称：
  功    能：输出绩点最高的学生（可能有并列）
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* 本函数中允许定义各种类型的简单变量，但不允许定义数组 */
	printf("\n绩点最高的学生为\n");
	printf("序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点\n");
	printf("==================================================================\n");
	float max = 0;
	for (int i = 0; i < num ; i++)
	{
		if (stu[i].avg_gpa > max)
			max = stu[i].avg_gpa;
	}
	for (int i = 0; i < num; i++)
	{
		if (stu[i].avg_gpa == max)
		{
			struct student* ps = &stu[i];
			printf("%-4d %-7d %-8s %-5d %-5g %-5d %-5g %-5d %-5g %-5.3f\n", 
				ps - stu + 1, ps->no, ps->name, ps->score[0].gpa, ps->score[0].weight, ps->score[1].gpa, ps->score[1].weight, ps->score[2].gpa, ps->score[2].weight, ps->avg_gpa);
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, 10);		//输入10个学生的信息
	output_base(stu, 10);	//输出10个学生的基本信息
	output_max(stu, 10);	//输出最高（可能有多个）

	return 0;
}

/*
测试数据，复制到cmd即可（名单随机抓取，成绩随机给出，无任何实际意义或暗示）

2152482 鄂俊伍 76.5 4 82 5 52 2.5
2250411 林俊吉 63 4.5 49 1 87 6
2250821 郭平伟 56 3 76 4 69 5
2251561 任昱扬 44.5 2 83.5 4 87 6
2252584 欧宇轩 91 4 43.5 1 66 3
2252753 阮飞翔 79 6 85.5 3 62 2
2253554 廖海峰 86 3 63 3 77.5 4
2253711 钟沛橙 49.5 3 86 6 93.5 3
2253968 贾文超 81.5 2 64.5 3 87 4
2254174 任奕 73 3 62 2.5 85 5

*/
