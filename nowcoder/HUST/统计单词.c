#include <stdio.h>

char str[100000];

int main(void) {
    int len = 0;
    while (~scanf("%s", str)) {
        len = strlen(str);
        if (str[0] == '.') {
            printf("\n");
        }
        else if (str[len - 1] == '.') {
            printf("%d\n", len - 1);
        }
        else {
            printf("%d ", len);
        }
    }

    return 0;
}
