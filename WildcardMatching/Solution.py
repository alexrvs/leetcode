class Solution(object):
    def getCharAt(self, str, i):
        l = len(str)
        if i < l:
            return str[i]
        return ' '

    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        l1 = len(s)
        l2 = len(p)
        i = 0
        j = 0
        starIdx = 0
        saveIdx = 0
        star = False
        while i < l1:
            if self.getCharAt(p, j) == '?':
                i += 1
                j += 1
            elif self.getCharAt(p, j) == '*':
                while self.getCharAt(p, j) == '*':
                    j += 1
                starIdx = j
                saveIdx = i
                star = True
            else:
                if self.getCharAt(s, i) == self.getCharAt(p, j):
                    i += 1
                    j += 1
                else:
                    if star == True:
                        j = starIdx
                        saveIdx += 1
                        i = saveIdx
                    else:
                        return False
        while self.getCharAt(p, j) == '*':
            j += 1
        return (i == l1 and j == l2)
