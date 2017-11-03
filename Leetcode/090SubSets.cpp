//#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    void search(vector<vector<int>> &result, vector<int> &temp, const vector<int> &nums, const int &index) {
        if (index >= nums.size()) {
            result.push_back(temp);
            return;
        }
        int t = index + 1;

        while (t < nums.size() && nums[t] == nums[t - 1]) {
            ++t;
        }
        search(result, temp, nums, t);
        for (int i = index; i < t && i < nums.size(); ++i) {
            temp.push_back(nums[index]);
            search(result, temp, nums, t);
        }
        for (int i = index; i < t && i < nums.size(); ++i) {
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        search(result, temp, nums, 0);
        return result;
    }
};

int main() {
    Solution sol;
    // [],[1],[1,2],[1,2,2],[2],[2,2]
    vector<int> nums{1, 2, 2};
    auto s = sol.subsetsWithDup(nums);
    cout << s.size() << endl;
    for(const auto &v : s) {
        for(const auto &item : v) {
            cout << item << " ";
        }
        cout << "\n";
    }

    return 0;
}
