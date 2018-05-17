#include <cstdio>

using namespace std;

int nums[5005];
int record[5005];
int len[5005];

int main() {
    int cnt;
    int max = 0;
    int num;    
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i) {
        scanf("%d", &record[i]);
        int temp = max - 1;
        while (temp >= 0 && nums[temp] <= record[i]) {
            temp--;
        }
        // 此位置可得到最长的递减子序列
        len[i] = temp + 2;
        // nums[temp + 1] = record[i];
        nums[temp + 1] = record[i];
        if (temp + 2 > max) {
            max = temp + 2;
        } 
    }
    int k = max;
    int sum = 0;
    // 获取结果的序列
    for (int i = cnt - 1; i >= 0; --i) {
        if (k == len[i]) {
            nums[--k] = record[i];
        }
    }
    // 输出答案
    for (int i = 0; i < max - 1; ++i) {
        printf("%d ", nums[i]);
    }
    // 最后一个后面没有空格
    printf("%d\n", nums[max - 1]);

    return 0;
}