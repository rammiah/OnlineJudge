#include <stdio.h>

int main() {
    int num;
    while (~scanf("%d", &num)) {
        printf("%o\n", num);
    }
    return 0;
}