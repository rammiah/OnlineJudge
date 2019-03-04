// 挺没意思的一道题
class Solution {
    int mark[256];
public:
    int numJewelsInStones(string J, string S) {
        // 数据清零，这个函数应该是无状态的，虽然类有状态
        bzero(mark, sizeof(mark));
        for (auto &ch : J) {
            mark[ch] = 1;
        }
        int res{};
        for (auto &ch : S) {
            res += mark[ch];
        }
        return res;
    }
};

