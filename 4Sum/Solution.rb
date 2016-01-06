def helper(nums, target, f, s, res)
    l = s + 1
    r = nums.length - 1
    while l < r do
        sum = nums[f] + nums[s] + nums[l] + nums[r]
        if sum < target then
            l += 1
        elsif sum > target then
            r -= 1
        else
            path = []
            path << nums[f]
            path << nums[s]
            path << nums[l]
            path << nums[r]
            res << path
            l += 1
            while l < r && nums[l - 1] == nums[l] do
                l += 1
            end
        end
    end
end

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[][]}
def four_sum(nums, target)
    l = nums.length
    res = []
    i = 0
    nums.sort!
    while i < l - 3 do
        j = i + 1
        while j < l - 2 do
            helper(nums, target, i, j, res)
            j += 1
            while j < l && nums[j - 1] == nums[j] do
                j += 1
            end
        end
        i += 1
        while i < l && nums[i - 1] == nums[i] do 
            i += 1
        end
    end
    return res
end
