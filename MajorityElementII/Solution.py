class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        num1 = num2 = cnt1 = cnt2 = 0
        l = len(nums)
        for i in range(0, l):
            if cnt1 != 0 and nums[i] == num1:
                cnt1 += 1
                continue
            if cnt2 != 0 and nums[i] == num2:
                cnt2 += 1
                continue
            if cnt1 == 0:
                num1 = nums[i]
                cnt1 += 1
                continue
            if cnt2 == 0:
                num2 = nums[i]
                cnt2 += 1
                continue
            cnt1 -= 1
            cnt2 -= 1
        if cnt1 == 0:
            num1 = None
        if cnt2 == 0:
            num2 = None
        cnt1 = cnt2 = 0
        for i in range(0, l):
            if nums[i] == num1:
                cnt1 += 1
            if nums[i] == num2:
                cnt2 += 1
        res = []
        if cnt1 > l // 3:
            res.append(num1)
        if cnt2 > l // 3:
            res.append(num2)
        return res
