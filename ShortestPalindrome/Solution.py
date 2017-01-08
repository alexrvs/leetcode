class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        size = len(s)
        if size < 2:
            return s
        l = 2 * size + 1
        longStr = s + '#' + s[::-1]
        table = [0] * l
        idx = 0
        for i in range(1, l):
            if longStr[i] == longStr[idx]:
                idx += 1
                table[i] = idx
            else:
                idx = table[i - 1]
                while idx > 0 and longStr[i] != longStr[idx]:
                    idx = table[idx - 1]
                if longStr[i] == longStr[idx]:
                    idx += 1
                table[i] = idx
        return s[table[l - 1]:][::-1] + s