# @param {Integer[]} nums
# @return {Integer}
def find_min(nums)
    l = 0
    r = nums.length
    while l < r do
        m = l + (r - l) / 2
        if nums[m] >= nums[0] then
            l = m + 1
        else
            r = m
        end
    end
    return nums[0] if l >= nums.length
    return nums[l]
end
