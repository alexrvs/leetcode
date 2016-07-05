import ctypes

class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        bc = ctypes.c_int32(b)
        while bc.value != 0:
            c = ctypes.c_int32(a & bc.value)
            a = a ^ bc.value
            bc.value = c.value << 1
        return a