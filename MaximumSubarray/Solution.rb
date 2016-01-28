# @param {Integer[]} nums
# @return {Integer}
def max_sub_array(nums)
    l = nums.length
    return 0 if l == 0
    sum = nums[0]
    max = sum
    1.upto(l - 1) do |i|
        sum += nums[i]
        sum = nums[i] if sum < nums[i]
        max = sum if max < sum
    end
    return max
end
