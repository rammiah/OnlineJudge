class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int row = 0, col = matrix[0].size() - 1;
        int row_limit = matrix.size();
        // 简单的搜索
        while (row < row_limit && col >= 0) {
            if (matrix[row][col] > target) {
                --col;
            } else if (matrix[row][col] < target) {
                ++row;
            }else {
                return true;                
            }
        }

        return false;
    }
};