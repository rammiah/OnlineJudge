class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        # 怎么会有这么爽的语言 /(ㄒoㄒ)/~~
        return list(set(nums1).intersection(set(nums2)))
        