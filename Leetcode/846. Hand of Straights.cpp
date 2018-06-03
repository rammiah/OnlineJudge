#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (W == 1) {
            return true;
        }
        if (hand.size() % W) {
            return false;
        }
        map<int, int> num_cnt;
        // 先排序哈
        sort(hand.begin(), hand.end());
        for (auto &num : hand) {
            num_cnt[num]++;
        }
        // 开始检测吧
        int size = hand.size();
        // 从最小的开始分，最小的肯定是第一个
        for (int i = 0; i < size; ++i) {
            if (num_cnt[hand[i]] > 0) {
                for (int j = 0; j < W; ++j) {
                    if (num_cnt[hand[i] + j] > 0) {
                        --num_cnt[hand[i] + j];
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};