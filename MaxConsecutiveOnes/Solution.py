class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = 0
        max = 0
        l = len(nums)
        for i in range(0, l):
            if nums[i] == 0:
                cnt = 0
            else:
                cnt += 1
                if max < cnt:
                    max = cnt
        return max