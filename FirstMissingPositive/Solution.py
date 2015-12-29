class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        for i in range(0, l):
            cur = nums[i]
            while cur >= 1 and cur <= l and nums[cur - 1] != cur:
                tmp = nums[cur - 1]
                nums[cur - 1] = cur
                cur = tmp
        for i in range(0, l):
            if nums[i] != i + 1:
                return i + 1
        return l + 1
