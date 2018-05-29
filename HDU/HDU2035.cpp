#include <iostream>

using ll = long long;

ll fast_pow(ll num, ll exp, ll mod) {
    ll result = 1;
    while (exp != 0) {
        if (exp&1) {
            result = result * num % mod;
        }
        num = num * num % mod;
        exp >>= 1;
    }

    return result;
}

int main() {
    ll a, b;
    std::cin >> a >> b;
    while (a != 0 || b != 0) {
        std::cout << fast_pow(a, b, 1000) << "\n";
        std::cin >> a >> b;
    }


    return 0;
}