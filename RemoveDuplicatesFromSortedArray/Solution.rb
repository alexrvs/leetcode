# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
    size = nums.length
    return size if size <= 1
    last_value = nums[0]
    new_size = 1
    nums.each_with_index do |n, i|
        if i > 0 && n != last_value
            last_value = n
            nums[new_size] = n
            new_size += 1
        end
    end
    return new_size
end
