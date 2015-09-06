class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        l = len(citations)
        for i in list(range(0, l)):
            cnt = l - i
            if citations[i] >= cnt:
                return cnt
        return 0
