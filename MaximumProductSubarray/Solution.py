class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = nums[0]
        tmax = nums[0]
        tmin = nums[0]
        for i in range(1, len(nums)):
            prod1 = tmax * nums[i]
            prod2 = tmin * nums[i]
            tmax = max(max(prod1, prod2), nums[i])
            tmin = min(min(prod1, prod2), nums[i])
            res = max(tmax, res)
        return res
