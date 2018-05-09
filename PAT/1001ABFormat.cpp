#include<cstdio>
#include <stack>

using namespace std;

int main(void)
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	a += b;
	if (a < 0) {
		printf("-");
		a = -a;
	}
	stack<int> s;
	// 和是0的话就很难过了
	if (a == 0) {
		s.push(a);
	}
	while (a > 0) {
		s.push(a % 1000);
		a /= 1000;
	}
	// 只有一个数字的话就很难过了
	if (s.size() > 1) {
		printf("%d,", s.top());
		s.pop();
		while (s.size() > 1) {
			printf("%03d,", s.top());
			s.pop();
		}
		printf("%03d", s.top());
	} else {
		// 只有一个数字
		printf("%d\n", s.top());
	}
	
		
	return 0;
}
