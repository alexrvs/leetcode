class Solution(object):
    def helper(self, stones, cur, step, target):
        if (cur, step) in self.jumps:
            return False

        if cur == target:
            return True

        if cur > target or cur < 0 or step <= 0 or cur not in stones:
            return False

        for i in [ -1, 0, 1]:
            nextStep = step + i
            if (cur + nextStep) in stones:
                if self.helper(stones, cur + nextStep, nextStep, target):
                    return True

        self.jumps.add((cur, step))
        return False

    def canCross(self, stones):
        self.jumps = set()
        target = stones[-1]
        stones = set(stones)

        res = self.helper(stones, 1, 1, target)
        return res
