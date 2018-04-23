// 0 possible
// 1 immpossible
int possible[2001] = {0};
// 0 no, 1 have
int have[2001] = {0};

class Solution {
public:
    int flipgame(vector<int> &fronts, vector<int> &backs) {
        int result = 0;
        int card_cnt = fronts.size();
        for (int i = 0; i < 2001; ++i) {
            have[i] = 0;
            possible[i] = 0;
        }

        for (int i = 0; i < card_cnt; ++i) {
            // 数字存在
            have[fronts[i]] = have[backs[i]] = 1;
            if (fronts[i] == backs[i]) {
                // fronts[i]必定存在正反面
                possible[fronts[i]] = 1;
            }
        }

        for (int i = 1; i < 2001; ++i) {
            // 第一个就是
            if (possible[i] == 0 && have[i] == 1) {
                return i;
            }
        }
        // 没有满足需求的
        return 0;
    }
};