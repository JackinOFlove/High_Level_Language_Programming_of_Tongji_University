/*2253744 林觉凯 软工*/
#include <iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int max(int a, int b, int c)
{
	if (b > a)
		a = b;
	if (c > a)
		a = c;
	return a;
}
int max(int a, int b, int c, int d)
{
	if (b > a)
		a = b;
	if (c > a)
		a = c;
	if (d > a)
		a = d;
	return a;
}
int main()
{
	int num, a, b, c, d;
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (num < 2 || num > 4)
		{
			cout << "个数输入错误" << endl;
			break;
		}
		if (num == 2)
		{
			cin >> a >> b;
			if (cin.good() == 0 || a <= 0 || b <= 0)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(1024, '\n');
			break;
		}
		else if (num == 3)
		{
			cin >> a >> b >> c;
			if (cin.good() == 0 || a <= 0 || b <= 0 || c <= 0)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(1024, '\n');
			break;
		}
		else if (num == 4)
		{
			cin >> a >> b >> c >> d;
			if (cin.good() == 0 || a <= 0 || b <= 0 || c <= 0 || d <= 0) 
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(1024, '\n');
			break;
		}
	}
	switch (num)
	{
	case 2:
		cout << "max=" << max(a, b) << endl;
		break;
	case 3:
		cout << "max=" << max(a, b, c) << endl;
		break;
	case 4:
		cout << "max=" << max(a, b, c, d) << endl;
		break;
	default:
		break;
	}
	return 0;
}