/*
Given a sequence of K integers { N1, N2, ..., NK }.
A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. 
The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements.
For example, given sequence { -2, 11, -4, 13, -5, -2 }, 
its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
Input Specification:
Each input file contains one test case. Each case occupies two lines. 
The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.
Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence.
The numbers must be separated by one space, but there must be no extra space at the end of a line.
In case that the maximum subsequence is not unique, 
output the one with the smallest indices i and j (as shown by the sample case).
If all the K numbers are negative, then its maximum sum is defined to be 0, 
and you are supposed to output the first and the last numbers of the whole sequence.
Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
#include <iostream>

using namespace std;

//定义结构体
struct MaxSum
{
	int sum;//此处可得到的最大和
	int start;//对应的开头和结尾
	int end;
};

int main(void)
{
	int N = 0;//输入总数
	//分别存储结果，上一个，现在的暂时的
	MaxSum result, last, temp;

	//输入
	cin >> N;
	//输入动态规划的起始
	cin >> result.sum;
	result.end = result.start = result.sum;
	//将第一个设为last
	last = result;

	for (int i = 1; i < N; ++i)
	{
		cin >> temp.end;//输入这一个的end即结尾

		//如果上一个的sum大于0，那么现在的可以得到的最大的
		//一定是现在的结尾加上一个的和
		//等于0是比较纠结的，如果last的sum是0，那么temp的sum是不应该加上的
		if (last.sum > 0)
		{
			//end不变，start就是last的start
			temp.sum = temp.end + last.sum;
			temp.start = temp.start;
		}
		//下面就是当last的sum小于等于0的时候了
		else if (temp.end > 0)//若上一个的小于等于0，则这一个sum可以得到的必然是这个的end了
		{
			//将start和sum设为end的值
			temp.start = temp.sum = temp.end;
		}
		//若这一个的end和last的sum小于0，就应该把负的加上去，保证一直小下去，
		//为的是如果last是负的那么它前面一定都是负的，最后判断输出全负做准备
		else if (temp.end < 0)
		{
			temp.sum = temp.end + last.sum;
			temp.start = last.start;
		}
		//等于0，last的sum是小于等于0的，所以0是可以留下来当sum的，说明不是全负数。
		else if (temp.end == 0)
		{
			temp.sum = temp.start = temp.end;
		}
		//判断是否是最大
		if (temp.sum > result.sum)
		{
			result = temp;
		}
		//现在的temp作下一个的last
		last = temp;
	}

	//如果小于0，就说明全小于0
	if (result.sum < 0)
	{
		//此时的last里存储了开始的和结束的值
		cout << 0 << " " << last.start << " " << last.end << endl;
	}
	//大于等于0说明非全为负数，正常输出即可
	else if (result.sum >= 0)
	{
		cout << result.sum << " " << result.start << " " << result.end << endl;
	}

	return 0;
}