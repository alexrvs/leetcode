class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        nums = [ 0 ] * (n + 1)
        nums[0] = 1
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                nums[i] += nums[j - 1] * nums[i - j]
        return nums[n]
