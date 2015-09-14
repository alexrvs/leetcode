class Solution(object):
    def reverseArray(self, nums, i, j):
        while i < j:
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp
            i += 1
            j -= 1
        return

    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        k = k%size
        if k > 0:
            self.reverseArray(nums, 0, size - 1)
            self.reverseArray(nums, 0, k - 1)
            self.reverseArray(nums, k, size - 1)
        return
