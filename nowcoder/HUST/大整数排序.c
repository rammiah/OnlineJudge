#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Number {
    char num[1005];
    int len;
};
// 比较函数没有考虑周全
int cmp(struct Number a, struct Number b) {
    if (a.len < b.len) {
        return -1;
    }
    else if (a.len == b.len) {
        return strcmp(a.num, b.num);
    }
    return 1;
}

// 这个排序写的好痛苦啊
void sort(struct Number nums[], int cnt) {
    char str[1005];
    for (int i = 0; i < cnt; ++i) {
        int min = i;
        for (int j = i + 1; j < cnt; ++j) {
            if (cmp(nums[j], nums[min]) < 0) {
                min = j;
            }
        }
        if (i != min) {
            struct Number t = nums[i];
            nums[i] = nums[min];
            nums[min] = t;
        }
    }
}

int main() {
    int cnt;
    struct Number nums[105];
    while (~scanf("%d", &cnt)) {
        for (int i = 0; i < cnt; ++i) {
            scanf("%s", nums[i].num);
            nums[i].len = strlen(nums[i].num);
        }
        sort(nums, cnt);
        for (int i = 0; i < cnt; ++i) {
            printf("%s\n", nums[i].num);
        }
    }

    return 0;
}