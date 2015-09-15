class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        size = len(nums)
        if size == 0:
            return False
        i = 0
        reachable = nums[0]
        while i < size and i <= reachable:
            if i == size - 1:
                return True
            canReach = i + nums[i]
            if canReach > reachable:
                reachable = canReach
            i += 1

        return False
