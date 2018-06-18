class ExamRoom {
public:
    set<int> seats;
    int n;
    ExamRoom(int N) {
        // 保存一下N
        n = N;
    }

    int seat() {
        // 寻找座位
        int result = 0;
        if (seats.size() != 0) {
            result = 0;
            int idx = 0;
            int max_len = 0;
            // 查看0是否占用
            if (!seats.count(0)) {
                // 注意，最后的那个位置和0处的距离是不需要除2的
                max_len = *seats.begin() - 0;
                result = 0;
            }
            auto it = seats.begin(), end = seats.end();
            while (it != end) {
                int len = (*it - idx) / 2;
                if (len > max_len) {
                    max_len = len;
                    result = (*it + idx) / 2;
                }
                idx = *it;
                ++it;
            }
            // 看最后的位置有没有被占
            if (!seats.count(n - 1)) {
                int len = n - 1 - *seats.rbegin();
                if (len > max_len) {
                    max_len = len;
                    result = n - 1;
                }
            }
        }

        seats.insert(result);
        return result;
    }

    void leave(int p) {
        seats.erase(seats.find(p));
    }
};