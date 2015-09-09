class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        l = len(citations)
        cnt = [ 0 ] * (l + 1)
        for i in list(range(0, l)):
            if citations[i] > l - 1:
                cnt[l] += 1
            else:
                cnt[citations[i]] += 1
        if cnt[l] >= l:
            return l
        i = l - 1
        while i >= 0:
            cnt[i] += cnt[i + 1]
            if cnt[i] >= i:
                return i
            i -= 1
        return 0
