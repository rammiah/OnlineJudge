#!/bin/python3
class Solution:
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        S = S.upper()[::-1].replace('-', '')
        lst = []
        for i in range(0, len(S), K):
            lst.append(S[i:i+K])
        return '-'.join(lst)[::-1]
        
