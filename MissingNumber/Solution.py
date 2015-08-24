class Solution(object):
  def missingNumber(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    x = nums[0]
    l = len(nums)
    for i in list(range(1, l)):
      x ^= nums[i]
    l += 1
    for i in list(range(0, l)):
      x ^= i 
    return x

