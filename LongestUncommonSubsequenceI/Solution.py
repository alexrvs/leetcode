class Solution(object):
    def findLUSlength(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        res = -1
        if a != b:
            la = len(a)
            lb = len(b)
            if res < la:
                res = la
            if res < lb:
                res = lb
        return res