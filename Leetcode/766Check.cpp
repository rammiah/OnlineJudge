class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < col; ++i) {
            int r = 0, c = i - r;
            int t = matrix[r][c];
            while (r < row && c < col) {
                if (matrix[r][c] != t)return false;
                ++r, ++c;
            }
        }
        
        for (int i = 0; i < row; ++i) {
            int c = 0, r = i - c;
            int t = matrix[r][c];
            while (r < row && c < col) {
                if (matrix[r][c] != t)return false;
                ++r, ++c;
            }
        }
        
        return true;
    }
};
