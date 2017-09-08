int count = 0; // 全局记录总数
int max = 0;
// 检测该深度时是否满足
bool Check(int* arr, int depth) {
    int val_dif = 0; // 左右差
    int ind_dif = 0; // 上下差
    for (int i = 1; i <= depth; ++i) {
        for (int j = i + 1; j <= depth; j++) {
            val_dif = arr[i] - arr[j];
            ind_dif = i - j;
            if (val_dif == 0 || val_dif == ind_dif || val_dif == -ind_dif) {
                return false;
            }
        }
    }
    return true;
}

void DFS(int *arr, const int now) {
    for (int i = 1; i <= max; i++) {
        arr[now] = i;
        if (Check(arr, now)) {// 如果已经是第八个并且满足条件，打印
            if (now == max) {
                ++count;
                continue; // 不需要到下一层继续找了
            }// 未到第八层且前面的几层可以满足条件
            DFS(arr, now + 1);
        }
    }
}

// 我都不想写八皇后了。。。
int totalNQueens(int t) {
    max = t;
    int a[max + 1] = { 0, };
    DFS(a, 1); // 从第一层开始找
    return count;
}
