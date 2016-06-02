# @param {Integer[]} nums
# @return {Integer}
def max_product(nums)
    res = nums[0]
    tmax = nums[0]
    tmin = nums[0]
    i = 1
    while i < nums.length do
        prod1 = tmax * nums[i]
        prod2 = tmin * nums[i]
        tmax = [[prod1, prod2].max, nums[i]].max
        tmin = [[prod1, prod2].min, nums[i]].min
        res = [tmax, res].max
        i += 1
    end
    return res
end
