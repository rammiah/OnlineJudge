class Solution:
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        words = []
        idx = 0
        for i in range(0, len(s), k):
            if idx % 2 == 0:
                words.append(s[i:i+k][::-1])
            else:
                words.append(s[i:i+k])
            idx = idx + 1
        return ''.join(words)
