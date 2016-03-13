class Solution(object):
    def helper(self, nums, start, end):
        l = len(nums)
        sums = [ 0 ] * l
        max = 0
        for i in range(start, end + 1):
            if i - 3 >= start:
                if max < nums[i] + sums[i - 3]:
                    max = nums[i] + sums[i - 3]
            if i - 2 >= start:
                if max < nums[i] + sums[i - 2]:
                    max = nums[i] + sums[i - 2]
            if max < nums[i]:
                max = nums[i]
            sums[i] = max
        return max

    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l == 1:
            return nums[0]
        m1 = self.helper(nums, 0, l - 2)
        m2 = self.helper(nums, 1, l - 1)
        if m1 > m2:
            return m1
        return m2

