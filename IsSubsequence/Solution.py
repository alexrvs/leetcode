class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        sl = len(s)
        tl = len(t)
        if sl == 0:
            return True
        idx = 0
        for i in range(0, tl):
            if t[i] == s[idx]:
                idx += 1
                if idx == sl:
                    return True
        return False
