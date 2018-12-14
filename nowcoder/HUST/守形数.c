#include <stdio.h>
#include <stdlib.h>

int is_good(int n) {
    int square = n * n;
    int t = 1;
    while (t < square) {
        if (square % t == n) {
            return 1;
        }
        t *= 10;
    }
    return 0;
}

int main() {
    int num;

    while (~scanf("%d", &num)) {
        printf("%s!\n", is_good(num) ? "Yes" : "No");
    }
    return 0;
}