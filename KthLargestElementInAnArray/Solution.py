class Solution(object):
    def heapify(self, heap, k):
        for i in range(k - 1, 0, -1):
            r = (i - 1) // 2
            if heap[r] > heap[i]:
                tmp = heap[r]
                heap[r] = heap[i]
                heap[i] = tmp

    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        self.heapify(nums, k)
        l = len(nums)
        for i in range(k, l):
            if nums[i] > nums[0]:
                tmp = nums[i]
                nums[i] = nums[0]
                nums[0] = tmp
                self.heapify(nums, k)
        return nums[0]

