#include <stdio.h>

char str[1005];

int main() {
    while (~scanf("%s", str)) {
        int left = 0;
        int right = strlen(str) - 1;
        int ok = 1;
        while (left < right) {
            if (str[left++] != str[right--]) {
                ok = 0;
                break;
            }
        }
        printf("%s!\n", ok ? "Yes" : "No");
    }
    return 0;
}