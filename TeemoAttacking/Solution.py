class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        l = len(timeSeries)
        if l == 0:
            return 0
        res = duration
        for i in range(1, l):
            diff = timeSeries[i] - timeSeries[i - 1]
            if diff < duration:
                res += diff
            else:
                res += duration
        return res