class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        n = len(nums)
        l = 0
        r = n
        while l < r:
            m = l + (r - l) // 2
            if nums[m] < target:
                l = m + 1
            else:
                r = m
        if l == n or nums[l] != target:
            return [-1, -1]
        res = []
        res.append(l)
        l = 0
        r = n
        while l < r:
            m = l + (r - l) // 2
            if nums[m] <= target:
                l = m + 1
            else:
                r = m
        res.append(l - 1)
        return res
