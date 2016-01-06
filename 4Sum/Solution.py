class Solution(object):
    def helper(self, nums, target, f, s, res):
        l = s + 1
        r = len(nums) - 1
        while l < r:
            sum = nums[f] + nums[s] + nums[l] + nums[r]
            if sum < target:
                l += 1
            elif sum > target:
                r -= 1
            else:
                path = []
                path += nums[f],
                path += nums[s],
                path += nums[l],
                path += nums[r],
                res += path,
                l += 1
                while l < r and nums[l - 1] == nums[l]:
                    l += 1

    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        l = len(nums)
        res = []
        list.sort(nums)
        i = 0
        while i < l - 3:
            if i + 4 < l and nums[i + 4] == nums[i + 3] and \
            nums[i + 3] == nums[i + 2] and nums[i + 2] == nums[i + 1] and nums[i + 1] == nums[i]:
                i += 1
                continue
            j = i + 1
            while j < l - 2:
                self.helper(nums, target, i, j, res)
                j += 1
                while j < l and nums[j - 1] == nums[j]:
                    j += 1
            i += 1
            while i < l and nums[i - 1] == nums[i]:
                i += 1
        return res
