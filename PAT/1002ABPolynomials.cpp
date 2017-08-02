/******************************************************************************************************
This time, you are supposed to find A+B where A and B are two polynomials.
Input
Each input file contains one test case.
Each case occupies 2 lines, and each line contains the information of a polynomial:
K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial,
Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively.
It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.
Output
For each test case you should output the sum of A and B in one line, with the same format as the input.
Notice that there must be NO extra space at the end of each line.
Please be accurate to 1 decimal place.
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*******************************************************************************************************/
//包含头文件
#include <iostream>
#include <cstdio>//需要保留小数点后一位，可以用%.1f，暂时还不会c++的标准输出
#define MAXK 1001 //在数组中使用

using namespace std;

int main(void)
{
	float aK[MAXK] = { 0, };//系数数组，自带指数
	int iN = 0;//需要输入的数目
	int ix = 0;
	float ia = 0;//指数和系数

	//第一波攻击
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		cin >> ix >> ia;
		aK[ix] += ia;
	}//end of for (int i = 0; i < iN; ++i)

	//第二波攻击
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		cin >> ix >> ia;
		aK[ix] += ia;
	}//end of for (int i = 0; i < iN; ++i)

	//输入完毕，开始输出蛤
	//先计算它的有效数吧
	int iCount = 0;
	for (int i = 0; i < MAXK; ++i)
	{
		if (aK[i] != 0)
		{
			++iCount;
		}//end of if (aK[i] > 0)
	}//end of for (int i = MAXK - 1; i >= 0; --i)

	cout << iCount;//输出有效数
	
	//按照题意从高到低输出
	for (int i = MAXK - 1; i >= 0 && iCount > 0; --i)
	{
		if (aK[i] != 0)
		{
			printf(" %d %.1f", i, aK[i]);
			--iCount;
		}//end of if (aK[i] > 0)
	}//end of for (int i = MAXK - 1; i >= 0; --i)
	cout << endl;

	return 0;
}