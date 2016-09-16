class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        total = 0
        sum = 0
        l = len(A)
        for i in range(0, l):
            total += A[i]
            sum += i * A[i]
        max = sum
        for i in range(1, l):
            sum += total - l * A[l - i]
            if sum > max:
                max = sum
        return max
