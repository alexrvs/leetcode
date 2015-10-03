class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l = len(nums)
        res = [1] * l
        for i in range(1, l):
            res[i] = res[i - 1] * nums[i - 1]
        prod = 1
        for i in range(l - 1, -1, -1):
            res[i] *= prod
            prod *= nums[i]
        return res
