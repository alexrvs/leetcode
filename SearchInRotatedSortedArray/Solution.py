class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        size = len(nums)
        l = 0 
        r = size
        while l < r:
            m = l + (r - l) // 2
            if nums[m] >= nums[0]:
                l = m + 1
            else:
                r = m
        r = l - 1
        l %= size
        while l != r:
            m = (l + ((r - l + size) % size) // 2) % size
            if nums[m] < target:
                l = (m + 1) % size
            else:
                r = m
        if nums[l] == target:
            return l
        return -1
