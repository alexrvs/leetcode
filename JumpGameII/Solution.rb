# @param {Integer[]} nums
# @return {Integer}
def jump(nums)
    size = nums.length
    return 0 if size == 1
    jumps = 0
    reachable = 0
    from = 0
    while from <= reachable
        jumps += 1
        now_reach = reachable
        while from <= now_reach
            can_reach = from + nums[from]
            return jumps if can_reach >= size - 1
            reachable = can_reach if can_reach > reachable
            from += 1
        end
    end
    return 0
end
