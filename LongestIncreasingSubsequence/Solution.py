class Solution(object):
    def search(self, seq, l, r, target):
        while l < r:
            m = l + (r - l) // 2
            if seq[m] < target:
                l = m + 1
            else:
                r = m
        return l

    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        seq = [ 0 ] * n
        seqLen = 0
        for i in range(0, n):
            pos = self.search(seq, 0, seqLen, nums[i])
            seq[pos] = nums[i]
            if pos == seqLen:
                seqLen += 1
        return seqLen
