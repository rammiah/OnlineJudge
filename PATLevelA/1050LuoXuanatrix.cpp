/*************************************************************************
    > File Name: 1050LuoXuanatrix.cpp
    > Author: Yaning Wang, CS1607
    > Mail: wangyanign6166@gmail.com
    > School: HUST
    > Created Time: 2017年05月04日 星期四 15时46分29秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int row; // 行数
int col; // 列数

int GetRol(int N){
    int t = (int)sqrt(N);
    for (; t <= N; ++t){
        if (N % t  == 0 && t >= N / t)return t;
    }
    return -1;
}

void Sort(vector<int>&arr, const int start, const int end){
    if(start >= end)return;
    int key = arr[start];
    int s = start, e = end;
    while (s < e){
        while (arr[e] <= key && s < e)--e;
        arr[s] = arr[e];
        while (arr[s] >= key && s < e)++s;
        arr[e] = arr[s];
    }
    arr[s] = key;
    Sort(arr, start, s - 1);
    Sort(arr, s + 1, end);
}

int main(void){
    int N = 0;
    cin >> N;
    vector<int> arr(N, 0);
    for (auto i = 0u; i< arr.size(); ++i){
        cin >> arr[i];
    }
    Sort(arr, 0, arr.size() - 1);
    col = GetRol(N);
    row = N / col;
    vector<vector<int>>res(col, vector<int>(row));
    int horizontal = row; // 列数
    int vertical = col; // 行数

    // 1 to_right, 2 to_down, 3 to_left, 4 to_up
    int status = 1;
    int _row = 0; // 列数
    int _col = 0; // 行数
    for (int i = 0; i < N;){
        if (status == 1){
            for (int j = _col; j < horizontal; ++j){
                res[_row][j] = arr[i++];
            }
            ++_row;
            status = 2;
        }
        else if (status == 2){
            for (int j = _row; j < vertical; ++j){
                res[j][horizontal - 1] = arr[i++];
            }
            --horizontal;
            status = 3;
        }
        else if (status == 3){
            for (int j = horizontal - 1; j > _col; --j){
                res[vertical - 1][j] = arr[i++];
            }
            --vertical;
            status = 4;
        }
        else if (status == 4){
            for (int j = vertical; j > _row - 1; --j){
                res[j][_col] = arr[i++];
            }
            ++_col;
            status = 1;
        }
    }

    for (int i = 0; i < col; ++i){
        cout << res[i][0];
        for (int j = 1; j < row; ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，
 按顺时针螺旋方向填充。要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。
输入格式：
输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。
输出格式：
输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。
输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
*/
