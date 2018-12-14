#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

int first_idx[256];

int main() {
    string str;
    while (cin >> str) {
        // 使用map记录其发生的位置
        // 全部赋值为-1
        memset(first_idx, -1, sizeof(first_idx));
        map<char, vector<int>> idxs;
        for (int i = 0; i < str.length(); ++i) {
            if (first_idx[str[i]] == -1) {
                first_idx[str[i]] = i;
            }
            idxs[str[i]].push_back(i);
        }
        for (int i = 0; i < str.length(); ++i) {
            if (first_idx[str[i]] == i && idxs[str[i]].size() >= 2) {
                auto &vs = idxs[str[i]];
                for (int j = 0; j < vs.size(); ++j) {
                    cout << str[i] << ":" << vs[j] << (j == vs.size() - 1 ? '\n' : ',');
                }
            }
        }
    }

    return 0;
}
