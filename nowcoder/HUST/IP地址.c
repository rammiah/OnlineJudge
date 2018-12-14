#include <stdio.h>

int main() {
    int nums[4];
    bool ok;
    while (~scanf("%d.%d.%d.%d", &nums[0], &nums[1],&nums[2],&nums[3])) {
        ok = true;
        for (int i = 0; i < 4; ++i) {
            if (nums[i] < 0 || nums[i] > 255) {
                ok = false;
                break;
            }
        }
        printf("%s\n", ok ? "Yes!" : "No!");
    }

    return 0;
}