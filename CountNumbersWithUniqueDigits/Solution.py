class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        sum = 0
        temp = 9
        for i in range(0, n + 1):
            if i == 0:
                sum += 1
            elif i == 1:
                sum += 9
            else:
                temp *= max(0, 11 - i)
                sum += temp
        return sum
