class Solution(object):
    def isSame(self, str, pl, s):
        for i in range(0, pl):
            if str[i] != str[s + i]:
                return False
        return True
        
    def repeatedSubstringPattern(self, str):
        """
        :type str: str
        :rtype: bool
        """
        size = len(str)
        for l in range(1, (size >> 1) + 1):
            if size % l == 0:
                repeated = True
                s = l
                while s < size:
                    if False == self.isSame(str, l, s):
                        repeated = False
                        break
                    s += l
                if True == repeated:
                    return True
        return False