// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    // 好多坑啊
    int firstBadVersion(int n) {
        long long left = 1;
        long long right = n;
        if (isBadVersion(1)) return 1;
        long long mid;
        while (left <= right) {
            mid = (right + left + 1) / 2;
            if (isBadVersion(mid) && !isBadVersion(mid - 1)) {
                return mid;
            }
            else if (isBadVersion(mid)) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return mid;
    }
};