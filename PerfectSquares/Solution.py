class Solution(object):
    def numSquares(self, n):
        d1 = {}
        i = 1
        while i * i <= n:
            d1[i*i] = 1
            i += 1
        if n in d1:
            return 1
        d2 = {}
        for i in d1:
            for j in d1:
                d2[i+j] = 2
        if n in d2:
            return 2
        for i in d1:
            if n - i in d2:
                return 3
        return 4
