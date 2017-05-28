/*************************************************************************
	> File Name: 198MaxRobery.c
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年05月28日 星期日 14时17分10秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : b)

// 动态规划学得不到家，麻烦了一点
// 主要就是当前的需要前3个来得出现在这个可以取得的最大值，而其中前一个是用不到的
// 答案里面有的没有开辟数组，但是变量交换看着我就头晕，还是简单一点吧，打败44%c语言的提交者
int rob(int* nums, int numsSize) {
    // 上来先把用不到动态规划的4个去了
    if (numsSize == 0)return 0;
    if (numsSize == 1)return nums[0];
    if (numsSize == 2)return MAX(nums[1], nums[0]);
    if (numsSize == 3)return MAX(nums[0]+ nums[2], nums[1]);
    int *big = (int*)malloc(numsSize * sizeof(int));
    big[0] = nums[0];
    big[1] = nums[1];
    big[2] = nums[0] + nums[2];
    for (int i = 3; i < numsSize; ++i) {
        // 规划，由前三个里得出这个的最大结果
        big[i] = MAX(nums[i] + big[i - 2], nums[i] + big[i - 3]);
    }
    // 最大的在最后2个里面
    int res = MAX(big[numsSize - 1], big[numsSize - 2]);
    free(big);
    return res;
}

int main() {
    int arr[] = { 1, 2, 3, 1 };

    printf("%d", rob(arr, 4));


    return 0;
}
