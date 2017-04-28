class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        list.sort(nums)
        l = len(nums)
        i = 0
        sum = 0
        while i < l:
            sum += nums[i]
            i += 2
        return sum