class Solution(object):
    def magicalString(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        if n <= 3:
            return 1
        magicStr = "122"
        i = 2
        l = 3
        while l < n:
            c = magicStr[l - 1]
            if magicStr[i] == '2':
                if c == '2':
                    magicStr += "11"
                else:
                    magicStr += '22'
            else:
                if c == '2':
                    magicStr += "1"
                else:
                    magicStr += "2"
            l = len(magicStr)
            i += 1
        cnt = 0
        for i in range(0, n):
            if magicStr[i] == '1':
                cnt += 1
        return cnt