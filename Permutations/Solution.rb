def dfs(nums, idx, used, order, res)
    size = nums.length
    if idx == size then
        r = []
        order.each do | i |
            r << nums[i]
        end
        res << r
        return
    end
    i = 0
    while i < size do
        if used[i] == 0 then
            used[i] = 1
            order[idx] = i
            dfs(nums, idx + 1, used, order, res)
            used[i] = 0
            i += 1 while i + 1 < size && nums[i] == nums[i + 1]
        end
        i += 1
    end
end

# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
    size = nums.length
    used = Array.new(size, 0)
    order = Array.new(size, 0)
    res = []
    nums.sort!
    dfs(nums, 0, used, order, res)
    return res
end
