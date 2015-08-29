# @param {Integer[]} nums
# @return {String[]}
def summary_ranges(nums)
    ranges = []
    if nums.length == 0
        return ranges
    end
    start = nums[0]
    i = 1
    while i < nums.length
        if nums[i] != nums[i-1] + 1
            if nums[i-1] == start
                range = start.to_s
            else
                range = start.to_s + "->" + nums[i-1].to_s
            end
            ranges << range
            start = nums[i]
        end
        i += 1
    end
    if nums.last == start
        range = start.to_s
    else
        range = start.to_s + "->" + nums.last.to_s
    end
    ranges << range
    return ranges
end
