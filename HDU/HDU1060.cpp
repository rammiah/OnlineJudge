#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
    int T;
    long long num;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &num);
        double log = num * log10(num) - (long long) (num * log10(num));
        printf("%lld\n", (long long)pow(10, log));
    }

    return 0;
}