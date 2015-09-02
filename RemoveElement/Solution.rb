# @param {Integer[]} nums
# @param {Integer} val
# @return {Integer}
def remove_element(nums, val)
    cur = 0
    i = 0
    while i < nums.length
        if nums[i] != val
            nums[cur] = nums[i]
            cur += 1
        end
        i += 1
    end
    return cur
end
