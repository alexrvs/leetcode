# @param {Integer[]} nums
# @return {Boolean}
def can_jump(nums)
    size = nums.length
    return false if size == 0
    i = 0
    reachable = nums[i]
    while i < size && i <= reachable
        return true if i == size - 1
        can_reach = i + nums[i]
        reachable = can_reach if reachable < can_reach
        i += 1
    end
    return false
end
