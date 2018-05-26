#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using ull = unsigned long long;
ull MOD = (int)1E9 + 7;

ull fast_pow(ull a, ull b, ull mod) {
    ull result = 1;
    while (b > 0) {
        if (b & 1) {
            result = result * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }

    return result;
}

ull inv(ull a, ull mod) {
    return fast_pow(a, mod - 2, mod);
}

ull factorial(ull a, ull mod) {
    // 无符号数，不用考虑小于0
    if (a <= 1) {
        return 1;
    }
    ull result = 1;
    for (ull i = 2; i <= a; ++i) {
        result = result * i % mod;
    }

    return result;
}


int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int sum = a + b + c + d;
    ull ans = factorial(sum, MOD);
    ull down = 1;
    down = factorial(a, MOD) % MOD * factorial(b, MOD) % MOD * factorial(c, MOD) % MOD * factorial(d, MOD) % MOD;
    //std::cout << ans << " " << down << "\n";
    ull in = inv(down, MOD);
    ans = ans * in % MOD;

    std::cout << ans << "\n";

    return 0;
}

