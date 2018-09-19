#include <stdio.h>

int arr[4][5];

int main() {
    int num;
    while (~scanf("%d", &num)) {
        arr[0][0] = num;
        int cnt = 1;
        while (cnt < 20) {
            scanf("%d", &arr[cnt / 5][cnt % 5]);
            cnt++;
        }
        // 找出两个数，难的地方在于需要保持两个数的出现顺序不能动
        for (int i = 0; i < 5; ++i) {
            for (int j = 2; j < 4; ++j) {
                if (arr[j][i] > arr[1][i] || arr[j][i] > arr[0][i]) {
                    if (arr[1][i] > arr[0][i]) {
                        arr[0][i] = arr[1][i];
                    }
                    arr[1][i] = arr[j][i];
                }
            }
        }
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 5; ++j) {
                printf("%d%c", arr[i][j], j == 4 ? '\n' : ' ');
            }
        }
    }
    
    return 0;
}
