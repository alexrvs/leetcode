class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        res = []
        resStr = ""
        if num < 0:
            resStr += "-"
            num = -num
        l = len(res)
        while l == 0 or num != 0:
            res.append(num % 7)
            num = num / 7
            l = len(res)
        for i in range(l - 1, -1, -1):
            resStr += str(res[i])
        return resStr