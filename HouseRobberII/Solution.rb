def helper(nums, start, stop)
    l = nums.length
    sums = Array.new(l, 0)
    max = 0
    i = start
    while i <= stop do
        if i - 3 >= start then
            max = nums[i] + sums[i - 3] if max < nums[i] + sums[i - 3] 
        end
        if i - 2 >= start then
            max = nums[i] + sums[i - 2] if max < nums[i] + sums[i - 2] 
        end
        max = nums[i] if max < nums[i]
        sums[i] = max
        i += 1
    end
    return max
end
# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
    l = nums.length
    return nums[0] if l == 1
    m1 = helper(nums, 0, l - 2)
    m2 = helper(nums, 1, l - 1)
    return m1 if m1 > m2
    return m2
end
