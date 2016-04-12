# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
    l = nums.length
    return l if l == 0
    dup = false
    noDupIdx = 0
    1.upto(l - 1) do | i |
        if nums[i] != nums[noDupIdx] then
            dup = false
            noDupIdx += 1
            nums[noDupIdx] = nums[i]
        elsif dup == false then
            dup = true
            noDupIdx += 1
            nums[noDupIdx] = nums[i]
        end
    end
    return noDupIdx + 1
end
