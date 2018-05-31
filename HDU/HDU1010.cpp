#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

char maze[8][8] = { 0, };
int row, col, end_row, end_col;
bool flag;
void dfs(int cur_row, int cur_col, int time) {
    if (cur_row < 0 || cur_col < 0 || cur_col >= col || cur_row >= row) {
        return;
    }

    if (maze[cur_row][cur_col] == 'X' || time < 0) {
        return;
    }
    if (maze[cur_row][cur_col] == 'D') {
        flag = time == 0;
        return;
    }
    // dfs
    time--;
    maze[cur_row][cur_col] = 'X';
    dfs(cur_row - 1, cur_col, time);
    if (flag) {
        return;
    }
    dfs(cur_row + 1, cur_col, time);
    if (flag) {
        return;
    }
    dfs(cur_row, cur_col - 1, time);
    if (flag) {
        return;
    }
    dfs(cur_row, cur_col + 1, time);
    maze[cur_row][cur_col] = '.';
}


int main() {
    ios::sync_with_stdio(false);
    // freopen("data.txt", "r", stdin);
    int time;
    cin >> row >> col >> time;
    int s_row, s_col;
    while (row != 0 || col != 0 || time != 0) {
        memset(maze, 0, sizeof(maze));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') {
                    s_row = i;
                    s_col = j;
                }
                else if (maze[i][j] == 'D') {
                    end_row = i;
                    end_col = j;
                }
            }
        }
        // 曼哈顿距离奇偶剪枝
        int dis = abs(s_col - end_col) + abs(s_row - end_row);
        if (dis > time || (dis - time) & 1) {
            cout << "NO" << "\n";
        }
        else {
            flag = false;
            dfs(s_row, s_col, time);
            if (flag) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        
        cin >> row >> col >> time;
    }


    return 0;
}