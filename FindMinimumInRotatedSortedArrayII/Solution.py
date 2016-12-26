class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        if size == 0:
            return 0
        l = 0
        r = size - 1
        m = 0
        while l < r:
            m = l + ((r - l) >> 1)
            if nums[r] < nums[m]:
                l = m + 1
            elif nums[m] < nums[r]:
                r = m
            else:
                if nums[l] == nums[m]:
                    l += 1
                    r -= 1
                else:
                    r = m
        return nums[r]