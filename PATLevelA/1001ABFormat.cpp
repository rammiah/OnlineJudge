#include<iostream>
#include<cstdio>//使用C的标准输出，以免中间不够3位

using namespace std;

void Output(int target);

int Print(char ch){
	int r = 0;
	r = ch - '0';
	return r;
}

int main(void)
{
	//定义题里的数据
	int a = 0;
	int b = 0;
	cin >> a >> b;

	//交给Output处理
	Output(a + b);

	return 0;
}

void Output(int target)
{
	int count = 1;//定义位数
	int test = target;//使用局部变量，避免对原数据改动

					  //判断正负，为下一步准备
	if (test < 0)
	{
		cout << '-';
		test = 0 - test;
		target = test;//适当改动
	}

	//计算位数
	while (test > 9)
	{
		++count;
		test /= 10;
	}
	test = target;//恢复test的值

	if (count <= 3)
	{
		printf("%d\n", test);//直接输出，这里认为0是一位数，count = 1
	}
	else if (count <= 6)
	{
		printf("%d,%03d\n", test / 1000, test % 1000);//标准输出即可
	}
	else
	{
		printf("%d,", test / 1000000);//输出百万前的
		test -= test / 1000000 * 1000000;//将百万以上的去掉
		printf("%03d,%03d\n", test / 1000, test % 1000);//输出后面的
	}

	return;//主动退出，算是一个习惯吧
}

/************************
Calculate a + b and output the sum in standard format.
that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
Input
Each input file contains one test case. 
Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. 
The numbers are separated by a space.
Output
For each test case, you should output the sum of a and b in one line. 
The sum must be written in the standard format.
Sample Input
-1000000 9
Sample Output
-999,991
*************************/
