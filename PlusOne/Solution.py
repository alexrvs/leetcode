class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        l = len(digits)
        res = []
        c = 1
        for i in range(l-1, -1, -1):
            s = digits[i] + c
            c = s / 10
            res.append(s % 10)
        if c == 1:
            res.append(1)
        return list(reversed(res))
