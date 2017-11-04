#include <stdio.h>
#include <string.h>

#define ISVALID(x) ((x) <= 'E' && (x) >= 'A')
#define MAX_NUM 1024
#define SUM 2310
// 2 * 3 * 5 * 7 * 11 = 2310

// 给ABCDE分配数字
int str_to_num[5] = {2, 3, 5, 7, 11};

int main(void) {
    char str[MAX_NUM];
    size_t len = 0;
    size_t min;
    int sum;
    while (scanf("%s", str) != EOF) {
        // 扩充字符串为原来二倍长
        strcat(str, str);
        // 得到长度
        len = strlen(str);
        // 初始化min
        min = len / 2;
        // start指向开始，end指向最后的那一个字符
        for (int i = 0; i < len / 2; ++i) {
            sum = 1;
            // 检测从i开始最短的可行字符串
            for (int j = i; j < len; ++j) {
                if (ISVALID(str[j])) {
                    sum *= str_to_num[str[j] - 'A'];
                    if (sum % SUM == 0) {
                        min = j - i + 1 < min ? (size_t) (j - i + 1) : min;
                        break;
                    }
                }
            }
        }

        printf("%lu\n", len / 2 - min);
    }

    return 0;
}
