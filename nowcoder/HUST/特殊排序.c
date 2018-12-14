#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int l = left;
    int r = right;
    int key = arr[l];
    while (l < r) {
        while (l < r && arr[r] >= key)--r;
        arr[l] = arr[r];
        while (l < r && arr[l] <= key)++l;
        arr[r] = arr[l];
    }
    arr[l] = key;
    sort(arr, left, l - 1);
    sort(arr, l + 1, right);
}

int main() {
    int cnt;
    int arr[1005];
    while (~scanf("%d", &cnt)) {
        for (int i = 0; i < cnt; ++i) {
            scanf("%d", &arr[i]);
        }
        sort(arr, 0, cnt - 1);
        printf("%d\n", arr[cnt - 1]);
        for (int i = 0; i < cnt - 1; ++i) {
            printf("%d%c", arr[i], i == cnt - 2 ? '\n' : ' ');
        }
        if (cnt == 1) {
            printf("-1\n");
        }
    }
    
    return 0;
}