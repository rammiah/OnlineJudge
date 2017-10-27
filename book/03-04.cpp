#include <iostream>
/*
 * 骰子旋转，初始上前右为1，2，3，对立面和为7
 * NSWE代表旋转方向上下左右
 *
2
SW
Case 1:3
3
WWN
Case 2:2
10
NNNENNWSSE
Case 3:3
^D
 */
int main() {
    // 0不放东西
    int times = 0;
    int case_num = 1;
    while (std::cin >> times) {
        char ch;
        int temp;
        int arr[7] = {0, 1, 2, 3, 4, 5, 6};
        for (int i = 0; i < times; ++i) {
            std::cin >> ch;
            // 直接模拟旋转
            switch (ch) {
                case 'N':
                    temp = arr[1];
                    arr[1] = arr[2];
                    arr[2] = arr[6];
                    arr[6] = arr[5];
                    arr[5] = temp;
                    break;
                case 'S':
                    temp = arr[1];
                    arr[1] = arr[5];
                    arr[5] = arr[6];
                    arr[6] = arr[2];
                    arr[2] = temp;
                    break;
                case 'W':
                    temp = arr[1];
                    arr[1] = arr[3];
                    arr[3] = arr[6];
                    arr[6] = arr[4];
                    arr[4] = temp;
                    break;
                case 'E':
                    temp = arr[1];
                    arr[1] = arr[4];
                    arr[4] = arr[6];
                    arr[6] = arr[3];
                    arr[3] = temp;
                    break;
                default:
                    continue;
            }
        }
        // 输出结果
        std::cout << "Case " << case_num++ << ":" << arr[1] << "\n";
    }

    return 0;
}
