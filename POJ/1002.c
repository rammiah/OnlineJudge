#include <stdio.h>

#define ALL 10000000

// 建立从char到int映射
int map[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8,
               8, 9, 9, 9, 9};
// 全局数组默认初始化为0,省心
int allNumber[ALL];

int main() {
    int count = 0;
    // 居然是挂在数组上面了。。。，以后开大一点吧
    char number[200];
    int toInt = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; ++i) {
        scanf("%s", number);
        toInt = 0;
        for (int j = 0; number[j] != '\0'; ++j) {
            if (number[j] <= '9' && number[j] >= '0') {
                toInt = toInt * 10 + number[j] - '0';
            } else if (number[j] <= 'Z' && number[j] >= 'A') {
                toInt = toInt * 10 + map[number[j] - 'A'];
            }
        }
        ++allNumber[toInt];
    }
    int index = 0;
    for (int i = 0; i < ALL; ++i) {
        if (allNumber[i] > 1) {
            printf("%03d-%04d %d\n", i / 10000, i % 10000, allNumber[i]);
            ++index;
        }
    }

    if (index == 0) {
        // 细思极恐
        printf("No duplicates.\n");
    }

    return 0;
}
/*
 * 12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279
 * */