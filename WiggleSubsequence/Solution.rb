# @param {Integer[]} nums
# @return {Integer}
def wiggle_max_length(nums)
    size = nums.length
    return size if size <= 1
    comm = nums[0]
    len = 1
    prev = 0
    1.upto(size - 1) do | i |
        if prev <= 0 && nums[i] > comm then
            prev = 1
            len += 1
        elsif prev >= 0 && nums[i] < comm then
            prev = -1
            len += 1
        end
        comm = nums[i]
    end
    return len
end
