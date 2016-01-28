class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l == 0:
            return 0
        sum = nums[0]
        max = sum
        for i in range(1, l):
            sum += nums[i]
            if sum < nums[i]:
                sum = nums[i]
            if max < sum:
                max = sum
        return max
