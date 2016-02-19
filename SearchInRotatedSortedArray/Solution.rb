# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search(nums, target)
    size = nums.length
    l = 0
    r = size
    while l < r do
        m = l + (r - l) / 2
        if nums[m] >= nums[0] then
            l = m + 1
        else
            r = m
        end
    end
    r = l - 1
    l = l % size
    while l != r do
        m = (l + ((r - l + size) % size) / 2) % size
        if nums[m] < target then
            l = (m + 1) % size
        else
            r = m
        end
    end
    return l if nums[l] == target
    return -1
end
