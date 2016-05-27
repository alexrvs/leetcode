# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
    major = nums[0]
    c = 1
    i = 1
    while i < nums.length do
        if c != 0 then
            if major != nums[i] then
                c -= 1
            else
                c += 1
            end
        else
            major = nums[i]
            c = 1
        end
        i += 1
    end
    return major
end
