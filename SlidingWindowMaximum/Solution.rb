# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer[]}
def max_sliding_window(nums, k)
    can = Array.new(k)
    first = 0
    last = -1
    size = 0
    l = nums.length
    res = []
    nums.each_with_index do | n, i|
        if size != 0 && can[first] < i - k + 1 then
            first = (first + 1) % k
            size -= 1
        end
        while size != 0 && nums[can[last]] < nums[i] do
            last = (last + k - 1) % k
            size -= 1
        end
        last = (last + 1) % k
        can[last] = i
        size += 1
        if (i >= k - 1) then
            res << nums[can[first]]
        end
    end
    return res
end
