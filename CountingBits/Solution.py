class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        res = [ 0 ]
        if num == 0:
            return res
        n = 1
        for i in range(1, num + 1):
            if i - n >= n:
                n += n
            res.append(res[i - n] + 1)
        return res
