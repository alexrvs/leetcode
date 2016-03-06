class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = len(s)
        sum = 0
        for i in range(0, l):
           sum = sum * 26 + (ord(s[i]) - ord('A') + 1) 
        return sum

