class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        major = nums[0]
        c = 1
        for i in range(1, len(nums)):
            if c != 0:
                if major != nums[i]:
                    c -= 1
                else:
                    c += 1
            else:
                major = nums[i]
                c = 1
        return major
