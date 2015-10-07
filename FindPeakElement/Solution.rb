# @param {Integer[]} nums
# @return {Integer}
def find_peak_element(nums)
    size = nums.length
    return 0 if size < 2
    i = 0
    nums.each_with_index do |n, i|
        return i if i == 0 && nums[i] > nums[i + 1]
        return i if i == size - 1 && nums[i - 1] < nums[i]
        return i if nums[i - 1] < nums[i] && nums[i] > nums[i + 1]
    end
    return 0
end
