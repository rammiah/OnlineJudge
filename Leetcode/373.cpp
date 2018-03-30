class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size_1 = nums1.size(), size_2 = nums2.size();
        vector<pair<int, int>> results;
        k = min(k, size_1 * size_2);// 缩小k的范围
        int cnt = 0;
        vector<int> help(size_1, 0);// 节省时间的关键
        int min_val, min_index;
        while (cnt < k) {
            min_val = INT_MAX;
            // 妙啊，时间复杂度O(min(K, m * n) * m)，空间复杂度O(min(k, m))
            for (int i = 0; i < size_1; ++i) {
                if (help[i] < size_2 && nums1[i] + nums2[help[i]] < min_val) {
                    min_val = nums1[i] + nums2[help[i]];
                    min_index = i;
                }
            }
            // 写入到results中
            results.emplace_back(nums1[min_index], nums2[help[min_index]++]);
        }

        return results;
    }
};