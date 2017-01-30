class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        res = []
        for i in range(area, 0, -1):
            if area % i == 0:
                w = i
                l = area / i
                if w <= l:
                    res.append(l)
                    res.append(w)
                    return res
        return res