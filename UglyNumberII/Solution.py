class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        uglyNums = [1]
        i2 = i3 = i5 = 0
        while len(uglyNums) < n:
            num2 = uglyNums[i2]*2
            num3 = uglyNums[i3]*3
            num5 = uglyNums[i5]*5
            min_num = min(num2, num3, num5)
            uglyNums.append(min_num)
            if min_num == num2:
                i2 += 1
            if min_num == num3:
                i3 += 1
            if min_num == num5:
                i5 += 1

        return uglyNums[n-1]
