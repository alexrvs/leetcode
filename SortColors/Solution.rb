# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def sort_colors(nums)
    size = nums.length
    cnts = Array.new(3, 0)
    nums.each do |n|
        cnts[n] += 1
    end
    idx = 0
    i = 0
    while i < 3 do
        j = 0
        while j < cnts[i] do
            nums[idx] = i
            idx += 1
            j += 1
        end
        i += 1
    end
    return
end
