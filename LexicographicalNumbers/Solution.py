class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        cur = 1
        idx = 1
        res = []
        while idx <= n:
            idx += 1
            res.append(cur)
            if cur * 10 <= n:
                cur *= 10
            elif cur + 1 <= n and cur % 10 != 9:
                cur += 1
            else:
                while (cur / 10) % 10 == 9:
                    cur /= 10
                cur = cur / 10 + 1
        return res