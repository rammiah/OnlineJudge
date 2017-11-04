#include <stdio.h>
#define MAX 150000

// 直接打表吧
int main(void) {
    int from = 0, to = 0;

    // 素数为0，非素数是1
    int nums[MAX] = {0, };
    nums[0] = nums[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        if (nums[i] == 0) {
            for (int j = 2 * i; j < MAX; j += i) {
                nums[j] = 1;
            }
        }
    }

    scanf("%d %d", &from, &to);
    int cnt = 0;
    for (int i = 0; i < MAX; ++i) {
        if (nums[i] == 0) {
            nums[++cnt] = i;
        }
    }
    // printf("%d\n", cnt);

    cnt = 0;
    for (int i = from; i < to; ++i) {
        printf("%d%c", nums[i], ++cnt % 10 == 0 ? '\n' : ' ');
    }
    printf("%d", nums[to]);
    if (cnt % 10 == 0) {
        printf("\n");
    }

    return 0;
}
