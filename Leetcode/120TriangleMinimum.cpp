#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        size_t rows = triangle.size();
        for (size_t i = 1; i < rows; ++i) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for (int j = 1; j < triangle[i].size() - 1; ++j) {
                triangle[i][j] += (triangle[i - 1][j - 1] > triangle[i - 1][j] ?
                                   triangle[i - 1][j] : triangle[i - 1][j - 1]);
            }
        }

        int min = INT_MAX;
        for (int i = 0; i < rows; ++i) {
            if (triangle[rows - 1][i] < min) {
                min = triangle[rows - 1][i];
            }
        }

        return min;
    }
};

// 6到飞起，从上到下不如从下到上
//class Solution {
//public:
//    int minimumTotal(vector<vector<int>>& triangle) {
//        size_t len=triangle.size();
//        
//        for(int i=len-2;i>=0;--i)
//            for(int j=0;j<i+1;++j)
//                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
//            
//        
//        return triangle[0][0];
//    }
//};

int main() {
    Solution sol;
    vector<vector<int>> test = {
            {-1},
            {-2,-3}};
    cout << sol.minimumTotal(test) << endl;
    return  0;
}

