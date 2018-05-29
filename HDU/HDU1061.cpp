#include <iostream>

long long fast_pow(long long num, long long exp, int mod) {
    long long result = 1;
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
    int cnt;
    std::cin >> cnt;
    long long num;
    int result;
    while (cnt--) {
        std::cin >> num;
        std::cout << fast_pow(num, num, 10) << "\n";
    }


    return 0;
}