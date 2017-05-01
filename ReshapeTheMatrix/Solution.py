class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        res = []
        nums_r = len(nums)
        if nums_r == 0:
            return res
        nums_c = len(nums[0])
        if nums_r * nums_c < r * c:
            return nums
        for i in range(0, r):
            res.append([0] * c)
            for j in range(0, c):
                idx = c * i + j
                res[i][j] = nums[idx / nums_c][idx % nums_c]
        return res