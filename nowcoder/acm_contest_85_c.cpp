#include<iostream>
using namespace std;
using LL = long long;
LL a, b, c, d, e, p;
// 我擦，这什么意思啊
int main()
{
    cin >> a >> b >> c >> d >> e;
    for (a = ((a%e)*(b%e)) % e, c *= d, p = 1; c; a = a * a%e, c >>= 1)
    {
        // 如果c是奇数
        if (c & 1)p = p * a%e;
    }
    cout << p % e;

    return 0;
}