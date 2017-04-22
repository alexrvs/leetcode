class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        mod = 1000000007
        al = []
        al.append([ 0 ] *3)
        al.append([ 0 ] *3)
        al[0][0] = 1
        for i in range(0, n + 1):
            a = (al[0][0] + al[0][1] + al[0][2]) % mod
            al[0][2] = al[0][1]
            al[0][1] = al[0][0]
            al[0][0] = a
            a += al[1][0] + al[1][1] + al[1][2]
            a %= mod
            al[1][2] = al[1][1]
            al[1][1] = al[1][0]
            al[1][0] = a
        return al[1][0]