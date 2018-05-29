#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    // x.y
    unsigned long long x;
    char y[1005];
    // 最后只需要输出x部分
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%llu.%s", &x, y);
        // 最重要的是X部分需不需要进位
        // 假设需要进位，肯定是y从左到右都能进
        int len = strlen(y);
        int add = 0;
        for (int i = 0; i < len; ++i) {
            if (y[i] < '4') {
                break;
            } else if (y[i] == '4') {
                continue;
            } else {
                add = 1;
                break;
            }
        }

        printf("%llu\n", x + add);
    }
    
    return 0;
}