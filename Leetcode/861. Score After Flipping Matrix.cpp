
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        // 首先判断第一列元素
        for (auto &vs : A) {
            if (vs[0] == 0) {
                // 翻转
                for (auto &v : vs) {
                    v = 1 - v;
                }
            }
        }
        // 开始列检测
        for (int col = 0; col < A[0].size(); ++col) {
            // 查看这一列是0多还是1多
            int one = 0, zero = 0;
            for (int row = 0; row < A.size(); ++row) {
                if (A[row][col] == 0) {
                    zero += 1;
                }
                else {
                    one += 1;
                }
            }
            if (zero > one) {
                // 翻转这一列
                for (int row = 0; row < A.size(); ++row) {
                    A[row][col] = 1 - A[row][col];
                }
            }
        }
        // 转换成数字哈
        int sum = 0;
        int num;
        for (int i = 0; i < A.size(); ++i) {
            num = 0;
            for (int j = 0; j < A[0].size(); ++j) {
                num = num * 2 + A[i][j];
            }
            sum += num;
        }
        return sum;
    }
};