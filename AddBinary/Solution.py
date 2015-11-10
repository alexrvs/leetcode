class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        al = len(a)
        bl = len(b)
        if al < bl:
            l = bl;
        else:
            l = al;
        d = []
        c = 0
        res = ""
        for i in range(0, l):
            da = 0
            if al - 1 - i >= 0:
                da = int(a[al - 1 - i])
            db = 0
            if bl - 1 - i >= 0:
                db = int(b[bl - 1 - i])
            d.append((da + db + c) % 2)
            c = (da + db + c) / 2
        if c == 1:
            res += "1"
        for i in range(0, l):
            res += str(d[l - 1 - i])
        return res
