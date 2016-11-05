class Solution(object):
    def calStep(self, limit, start, end):
        step = 0;
        while start <= limit:
            if limit + 1 < end:
                step += limit + 1 - start
            else:
                step += end - start
            start *= 10
            end *= 10
        return step
        
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        cur = 1
        k -= 1
        while k > 0:
            step = self.calStep(n, cur, cur + 1)
            if k >= step:
                k -= step
                cur = cur + 1
            else:
                k -= 1
                cur *= 10
        return cur