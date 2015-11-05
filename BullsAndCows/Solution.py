class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        s = [0] * 10
        g = [0] * 10
        l = len(secret)
        b = 0
        for i in range(0, l):
            if secret[i] == guess[i]:
                b += 1
            s[int(secret[i])] += 1
            g[int(guess[i])] += 1
        c = 0
        for i in range(0, 10):
            if s[i] < g[i]:
                c += s[i]
            else:
                c += g[i]
        c -= b
        res = str(b) + "A" + str(c) + "B"
        return res
