# @param {Integer[]} nums
# @param {Integer} k
# @return {Void} Do not return anything, modify nums in-place instead.
def reverse(nums, i, j)
    while i < j
        tmp = nums[i]
        nums[i] = nums[j]
        nums[j] = tmp
        i += 1
        j -= 1
    end
    return
end

def rotate(nums, k)
    size = nums.length
    k = k%size
    if k > 0
        reverse(nums, 0, size - 1)
        reverse(nums, 0, k - 1)
        reverse(nums, k, size - 1)
    end
    return
end
