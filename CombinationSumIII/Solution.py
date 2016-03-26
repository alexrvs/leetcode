class Solution(object):
    def helper(self, k, path, idx, sum, res):
        if k < 0 or sum < 0:
            return
        if k == 0 and sum == 0:
            res.append(list(path))
            return
        for i in range(idx, 10):
            path.append(i)
            self.helper(k - 1, path, i + 1, sum - i, res)
            path.pop()

    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        path = []
        self.helper(k, path, 1, n, res)
        return res
