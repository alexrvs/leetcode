class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 3:
            return 0
        l = 0
        while l * l < n:
            l += 1
        nums = [0] * n
        for i in range(2, l + 1):
            if nums[i] != 1:
                j = i * i
                while j < n:
                    nums[j] = 1
                    j += i
        cnt = 0
        for i in range(2, n):
            if nums[i] != 1:
                cnt += 1
        return cnt
