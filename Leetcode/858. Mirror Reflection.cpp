using ll = long long;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

class Solution {
public:
    int mirrorReflection(int p, int q) {
        ll a = 0, b = 0;
        // 最大公约数
        ll g = gcd(p, q);
        a = p / g;
        b = q / g;
        if (a % 2 == 1 && b % 2 == 0) {
            return 0;
        }
        else if (a % 2 == 1 && b % 2 == 1) {
            return 1;
        }
        else if (a % 2 == 0 && b % 2 == 1) {
            return 2;
        }
        return 0;
    }
};
