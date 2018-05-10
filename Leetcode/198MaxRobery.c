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

// 在OJ中永远不要使用new和delete或者malloc或者free
// 时间消耗太大
int big[10000];
int rob(int* nums, int numsSize) {
    // 上来先把用不到动态规划的4个去了
    if (numsSize == 0)return 0;
    if (numsSize == 1)return nums[0];
    if (numsSize == 2)return MAX(nums[1], nums[0]);
    if (numsSize == 3)return MAX(nums[0]+ nums[2], nums[1]);
    // int *big = (int*)malloc(numsSize * sizeof(int));
    big[0] = nums[0];
    big[1] = nums[1];
    big[2] = nums[0] + nums[2];
    for (int i = 3; i < numsSize; ++i) {
        // 规划，由前三个里得出这个的最大结果
        big[i] = MAX(nums[i] + big[i - 2], nums[i] + big[i - 3]);
    }
    // 最大的在最后2个里面
    int res = MAX(big[numsSize - 1], big[numsSize - 2]);
    // free(big);
    return res;
}

int main() {
    int arr[] = { 1, 2, 3, 1 };

    printf("%d", rob(arr, 4));


    return 0;
}
