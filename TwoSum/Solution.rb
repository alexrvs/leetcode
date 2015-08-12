# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  nums.each_with_index do | num, i |
    lookup = target - num
    if nums.include?(lookup) && i != nums.index(lookup)
      return [i+1, nums.index(lookup)+1].sort
    end
  end
end
