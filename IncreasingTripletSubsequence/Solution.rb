# @param {Integer[]} nums
# @return {Boolean}
def increasing_triplet(nums)
    n = nums.length
    return false if n < 3
    a = [0, 0]
    a[0] = nums[0]
    1.upto(n - 1) do | i |
        a[0] = nums[i] if a[0] < nums[i]
    end
    a[1] = a[0]
    0.upto(n - 1) do | i |
        if nums[i] <= a[0] then
            a[0] = nums[i]
        elsif nums[i] < a[1] then
            a[1] = nums[i]
        end
        return true if nums[i] > a[0] && nums[i] > a[1]
    end
    return false
end
