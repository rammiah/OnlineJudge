//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


bool is_in(const vector<int> &a, const vector<int> &b) {
    vector<bool> as(1001), bs(1001);    
    // 计算a是否在b中存在且相连
    int size = a.size();
    for (int i = 0; i < size; ++i) {
        as[a[i]] = true;
        bs[b[i]] = true;
    }
    if (as == bs) {
        return true;
    }
    for (int i = size; i < b.size(); ++i) {
        bs[b[i - size]] = false;
        bs[b[i]] = true;
        if (as == bs) {
            return true;
        }
    }

    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Yaning Wang/Documents/GitHub/OnlineJudge/etc/4-2.txt", "r", stdin);
    #endif
    int sum, cnt;
    scanf("%d %d", &sum, &cnt);
    vector<int> result;
    for (int i = 0; i < sum; ++i) {
        result.push_back(i + 1);
    }
    vector<vector<int>> datas(cnt, vector<int>());
    for (int i = 0; i < cnt; ++i) {
        // 先记录所有数据吧
        // 再依次检查好了
        // 读入所有数据
        int T;
        int data;
        scanf("%d", &T);
        for (int j = 0; j < T; ++j) {
            scanf("%d", &data);
            datas[i].push_back(data);
        }
    }
    // 开始检测
    bool ok = false;
    // 如何检测是个问题
    // 只能应对简单级别
    // 中等就会超时
    while (!ok) {
        ok = true;
        for (int i = 0; i < cnt && ok; ++i) {
            if (is_in(datas[i], result)) {
                continue;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        } else {
            if (!next_permutation(result.begin(), result.end())) {
                break;
            }
        }
    }

    if (ok) {
        // 输出排列
        for (int i = 0; i < sum - 1; ++i) {
            printf("%d ", result[i]);
        }
        printf("%d\n", result[sum - 1]);
    } else {
        printf("-1\n");
    }
    return 0;
}
