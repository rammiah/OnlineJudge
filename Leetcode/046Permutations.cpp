class Solution {
public:
    // 没办法，一眼看见就想起了深度搜索，没想到还真的可以
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> temp;
        vector<vector<int>>result;
        // 使用map标记数字是否在temp中，本来想使用数组的，但是考虑数据可能会很可怕，就算了吧
        map<int, bool> map;
        for (const int &t : nums) {
            map[t] = true;
        }
        DFS(result, temp, nums, map);
        return result;
    }

protected:
    void DFS(vector<vector<int>> &result, vector<int> &temp, const vector<int> &nums, map<int, bool > &map) {
        bool isEnd = true;
        for (const int &t : nums) {
            if (map[t]) {
                map[t] = false;
                temp.push_back(t);
                DFS(result, temp, nums, map);
                temp.pop_back();
                map[t] = true;
                isEnd = false;
            }
        }
        if (isEnd) {
            result.push_back(temp);
        }
    }
};
