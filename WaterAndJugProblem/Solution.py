class Solution(object):
    def myGCD(self, x, y):
        if y == 0:
            return x
        else:
            return self.myGCD(y, x % y)

    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        if x == 0 and y == z:
            return True
        if x == z and y == 0:
            return True
        if x == z or y == z:
            return True
        if z > x + y:
            return False
        return (z % self.myGCD(x, y) == 0)
