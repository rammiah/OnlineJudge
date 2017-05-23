/*************************************************************************************************
Given a non-negative integer N, your task is to compute the sum of all the digits of N,
and output every digit of the sum in English.
Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).
Output Specification:
For each test case, output in one line the digits of the sum in English words.
There must be one space between two consecutive words, but no extra space at the end of a line.
Sample Input:
12345
Sample Output:
one five
****************************************************************************************************/
#include <iostream>
#include <string>

using namespace std;

//定义一个转化输出的函数
//参数是要输出的数和main()中定义的string数组
void print(int num, const string *Number)
{
	int temp = num;//将数据用变量存储
	int count = 0;//count用来记录位数
	int t = 1;//要用来作除数的变量

	//当temp大于9就继续运行，具体目的是t结束循环后不用除以10，count不用-1
	while (temp > 9)
	{
		temp /= 10;
		++count;
		t *= 10;
	}
	//恢复temp的值
	temp = num;
	//根据t的值先输出最高位
	cout << Number[temp / t];//根据下标
	temp -= temp / t * t;//temp去除输出了的位，不用担心temp变成0
	t /= 10;//t和count对应减小
	--count;

	while (count >= 0)
	{
	    //输出字符，自减，除10
		cout << " " << Number[temp / t];
		temp -= temp / t * t;
		t /= 10;
		--count;
	}
	//换行，为了美观
	cout << endl;
}

int main(void)
{
    //定义const string的Number数组存储要用的字符传
	const string Number[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string str;//用str存储要输入的字符串，只因为它的[]重载很好用
	int sum = 0;
	cin >> str;
	//求和
	for (int i = 0; i < (int)str.length(); ++i)
	{
		sum += str[i] - '0';
	}
	//输出
	print(sum, Number);
	//结束
	return 0;
}
