# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
    size = nums.length
    cur = 0
    nums.each do |n|
        if n != 0
           nums[cur] = n
           cur += 1
        end
    end
    while cur < size
        nums[cur] = 0
        cur += 1
    end
    return
end
