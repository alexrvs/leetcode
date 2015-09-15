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
            i = start

            while i <= nowReach:
                canReach = i + nums[i]
                if canReach >= size - 1:
                    return jumps
                if canReach > reachable:
                    reachable = canReach
                i += 1

            start = nowReach + 1

        return 0
