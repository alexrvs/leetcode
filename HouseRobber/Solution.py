class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        if size == 0:
            return 0
        if size == 1:
            return nums[0]
        for i in range(1, size):
            pred = i - 4 if i > 4 else 0
            max = nums[i]
            for j in range(pred, i-1):
                sum = nums[i] + nums[j]
                if max < sum:
                    max = sum
            nums[i] = max
        res = nums[size - 1] if nums[size - 1] > nums[size - 2] else nums[size - 2]
        return res
