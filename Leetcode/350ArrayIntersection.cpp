class Solution {
public:
	// 感觉像合并链表
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int>sol;
        while (i < nums1.size() && j < nums2.size()) {
        	if (nums1[i] == nums[j]) {
        		sol.push_back(nums[i]);
        		++i;
        		++j;
        	} else if (nums1[i] > nums[j]) {
        		++j;
        	} else {
        		++i;
        	}
        }
        return sol;
    }
};