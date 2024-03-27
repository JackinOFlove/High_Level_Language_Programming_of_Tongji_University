/* 2253744 林觉凯 软工 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
/* ----具体要求----
   1、允许添加需要的头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   ---------------------------------------------------------------------
*/

/***************************************************************************
  函数名称：
  功    能：求平方根的函数，返回为a的平方根
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
double my_sqrt(double a)
{
	double n1;
	double n2=1;
	n1 = a / 2.0;
	do {
		n1 = n2;
		n2 = (n1 + a / n2) / 2.0;
	} while (abs(n1 - n2) >= 0.00001);
	return n2;
}

/***************************************************************************
  函数名称：
  功    能：重复输入，直到取得double型非负数后返回
  输入参数：
  返 回 值：
  说    明：不准修改函数名、返回类型、形参
 ***************************************************************************/
double input()
{
	double a=0;
	char good;
	while (1)
	{
		printf("请输入a的值\n");
		scanf("%lf", &a);
		while ((good = getchar()) != EOF && good != '\n');
		if(a>0)
		{
			break;
		}
	}
	return a;

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：只允许修改...部分
 ***************************************************************************/
int main()
{
	/* 键盘输入要求平方根的数 */
	double a = input();
	/* 调用求平方根的函数 */
	double d = my_sqrt(a);

	/* 此处输出平方根（语句不全，将后面补齐）*/
	printf("%lf的平方根=%lf",a,d);

	return 0;
}

