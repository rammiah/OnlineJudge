#!/usr/bin/env python
# coding=utf-8
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        maxPro = 0
        minPri = 102400
        temp = 0
        for x in prices:
            maxPro = max(x - minPri, maxPro)
            minPri = min(x, minPri)
        return maxPro

