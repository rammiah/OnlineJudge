/*
At the beginning of every day, the first person who 
signs in the computer room will unlock the door,
and the last one who signs out will lock the door. 
Given the records of signing in's and out's, you are 
supposed to find the ones who have unlocked and locked the door on that day.
Input Specification:
Each input file contains one test case. Each case contains the records for one day. 
The case starts with a positive integer M, which is the total number of records, 
followed by M lines, each in the format:
ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, 
and ID number is a string with no more than 15 characters.
Output Specification:
For each test case, output in one line the ID numbers of the 
persons who have unlocked and locked the door on that day. 
The two ID numbers must be separated by one space.
Note: It is guaranteed that the records are consistent. 
That is, the sign in time must be earlier than the sign out time for each person, 
and there are no two persons sign in or out at the same moment.
Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
*/
#include <iostream>
#include <string>

using namespace std;

class Student
{
	string number;//学号
	int bgn;//开始结束的时间，以秒为单位
	int end;

public:
	//对开始学生的判断
	bool operator < (const Student &a)
	{
		return bgn < a.bgn;
	}
	//对最后离开的学生的判断
	bool operator > (const Student &a)
	{
		return end > a.end;
	}
	//输入重载
	friend istream& operator >> (istream &in, Student &a)
	{
		//冒号用ch接收
		char ch;
		int hour, min, sec;
		in >> a.number;//学号
		in >> hour >> ch >> min >> ch >> sec;//输入时间挺烦人的
		a.bgn = hour * 3600 + min * 60 + sec;//开始
		in >> hour >> ch >> min >> ch >> sec;
		a.end = hour * 3600 + min * 60 + sec;//结束
		return in;//返回in
	}
	//输出重载
	friend ostream& operator << (ostream &out, const Student &a)
	{
		//根据要求只需要学号，输出学号即可，对于重载的输出要求
		//一般是越精简越好，因为你不知道如果你多输出一个空格会造成什么
		out << a.number;
		return out;//返回out保证连续输出
	}
};

int main(void)
{
	//first，last存储最早的和最晚的，unknown存储未知的
	Student firstStu, lastStu, unknown;
	//N输入个数
	int N = 0;
	cin >> N;
	//先把第一个学生输入，然后将其设置为最早的和最晚的
	cin >> unknown;
	firstStu = lastStu = unknown;
	for (int i = 1; i < N; ++i)
	{
		//依次读入，判断是否最早或最晚
		cin >> unknown;
		if (unknown < firstStu)
		{
			firstStu = unknown;
		}
		//对于后面的else，我开始想的是只有unknown晚于first才有可能是last，但是后来提交时2，3过不去，
		//去掉else过了，现在想到了开始和结束是没有关系的，所以不能用else
		if (unknown > lastStu)
		{
			lastStu = unknown;
		}
	}
	//输出结果
	cout << firstStu << " " << lastStu << endl;

	return 0;
}