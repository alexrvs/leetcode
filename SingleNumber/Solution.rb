# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  nums.each_with_index do | r, i | if i > 0 then nums[0] ^= nums[i] end end
  return nums[0]
end
