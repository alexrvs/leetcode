# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
    size = nums.length
    return 0  if size == 0
    return nums[0] if size == 1
    i = 1
    while i < size
        pred = i > 4 ? i - 4 : 0
        j = pred
        max = nums[i]
        while j < i - 1
            sum = nums[i] + nums[j]
            max = sum if max < sum
            j += 1
        end
        nums[i] = max
        i += 1
    end
    return nums[size - 1] > nums[size - 2] ? nums[size - 1] : nums[size - 2]
end
