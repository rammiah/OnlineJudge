class RLEIterator {
    list<pair<int, int>> nums;
public:
    // list可以在两端操作，和deque差不多
    RLEIterator(vector<int> A) {
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] > 0) {
                nums.emplace_back(A[i], A[i + 1]);
            }
        }
    }

    int next(int n) {
        // 获取第n个数据
        int res = -1;
        while (n > 0 && !nums.empty()) {
            if (n > nums.front().first) {
                n -= nums.front().first;
                nums.pop_front();
            } else if (n == nums.front().first) {
                n = 0;
                res = nums.front().second;
                nums.pop_front();
            } else {
                res = nums.front().second;
                nums.front().first -= n;
                n = 0;
            }
        }
        return res;
    }
};


/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */

