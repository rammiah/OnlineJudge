#include <stdio.h>
#include <stdlib.h>


// 快速排序阿拉
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
    int arr[105];
    while (~scanf("%d", &cnt)) {
        for (int i = 0; i < cnt; ++i) {
            scanf("%d", &arr[i]);
        }
        sort(arr, 0, cnt - 1);
        for (int i = 0; i < cnt; ++i) {
            printf("%d ", arr[i]);
        }
    }
    
    return 0;
}