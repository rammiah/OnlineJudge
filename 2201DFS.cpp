#include <iostream>

using namespace std;

char g_field[50][50];
int sum = 0;
int g_row = 0, g_col = 0;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void DFS(int row, int col, int depth) {
    // 越界
    if (row > g_row || col > g_col || row < 0 || col < 0) return;
    // 无效
    if (g_field[row][col] == '*')return;
    // 开始深搜
    if (g_field[row][col] == '@') {
        if (depth == 0) {
            ++sum;
        }
        g_field[row][col] = '*';
        DFS(row - 1, col, depth + 1);
        DFS(row + 1, col, depth + 1);
        DFS(row, col - 1, depth + 1);
        DFS(row, col + 1, depth + 1);
    }
}

int main(void) {
    cin >> g_row >> g_col;
    for (int i = 0; i < g_row; ++i) {
        for (int j = 0; j < g_col; ++j) {
            cin >> g_field[i][j];
        }
    }
    
    for (int i = 0; i < g_row; ++i) {
        for (int j = 0; j < g_col; ++j) {
            DFS(i, j, 0);
        }
    }

    cout << sum << endl;

    return 0;
}