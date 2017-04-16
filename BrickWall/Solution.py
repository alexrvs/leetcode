class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        r = len(wall)
        if r == 0:
            return 0
        sumCnt = {}
        max = 0
        for i in range(0, r):
            sum = 0
            c = len(wall[i])
            for j in range(0, c - 1):
                sum += wall[i][j]
                if not sum in sumCnt:
                    sumCnt[sum] = 1
                else:
                    sumCnt[sum] += 1
                if max < sumCnt[sum]:
                    max = sumCnt[sum]
        return r - max