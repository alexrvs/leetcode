class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        res = ""
        l = len(strs)
        if l == 0:
            return res
        if l == 1:
            return strs[0]
        l0 = len(strs[0])
        idx = 0
        while idx < l0:
            c = strs[0][idx]
            for i in range(1, l):
                ls = len(strs[i])
                if idx >= ls or strs[i][idx] != c:
                    return res
                if i == l - 1:
                    res += c
            idx += 1
        return res
