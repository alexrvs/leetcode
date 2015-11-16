class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        m1 = {}
        m2 = {}
        l = len(s)
        for i in range(0, l):
            cs = s[i]
            ct = t[i]
            if cs in m1:
                if ct != m1[cs]:
                    return False
            else:
                m1[cs] = ct
            if ct in m2:
                if cs != m2[ct]:
                    return False
            else:
                m2[ct] = cs
        return True
