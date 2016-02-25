class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        un = [1]
        k = len(primes)
        idx = [0] * k
        cnt = 0
        while cnt < n:
            minNum = -1
            minIdx = -1
            for i in range(0, k):
                num = primes[i] * un[idx[i]]
                if minNum == -1 or num < minNum:
                    minNum = num
                    minIdx = i
            un.append(minNum)
            for i in range(0, k):
                num = primes[i] * un[idx[i]]
                if minNum == num:
                    idx[i] += 1
            cnt += 1
        return un[n - 1]

