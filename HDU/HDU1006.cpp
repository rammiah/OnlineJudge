#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


#define pb push_back
#define mp make_pair
#define fillchar(a, x) memset(a, x, sizeof(a))
#define copy(a, b) memcpy(a, b, sizeof(a))
#define lson rt << 1, l, mid
#define rson rt << 1|1, mid + 1, r


typedef long long LL;
typedef pair<int, int > PII;
typedef unsigned long long uLL;
template<typename T>
void print(T* p, T* q, string Gap = " ") {
    int d = p < q ? 1 : -1;
    while (p != q) {
        cout << *p;
        p += d;
        if (p != q) cout << Gap;
    }
    cout << endl;
}
template<typename T>
void print(const T &a, string bes = "") {
    int len = bes.length();
    if (len >= 2)cout << bes[0] << a << bes[1] << endl;
    else cout << a << endl;
}

const int INF = 0x3f3f3f3f;
const int MAXM = 2e5;
const int MAXN = 1e3 + 5;
double D;

struct Interval {
    double l, r;
};

Interval calc(double a, double b) {//计算秒满足条件的区间
    Interval c;
    if (a > 0) {
        c.l = (D - b) / a;
        c.r = (360 - D - b) / a;
    }
    else {
        c.l = (360 - D - b) / a;
        c.r = (D - b) / a;
    }
    //秒的大小在[0,60]之间
    if (c.l > c.r) c.l = c.r = -1;
    if (c.l < 0) c.l = 0;
    if (c.r > 60) c.r = 60;
    return c;
}

Interval unite(Interval a, Interval b) {//获取交集
    Interval c;
    c.l = max(a.l, b.l);
    c.r = min(a.r, b.r);
    if (c.l > c.r) c.l = c.r = -1;
    return c;
}

double getHappyTime(double h, double m) {
    double a1 = 0.1 - 6, b1 = 6. * m;//分针与秒针
    double a2 = 1. / 120. - 6., b2 = 30. * h + m / 2.;//秒针与时针
    double a3 = 1. / 120. - 0.1, b3 = 30. * h + m / 2. - 6. * m;//分针与时针
    Interval result[3][2], p;
    result[0][0] = calc(a1, b1), result[0][1] = calc(-a1, -b1);//有正负两个可能
    result[1][0] = calc(a2, b2), result[1][1] = calc(-a2, -b2);
    result[2][0] = calc(a3, b3), result[2][1] = calc(-a3, -b3);
    double res = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                p = unite(result[0][i], unite(result[1][j], result[2][k]));
                res += p.r - p.l;
            }
        }
    }
    return res;
}

int main() {
    while (~scanf("%lf", &D), D != -1) {
        double res = 0;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                res += getHappyTime(h, m);
            }
        }
        printf("%.3lf\n", res * 100. / (60. * 60. * 12.));
    }
    return 0;
}