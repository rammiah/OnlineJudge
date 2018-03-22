using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        const char *rows[3] = {board[0].c_str(), board[1].c_str(), board[2].c_str()};
        // 检查XO个数
        int x_count = 0, o_count = 0;
        for (auto &row : rows) {
            for (int j = 0; j < 3; ++j) {
                if (row[j] == 'O') {
                    ++o_count;
                }else if(row[j] == 'X'){
                    ++x_count;
                }
            }
        }

        if (o_count > x_count || x_count >= o_count + 2) {
            return false;
        }

        // 检测获胜者
        // 检查横的
        bool x_win = false, o_win = false;
        for (auto &row : rows) {
            if (row[0] == row[1] && row[1] == row[2]) {
                if (row[0] == 'X') {
                    x_win = true;
                }else if (row[0] == 'O') {
                    o_win = true;
                }
            }
        }
        // 检测竖的
        for (int i = 0; i < 3; ++i) {
            if (rows[0][i] == rows[1][i] && rows[1][i] == rows[2][i]) {
                if (rows[0][i] == 'X') {
                    x_win = true;
                }else if (rows[0][i] == 'O') {
                    o_win = true;
                }
            }
        }
        // 检测斜的
        if (rows[0][0] == rows[1][1] && rows[1][1] == rows[2][2]) {
            if (rows[0][0] == 'X') {
                x_win = true;
            }else if (rows[0][0] == 'O') {
                o_win = true;
            }
        } else if (rows[0][2] == rows[1][1] && rows[1][1] == rows[2][0]) {
            if (rows[2][0] == 'X') {
                x_win = true;
            }else if (rows[2][0] == 'O') {
                o_win = true;
            }
        }

        if (x_win && o_win) {
            return false;
        }

        if (x_win && x_count == o_count) {
            return false;
        }
        if (o_win && x_count > o_count) {
            return false;
        }

        return true;
    }
};
