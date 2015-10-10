class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        pLen = len(pattern)
        words = str.split()
        wLen = len(words)
        if pLen != wLen:
            return False
        d = {}
        for i in range(0, pLen):
            c = pattern[i]
            if c in d:
                if d[c] != words[i]:
                    return False
            else:
                if words[i] in list(d.values()):
                    return False
                d[c] = words[i]

        return True
