// 1 1 2 3 5 8
#include <stdio.h>

unsigned long long arr[100];

// 打表
void init() {
    arr[0] = arr[1] = 1;
    for (int i = 2; i < 100; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

int main() {
    init();
    int cnt;
    while(~scanf("%d", &cnt)) {
        printf("%d\n", arr[cnt]);
    }
    
    return 0;
}
