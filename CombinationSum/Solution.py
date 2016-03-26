class Solution(object):
    def helper(self, candidates, path, index, sum, res):
        if sum < 0:
            return
        if sum == 0:
            res.append(list(path))
            return
        l = len(candidates)
        for i in range(index, l):
            path.append(candidates[i])
            self.helper(candidates, path, i, sum - candidates[i], res)
            path.pop()

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        path = []
        list.sort(candidates)
        self.helper(candidates, path, 0, target, res)
        return res
