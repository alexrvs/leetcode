class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        can = [ 0 ] * k
        first = 0
        last = -1
        size = 0
        res = []
        l = len(nums)
        for i in range(0, l):
            if size != 0 and can[first] < i - k + 1:
                first = (first + 1) % k
                size -= 1
            while size != 0 and nums[can[last]] < nums[i]:
                last = (last + k - 1) % k
                size -= 1
            last = (last + 1) % k
            can[last] = i
            size += 1
            if i >= k - 1:
                res.append(nums[can[first]])
        return res
