class Solution(object):
    def helper(self, res, str, a, b):
        if a == 0 and b == 0:
            res.append(str)
        elif a == 0:
            self.helper(res, str + ")", a, b - 1)
        else:
            self.helper(res, str + "(", a - 1, b)
            if a < b:
                self.helper(res, str + ")", a, b - 1)
        return

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        str = ""
        self.helper(res, str, n, n)
        return res
