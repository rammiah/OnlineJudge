#include <iostream>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b != 0) {
        int t = b % a;
        a = b;
        b = t;
    }

    return a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {



    return 0;
}

