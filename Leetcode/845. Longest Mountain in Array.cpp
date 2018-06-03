#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void up_max(int &a, int b) {
    a = a > b ? a : b;
}

void up_min(int &a, int b) {
    a = a < b ? a : b;
}

class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        // 坑爹的吧，写了个dp发现不是
        int result = 0;
        int size = A.size();
        for (int i = 1; i < size - 1; ++i) {
            int t_max = 1;
            if (A[i - 1] >= A[i] || A[i + 1] >= A[i]) {
                continue;
            }
            // 开始左右扫描
            int left = i - 1;
            while (left >= 0 && A[left] < A[left + 1]) {
                left--;
                t_max++;
            }
            int right = i + 1;
            while (right < size && A[right] < A[right - 1]) {
                right++;
                t_max++;
            }
            up_max(result, t_max);
        }

        return result >= 3 ? result : 0;
    }
};