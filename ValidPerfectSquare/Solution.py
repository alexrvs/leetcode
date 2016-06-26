class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 1:
            return True
        l = 1
        r = num / 2
        while l < r:
            m = l + (r - l) / 2
            if m < num / m:
                l = m + 1
            else:
                r = m
        return (l == num / l and num % l == 0)
