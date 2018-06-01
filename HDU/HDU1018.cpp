#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

using namespace std;

int get_cnt(int num) {
    double sum = 1;
    for (int i = 2; i <= num; ++i) {
        sum += log10(i);
    }

    return (int)sum;
}

int main() {

    int cnt, num;
    scanf("%d", &cnt);
    while (cnt--) {
        scanf("%d", &num);
        printf("%d\n", get_cnt(num));
    }

    return 0;
}