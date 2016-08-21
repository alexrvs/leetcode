class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = []
        if n == 0:
            res.append(0)
            return res
        num = 1
        for i in range(1, n):
            num <<= 1
            num |= 0x1
        mask = 1
        idx = 0
        for i in range(0, num + 1):
            if i < 2:
                res.append(i)
            else:
                if mask << 1 == i:
                    mask <<= 1
                    idx = i - 1
                res.append(mask | res[idx])
                idx -= 1
        return res
