using ll = long long;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}
// https://blog.csdn.net/qq2667126427/article/details/80793913
// 配合blog更易懂
class Solution {
public:
    int mirrorReflection(int p, int q) {
        ll x = 0, y = 0;
        // 最小公倍数
        ll g = p * q / gcd(p, q);
        y = g / p;
        x = g / q;
        if (x % 2 == 1 && y % 2 == 0) {
            return 0;
        }
        else if (x % 2 == 1 && y % 2 == 1) {
            return 1;
        }
        else if (x % 2 == 0 && y % 2 == 1) {
            return 2;
        }
        return 0;
    }
};