class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (auto &bill : bills) {
            // 计算是否能找钱
            if (bill == 5) {
                five += 1;
            }
            else if (bill == 10) {
                // 减一张5元，加一张10元
                if (five >= 1) {
                    five -= 1;
                    ten += 1;
                }
                else {
                    return false;
                }
            }
            else {
                // 找15元，把10块的能花就花
                if (ten >= 1 && five >= 1) {
                    twenty += 1;
                    ten -= 1;
                    five -= 1;
                }
                else if (five >= 3) {
                    five -= 3;
                    twenty += 1;
                }
                else {
                    return false;
                }
            }

        }
        return true;
    }
};
