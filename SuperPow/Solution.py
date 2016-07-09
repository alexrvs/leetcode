class Solution(object):
    def helper(self, e, p):
        res = 1
        while p > 0:
            if p % 2 == 1:
                res *= e
            p >>= 1
            e = (e * e) % 1337
        return res

    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        res = 1
        a %= 1337
        l = len(b)
        for i in range(l - 1, -1, -1):
            res = (res * self.helper(a, b[i])) % 1337
            a = self.helper(a, 10)
        return res
