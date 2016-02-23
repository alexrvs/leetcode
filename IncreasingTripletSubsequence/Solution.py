class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if n < 3:
            return False
        a = [0, 0]
        a[0] = nums[0]
        for i in range(1, n):
            if a[0] < nums[i]:
                a[0] = nums[i]
        a[1] = a[0]
        for i in range(0, n):
            if nums[i] <= a[0]:
                a[0] = nums[i]
            elif nums[i] < a[1]:
                a[1] = nums[i]
            if nums[i] > a[0] and nums[i] > a[1]:
                return True
        return False
