class Solution(object):
    def inOneRow(self, word, capRow):
        l = len(word)
        expect = 0
        for i in range(0, l):
            if i == 0:
                expect = capRow[word[i]]
            else:
                if expect != capRow[word[i]]:
                    return False
        return True
        
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        capRow = { 'a':2, 'b':3, 'c':3, 'd':2, 'e':1, 'f':2, 'g':2, 'h':2, 'i':1, 'j':2, 'k':2, 'l':2, 'm':3, 'n':3, 'o':1, 'p':1, 'q':1, 'r':1, 's':2, 't':1, 'u':1, 'v':3, 'w':1, 'x':3, 'y':1, 'z':3 }
        wl = len(words)
        res = []
        for i in range(0, wl):
            if True == self.inOneRow(words[i].lower(), capRow):
                res.append(words[i])
        return res