class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        zero = "0"
        l1 = len(num1)
        l2 = len(num2)
        n1 = [ 0 ] * l1
        n2 = [ 0 ] * l2
        num = [ 0 ] * (l1 + l2)
        for i in range(0, l1):
            n1[i] = int(num1[i])
        for i in range(0, l2):
            n2[i] = int(num2[i])
        if n1[0] == 0 or n2[0] == 0:
            return zero
        for i in range(0, l1):
            for j in range(0, l2):
                num[i + j + 1] += n1[i] * n2[j]
        for i in range(l1 + l2 - 1, -1, -1):
            if i > 0:
                num[i - 1] += num[i] / 10
            num[i] %= 10
        res = ""
        if num[0] != 0:
            res += str(num[0])
        for i in range(1, l1 + l2):
            res += str(num[i])
        return res
