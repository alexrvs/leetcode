class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        chars = list(s)
        l = 0
        r = len(chars) - 1
        while l < r:
            c = chars[l]
            chars[l] = chars[r]
            chars[r] = c
            l += 1
            r -= 1
        return "".join(chars)
