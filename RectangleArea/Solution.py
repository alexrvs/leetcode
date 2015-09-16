class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        area1 = (C - A) * (D - B)
        area2 = (G - E) * (H - F)
        inL = A if A > E else E
        inR = C if C < G else G
        inB = B if B > F else F
        inT = D if D < H else H
        inW = inR - inL if inR > inL else 0
        inH = inT - inB if inT > inB else 0
        return area1 + area2 - (inW * inH)
