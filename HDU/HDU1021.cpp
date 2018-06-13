#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// 找规律题目
int nums[] = {1, 2, 0, 2, 2, 1, 0, 1};

int main() {
    int idx;
    while (scanf("%d", &idx) != EOF) {
        printf("%s\n", (nums[idx % 8] == 0 ? "yes" : "no"));
    }
    return 0;
}
