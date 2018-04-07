class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        if (array.size() == 0 || array[0].size() == 0) {
            return false;
        }
        int row_lim = array.size();
        int col_lim = array[0].size();
        int row = 0, col = col_lim - 1;
        while (row < row_lim && col >= 0) {
            if (array[row][col] > target) {
                --col;
            } else if (array[row][col] < target) {
                ++row;
            } else {
                return true;
            }
        }
        
        return false;
    }
};