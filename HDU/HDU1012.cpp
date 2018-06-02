#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
    double nums[10];
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 2.5;
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    double fact = 2;
    for (int i = 3; i < 10; ++i) {
        fact *= i;
        nums[i] = nums[i - 1] + 1 / fact;
        printf("%d %.9f\n", i, nums[i]);
    }

    return 0;
}