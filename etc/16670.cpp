#include <stdio.h>

int main() {
    int N;
    double result = 14;
    scanf("%d", &N);
    if (N > 3) {
        result += (N - 3) * 2.3;
    }
    if (result - (int)result >= 0.5) {
        printf("%d\n", (int)result + 1);
    } else {
        printf("%d\n", (int)result);
    }

    return 0;
}