# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search_insert(nums, target)
    size = nums.length
    l = 0
    r = size
    while l < r do
        m = l + (r - l) / 2
        if nums[m] < target then
            l = m + 1
        else
            r = m
        end
    end
    return l
end
