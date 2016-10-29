class Solution(object):
    def compare(self, sCnt, pCnt):
        l = len(pCnt)
        for i in range(0, l):
            if sCnt[i] != pCnt[i]:
                return False
        return True
        
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        sLen = len(s)
        pLen = len(p)
        if sLen < pLen:
            return res
        pCnt = [ 0 ] * 26
        sCnt = [ 0 ] * 26
        for i in range(0, pLen):
            pCnt[ord(p[i]) - ord('a')] += 1
        for i in range(0, pLen):
            sCnt[ord(s[i]) - ord('a')] += 1
        if True == self.compare(sCnt, pCnt):
            res.append(0)
        for i in range(pLen, sLen):
            sCnt[ord(s[i - pLen]) - ord('a')] -= 1
            sCnt[ord(s[i]) - ord('a')] += 1
            if self.compare(sCnt, pCnt):
                res.append(i - pLen + 1)
        return res