#include <stdio.h>

int main() {
    unsigned char uch;
    char ch;
    int arr[8];
    int flag;
    while (~(ch = getchar())) {
        if (ch == '\n') {
            continue;
        }
        uch = ch;
        // 奇校验
        flag = 1;
        for (int i = 0; i < 7; ++i) {
            arr[i] = uch % 2;
            uch /= 2;
            flag ^= arr[i];
        }
        // 校验位
        arr[7] = flag;
        for (int i = 7; i >= 0; --i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    
    return 0;
}