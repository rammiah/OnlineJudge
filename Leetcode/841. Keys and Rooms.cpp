#include <vector>
#include <set>

using namespace std;

class Solution {
    set<int> can_in;
    // 遍历过的房子不再遍历
    void dfs(vector<vector<int>>& rooms, int idx) {
        // 已经遍历
        if (can_in.count(idx)) {
            return;
        }
        // 可以进入，加入到set中
        can_in.insert(idx);
        for (auto &id : rooms[idx]) {
            dfs(rooms, id);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        can_in.clear();
        // 好吧，其实就是dfs，是否有门不能被打开
        dfs(rooms, 0);
        // 阿嘞，结果很简单了
        return can_in.size() == rooms.size();
    }
};