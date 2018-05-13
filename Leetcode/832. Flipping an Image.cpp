#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void reverse(vector<int> &v) {
        int right = v.size() - 1;
        int left = 0;
        while (left  < right) {
            swap(v[left], v[right]);
            left++;
            right--;
        }
        for (auto &num : v) {
            num = !num;
        }
    }
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        // 反转图像
        int size = A.size();
        vector<vector<int>> v(A);
        for (int i = 0; i < size; ++i) {
            reverse(v[i]);
        }

        return v;
    }
};