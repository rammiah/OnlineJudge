/*
The highest building in our city has only one elevator.
A request list is made up with N positive numbers.
The numbers denote at which floors the elevator will stop, in specified order.
It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor.
The elevator will stay for 5 seconds at each stop.
For a given request list, you are to compute the total time spent to fulfill the requests on the list.
The elevator is on the 0th floor at the beginning and does not have
to return to the ground floor when the requests are fulfilled.
Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers.
All the numbers in the input are less than 100.
Output Specification:
For each test case, print the total time on a single line.
Sample Input:
3 2 3 1
Sample Output:
41
*///18 + 8 + 15
#include <iostream>
#define UP 6 //为了代码思路清晰，用宏分别定义上一楼，下一楼，停一楼的时间
#define DOWN 4
#define STAY 5

using namespace std;

int main(void)
{
	int N = 0;//记录进行需要的次数
	int sum = 0;//总时间
	int start = 0;//开始楼层即0层
	int next = 0;//下一个去哪？

	cin >> N;//输入总次数

	for (int i = 0; i < N; ++i)
	{
		cin >> next;//输入下一个楼层

		if (next > start)//如果要上楼
		{
			sum += (next - start) * UP;
		}
		else//下楼
		{
			sum += (start - next) * DOWN;
		}

		start = next;//将next设为下一个的start
	}
	sum += N * STAY;//加上总停留时间

	//输出
	cout << sum << endl;

	return 0;
}
