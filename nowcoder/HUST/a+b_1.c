#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        printf("%d\n", a + b);
    }
    return 0;
}