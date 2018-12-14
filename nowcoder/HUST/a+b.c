#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 1005

char str1[MAXN], str2[MAXN], result[MAXN];

int main() {
    while (~scanf("%s %s", str1, str2)) {
        int idx1 = strlen(str1) - 1;
        int idx2 = strlen(str2) - 1;
        int idx = 0;
        int carry = 0;
        while (carry > 0 || idx1 >= 0 || idx2 >= 0) {
            carry += idx1 >= 0 ? str1[idx1--] - '0' : 0;
            carry += idx2 >= 0 ? str2[idx2--] - '0' : 0;
            // result保留余数
            result[idx++] = carry % 10;
            carry /= 10;
        }
        for (int i = idx - 1; i >= 0; --i) {
            printf("%d", result[i]);
        }
        printf("\n");
        memset(result, 0, sizeof(result));
    }
    return 0;
}