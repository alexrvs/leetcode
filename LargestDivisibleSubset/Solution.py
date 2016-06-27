class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l = len(nums)
        list.sort(nums)
        steps = [ 1 ] * l
        idx = [ 0 ] * l
        maxIdx = 0
        maxStep = 0
        for i in range(0, l):
            steps[i] = 1
            idx[i] = i
            if maxStep < steps[i]:
                maxStep = steps[i]
                maxIdx = i
            for j in range(i - 1, -1, -1):
                if nums[i] % nums[j] == 0:
                    steps[i] = steps[j] + 1
                    idx[i] = j
                    if maxStep < steps[i]:
                        maxStep = steps[i]
                        maxIdx = i
                    break
        res = [ 0 ] * maxStep
        while maxStep != 0:
            maxStep -= 1
            res[maxStep] = nums[maxIdx]
            maxIdx = idx[maxIdx]
        return res
