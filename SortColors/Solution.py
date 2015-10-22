class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        cnts = [0] * 3
        for i in range(0, l):
            cnts[nums[i]] += 1
        idx = 0
        for i in range(0, 3):
            for j in range(0, cnts[i]):
                nums[idx] = i
                idx += 1
        return
