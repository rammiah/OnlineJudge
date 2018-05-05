#include <stdio.h>

int main() {
    char isbn[20];
    scanf("%s", isbn);
    int idx = 1;
    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        if (isbn[i] != '-') {
            sum += (isbn[i] - '0') * idx++;
        }
    }
    sum %= 11;
    char right[] = "0123456789X";
    if (isbn[12] == right[sum]) {
        printf("Right\n");
    } else {
        isbn[12] = right[sum];
        printf("%s\n", isbn);
    }

    return 0;
}
