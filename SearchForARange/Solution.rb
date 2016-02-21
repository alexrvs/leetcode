# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def search_range(nums, target)
    n = nums.length
    l = 0
    r = n
    while l < r do
        m = l + (r - l) / 2
        if nums[m] < target then
            l = m + 1
        else
            r = m
        end
    end
    if l == n || nums[l] != target then
        return [-1, -1]
    end
    res = []
    res << l
    l = 0
    r = n
    while l < r do
        m = l + (r - l) / 2
        if nums[m] <= target then
            l = m + 1
        else
            r = m
        end
    end
    res << (l - 1)
    return res
end
