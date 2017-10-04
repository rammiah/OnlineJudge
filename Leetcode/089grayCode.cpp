class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>result(1<<n, 0);
        result[0] = 0;
        result[1] = 1;
        size_t index = 1;
        while (index < n) {
            for (size_t i = (1<<index); i < (2<<index); ++i) {
                result[i] = result[(2<<index) - i - 1] + (1<<index);
            }
            index++;
        }
        
        return result;
    }
};
