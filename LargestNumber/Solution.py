def compDigs(d1, d2):
    s1 = str(d1) + str(d2)
    s2 = str(d2) + str(d1)
    if s1 < s2:
        return -1
    elif s1 > s2:
        return 1
    return 0

class Solution(object):
    def compDigs(self, d1, d2):
        s1 = str(d1) + str(d2)
        s2 = str(d2) + str(d1)
        if s1 < s2:
            return -1
        elif s1 > s2:
            return 1
        return 0

    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        l = len(nums)
        nums.sort(compDigs)
        s = ""
        isZero = True
        for i in range(0, l):
            if nums[l - 1 - i] > 0:
                isZero = False
            s += str(nums[l - 1 - i])
        if isZero == True:
            return "0"
        return s
