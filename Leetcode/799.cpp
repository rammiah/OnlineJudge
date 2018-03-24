using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;


constexpr int size = 100;
double glasses[size][size];

void reset() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            glasses[i][j] = 0;
        }
    }
}

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        reset();
        // 每次都检测上面存储值是加完剩下的，自己所有的
        glasses[0][0] = poured;

        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                double get = 0;
                if (glasses[i - 1][j] > 1) {
                    glasses[i][j] += (glasses[i - 1][j] - 1) / 2;
                    glasses[i][j + 1] += (glasses[i - 1][j] - 1) / 2;
                    glasses[i - 1][j] = 1;
                }
            }
        }
        // 返回结果
        return glasses[query_row][query_glass];
    }
};
