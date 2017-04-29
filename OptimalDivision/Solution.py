class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        l = len(nums)
        res = str(nums[0])
        if l > 2:
            res += "/(" + str(nums[1])
            for i in range(2, l):
                res += "/" + str(nums[i])
            res += ")"
        elif l > 1:
            res += "/" + str(nums[1])
        return res