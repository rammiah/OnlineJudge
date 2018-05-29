#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>

int main() {
    unsigned long long num;

    while (scanf("%llu", &num) != EOF) {
        printf("%llu\n\n", num * (num + 1) / 2);
    }

    return 0;
}