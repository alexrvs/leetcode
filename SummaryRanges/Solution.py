class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        ranges = []
        r = ""
        l = len(nums)
        if l <= 0:
            return ranges
        start = nums[0]
        for i in list(range(1, l)):
            if nums[i] != nums[i-1]+1:
                if nums[i-1] == start:
                    r = str(start)
                else:
                    r = str(start) + "->" + str(nums[i-1])
                ranges.append(r)
                start = nums[i]
        if nums[l-1] == start:
            r = str(start)
        else:
            r = str(start) + "->" + str(nums[l-1])
        ranges.append(r)
        return ranges
        
