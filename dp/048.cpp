#include <cstdio>
#include <algorithm>

using namespace std;
int F[105][105], S[105][105];
int nums[105];;

int main() {
    // freopen("048.txt", "r", stdin);
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i) {
        scanf("%d", &nums[i]);
    }

    F[0][0] = nums[0];
    // 拿最后一个
    F[cnt - 1][cnt - 1] = nums[cnt - 1]; 
    for (int j = 1; j < cnt; ++j) {
        for (int i =cnt - 2; i >= 0; --i) {
            if (i <= j) {
                F[i][j] = max(nums[i] + S[i + 1][j], nums[j] + S[i][j - 1]);
                S[i][j] = min(F[i + 1][j], F[i][j - 1]);
            } else {
                F[i][j] = S[i][j] = 0;
            }
        }
    }

    printf("%d %d\n", F[0][cnt - 1], S[0][cnt - 1]);
    return 0;
}
