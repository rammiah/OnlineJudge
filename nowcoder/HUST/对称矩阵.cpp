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

#define MAXN 105
int mat[MAXN][MAXN];

int main() {
    int N;
    while (cin >> N) {
        // 输入矩阵
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; j++) {
                cin >> mat[i][j];
            }
        }
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; j++) {
                if (mat[i][j] != mat[j][i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        cout << (ok ? "Yes!\n" : "No!\n");
    }

    
    return 0;
}
