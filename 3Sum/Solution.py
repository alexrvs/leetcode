class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        l = len(nums)
        if l < 3:
            return res
        list.sort(nums)
        i = 0
        while i < l - 2:
            j = i + 1
            k = l - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:
                    r = []
                    r.append(nums[i])
                    r.append(nums[j])
                    r.append(nums[k])
                    res.append(r)
                    prev = nums[j]
                    while j < k and nums[j] == prev:
                        j += 1
                elif sum < 0:
                    prev = nums[j]
                    while j < k and nums[j] == prev:
                        j += 1
                else:
                    prev = nums[k]
                    while j < k and nums[k] == prev:
                        k -= 1
            prev = nums[i]
            while i < l and nums[i] == prev:
                i += 1
        return res
