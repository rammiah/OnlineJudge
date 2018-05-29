#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>

int bias = 500002;
int nums[1000005] = {0, };

int main() {
    int cnt, needs;
    int num;
    while(scanf("%d %d", &cnt, &needs) != EOF) {
        memset(nums, 0, sizeof(nums));
        for (int i = 0; i < cnt; ++i) {
            scanf("%d", &num);
            nums[num + bias]++;
        }
        int idx = 1000004;
        while (needs > 0) {
            while (nums[idx] == 0) {
                idx--;
            }
            while (nums[idx] > 0 && needs > 0) {
                printf("%d%c", idx - bias, (needs == 1 ? '\n' : ' '));
                nums[idx]--;
                needs--;
            }
            idx--;
        }
    }
    
    return 0;
}

