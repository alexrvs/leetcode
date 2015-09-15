class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        if size == 1:
            return 0
        reachable = 0
        start = 0
        jumps = 0
        while start <=  reachable:
            jumps += 1
            nowReach = reachable

            while start <= nowReach:
                canReach = start + nums[start]
                if canReach >= size - 1:
                    return jumps
                if canReach > reachable:
                    reachable = canReach
                start += 1

        return 0
