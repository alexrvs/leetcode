class Solution(object):
    def dfs(self, nums, idx, used, order, res):
        size = len(nums)
        if idx == size:
            r = []
            for i in range(0, size):
                r.append(nums[order[i]])
            res.append(r)
            return
        i = 0
        while i < size:
            if used[i] == 0:
                used[i] = 1
                order[idx] = i
                self.dfs(nums, idx + 1, used, order, res)
                used[i] = 0
                while i + 1 < size and nums[i] == nums[i + 1]:
                    i += 1
            i += 1

    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        size = len(nums)
        used = [ 0 ] * size
        order = [ 0 ] * size
        res = []
        list.sort(nums)
        self.dfs(nums, 0, used, order, res)
        return res
