#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 题意不明，我对出题人强烈谴责
int main() {
    bool opened[1005];
    int cnt;
    vector<pair<int, int>> vs;
    scanf("%d", &cnt);
    int from, to;
    for (int i = 0; i < cnt; ++i) {
        scanf("%d %d", &from, &to);
        vs.push_back(make_pair(from, to));
    }

    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            if (j != i && vs[i].second == j) {
                opened[j] = true;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < cnt; ++i) {
        result += opened[i] ? 0 : 1;
    }

    printf("%d\n", result);

    return 0;
}
