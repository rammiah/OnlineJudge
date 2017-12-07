#include <stdio.h>
#include <string.h>

int main(void) {
    char sub[10000];
    char p_str[10000];
    gets(sub);
    gets(p_str);
    int find[10000];
    int cnt = 0;
    int start = 0;
    int sub_len = strlen(sub);
    int par_len = strlen(p_str);
    // printf("%d %d %s %s", sub_len, par_len, sub, p_str);
    int have = 1;
    for (start = 0; start <= par_len - sub_len; ++start) {
        have = 1;
        for (int i = 0; i < sub_len; ++i) {
            if (sub[i] != p_str[start + i]) {
                have = 0;
                break;
            }
        }
        if (have) {
            find[cnt++] = start;
        }
    }

    if (cnt == 0) {
        printf("-1\n");
    } 
    else {
        for (int i = 0; i < cnt; ++i) {
            printf("%d ", find[i]);
        }
    }

    return 0;
}
