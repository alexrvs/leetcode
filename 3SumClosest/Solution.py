class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        res = 0
        l = len(nums)
        if l < 3:
            return res
        list.sort(nums)
        res = nums[0] + nums[1] + nums[2]
        minDist = res - target if target < res else target - res
        for i in range(0, l - 2):
            j = i + 1
            k = l - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == target:
                    return sum
                elif sum < target:
                    if target - sum < minDist:
                        minDist = target - sum
                        res = sum
                    j += 1
                else:
                    if sum - target < minDist:
                        minDist = sum - target
                        res = sum
                    k -= 1
        return res
