# @param {Integer[]} nums
# @return {Integer[]}
def product_except_self(nums)
    size = nums.length
    res = [1]
    i = 1
    while i < size do
        res << res[i - 1] * nums[i - 1]
        i += 1
    end
    i = size - 1
    prod = 1
    while i >= 0 do
        res[i] *= prod
        prod *= nums[i]
        i -= 1
    end
    return res
end
