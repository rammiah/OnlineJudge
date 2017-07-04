/*
This time, you are supposed to find A*B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines,
and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK,
where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients,
respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.
Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input.
Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/
//为了输出方便，本次使用c
#include <cstdio>
#define MAX 2002 //定义会用到的最大的数组元素个数
int main(void)
{
	int N = 0, exp = 0, count = 0;//分别代表输入总数，幂次，最后输出总数目
	double cof = 0.0f;//使用double表示系数
	//三个数组，初始化为0，虽然浮点数不能精确表示数但是0还是能的
	double pA[MAX / 2] = { 0, };
    double pB[MAX / 2] = { 0, };
	double result[MAX] = { 0, };
	//输入总数
	scanf("%d", &N);
	//输入pA的数据
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %lf", &exp, &cof);
		pA[exp] = cof;
	}
    //输入pB
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %lf", &exp, &cof);
		pB[exp] = cof;
	}
	//开始计算乘积
	for (int i = 0; i < MAX / 2; ++i)
	{
	    //pA[i] != 0，能节省点时间就行
		for (int j = 0; j < MAX / 2 && pA[i] != 0; ++j)
		{
		    //参考多项式乘法法则
			result[i + j] += pA[i] * pB[j];
		}
	}
	//记录不为0的result个数
	for (int i = 0; i < MAX; ++i)
	{
	    //这个精确度够了，
		if (result[i] >= 0.1f || result[i] <= -0.1f)
		{
			++count;
		}
	}
	//输出count
	printf("%d", count);
	//输出多项式
	for (int i = MAX - 1; i >= 0; --i)
	{
		if (result[i] != 0.0f)
		{
		    //精确到小数点后1位
			printf(" %d %.1f", i, result[i]);
			--count;
		}
	}
	//换行，虽然没必要
	printf("\n");
	//结束
	return 0;
}
