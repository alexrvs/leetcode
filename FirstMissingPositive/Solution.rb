# @param {Integer[]} nums
# @return {Integer}
def first_missing_positive(nums)
    l = nums.length
    i = 0
    while i < l do
        cur = nums[i]
        while cur >= 1 && cur <= l && nums[cur - 1] != cur do
            tmp = nums[cur - 1]
            nums[cur - 1] = cur
            cur = tmp
        end
        i += 1
    end
    i = 0
    while i < l do
        if nums[i] != i + 1 then
            return i + 1
        end
        i += 1
    end
    return l + 1
end
