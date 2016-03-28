class Solution(object):
    def addSpaces(self, str, i, n, l, leftJust):
        if n > 0 and i < n:
            spaces = 1
            if leftJust == False:
                spaces = l // n
                if i < l % n:
                    spaces += 1
            while spaces != 0:
                str += " "
                spaces -= 1
        return str

    def connect(self, words, start, end, l, maxWidth, leftJust):
        s = ""
        for i in range(start, end + 1):
            s += self.addSpaces(words[i], i - start, end - start, maxWidth - l, leftJust)
        while len(s) < maxWidth:
            s += " "
        return s

    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        res = []
        n = len(words)
        i = 0
        l = 0
        begin = 0
        while i < n:
            if l + len(words[i]) + (i - begin) > maxWidth:
                res.append(self.connect(words, begin, i - 1, l, maxWidth, False))
                begin = i
                l = 0
            l += len(words[i])
            i += 1
        res.append(self.connect(words, begin, i - 1, l, maxWidth, True))
        return res
        
