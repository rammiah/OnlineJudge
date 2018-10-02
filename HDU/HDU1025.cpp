#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAXN 500005

using namespace std;

int arr[MAXN];
int dp[MAXN];

int find(int arr[], int left, int right, int val) {
    int l = left, r = right;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == val) {
            return mid;
        }
        else if (arr[mid] < val) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return l;
}

int main() {
    int cnt;
    int idx, val;
    int cas = 1;
    while (~scanf("%d", &cnt)) {
        for (int i = 0; i < cnt; ++i) {
            scanf("%d %d", &idx, &val);
            arr[idx] = val;
        }
        dp[0] = arr[1];
        int len = 1;
        for (int i = 2; i <= cnt; ++i) {
            if (arr[i] > dp[len - 1]) {
                dp[len++] = arr[i];
            }
            else {
                idx = find(dp, 0, len, arr[i]);
                dp[idx] = arr[i];
            }
        }

        printf("Case %d:\n", cas++);
        if (len == 1) {
            printf("My king, at most 1 road can be built.\n\n");
        }
        else
        {
            printf("My king, at most %d roads can be built.\n\n", len);
        }
    }

    return 0;
}
