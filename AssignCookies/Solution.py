class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        list.sort(g)
        list.sort(s)
        gi = len(g) - 1
        si = len(s) - 1
        cnt = 0
        while gi >= 0 and si >= 0:
            if g[gi] <= s[si]:
                cnt += 1
                si -= 1
            gi -= 1
        return cnt