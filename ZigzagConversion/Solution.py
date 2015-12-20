class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        step = 2 * (numRows - 1)
        l = len(s)
        res = ""
        for i in range(0, numRows):
            j = 0
            while j - i < l:
                if i == 0 or i == numRows - 1:
                    if j + i < l:
                        res += s[j + i]
                else:
                    if j - i >= 0:
                        res += s[j - i]
                    if j + i < l:
                        res += s[j + i]
                j += step
        return res
