class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l == 0:
            return 0
        noDupIdx = 0
        dup = False
        for i in range(1, l):
            if nums[i] != nums[noDupIdx]:
                dup = False
                noDupIdx += 1
                nums[noDupIdx] = nums[i]
            elif dup == False:
                dup = True
                noDupIdx += 1
                nums[noDupIdx] = nums[i]
        return noDupIdx + 1
