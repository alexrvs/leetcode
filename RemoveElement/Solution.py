class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        cur = 0
        i = 0
        l = len(nums)
        while i < l:
            if nums[i] != val:
                nums[cur] = nums[i]
                cur += 1
            i += 1
        return cur
