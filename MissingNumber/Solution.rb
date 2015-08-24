# @param {Integer[]} nums
# @return {Integer}
def missing_number(nums)
    x = 0
    nums.each_with_index{|num, i| 
        x ^= num
        x ^= i
    }
    x ^= nums.size
    return x
end

nums = [3, 0, 2]
puts missing_number(nums)
