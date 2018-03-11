
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
constexpr int size_ = 100;
double glasses[size_][size_];

bool is_left[size_][size_];

void reset() {
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            glasses[i][j] = 0;
            is_left[i][j] = false;
        }
    }
}



class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        reset();
        // 每次都检测上面存储值是加完剩下的，还是自己所有的
        if (poured > 1) {
            glasses[0][0] = poured - 1;
            is_left[0][0] = true;
        } else {
            glasses[0][0] = poured;
            is_left[0][0] = false;
        }

        for (int i = 1; i <= query_row; ++i) {
            // 0处的和i处的特殊处理，他们只有一个输入口
            if (is_left[i - 1][0]) {
                double get = glasses[i - 1][0] / 2;
                if (get > 1) {
                    glasses[i][0] = get - 1;
                    is_left[i][0] = true;
                }else {
                    glasses[i][0] = get;
                    is_left[i][0] = false;
                }
            }else {
                glasses[i][0] = 0;
                is_left[i][0] = false;
            }
            for (int j = 1; j <= i; ++j) {
                double get = 0;
                if (is_left[i - 1][j - 1]) {
                    get += glasses[i - 1][j - 1] / 2;
                }
                if (is_left[i - 1][j]) {
                    get += glasses[i - 1][j] / 2;
                }
                if (get > 1) {
                    glasses[i][j] = get - 1;
                    is_left[i][j] = true;
                } else {
                    glasses[i][j] = get;
                    is_left[i][j] = false;
                }
            }

            if (is_left[i - 1][i - 1]) {
                double get = glasses[i - 1][i - 1] / 2;
                if (get > 1) {
                    glasses[i][i] = get - 1;
                    is_left[i][i] = true;
                }else {
                    glasses[i][i] = get;
                    is_left[i][i] = false;
                }
            } else {
                glasses[i][i] = 0;
                is_left[i][i] = false;
            }
        }
        // 有剩下说明是1
        if (is_left[query_row][query_glass]) {
            return 1;
        }else {
            // 不是剩下的直接返回
            return glasses[query_row][query_glass];
        }
    }
};