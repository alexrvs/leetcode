class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        aCnt = 0
        lCnt = 0
        l = len(s)
        for i in range(0, l):
            if s[i] == 'A':
                lCnt = 0
                aCnt += 1
                if aCnt > 1:
                    return False
            elif s[i] == 'L':
                lCnt += 1
                if lCnt > 2:
                    return False
            else:
                lCnt = 0
        return True