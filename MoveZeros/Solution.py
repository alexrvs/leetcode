class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        cur = 0
        for i in range(0, size):
            if nums[i] != 0:
                nums[cur] = nums[i]
                cur += 1
        for i in range(cur, size):
            nums[i] = 0
        return
