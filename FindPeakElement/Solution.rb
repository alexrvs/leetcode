# @param {Integer[]} nums
# @return {Integer}
def find_peak_element(nums)
    size = nums.length
    return 0 if size < 2
    return 0 if nums[0] > nums[1]
    nums.each_with_index do |n, i|
        return i if i > 0 && i < size - 1 && nums[i - 1] < nums[i] && nums[i] > nums[i + 1]
    end
    return size - 1 if nums[size - 2] < nums[size - 1]
    return 0
end
