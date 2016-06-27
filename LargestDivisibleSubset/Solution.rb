# @param {Integer[]} nums
# @return {Integer[]}
def largest_divisible_subset(nums)
    nums.sort!
    l = nums.length
    steps = Array.new(l, 0)
    idx = Array.new(l, 0)
    maxStep = 0
    maxIdx = 0
    l.times do | i |
        steps[i] = 1
        idx[i] = i
        if maxStep < steps[i] then
            maxStep = steps[i]
            maxIdx = i
        end
        j = i - 1
        while j >= 0 do
            if nums[i] % nums[j] == 0 then
                steps[i] = steps[j] + 1
                idx[i] = j
                if maxStep < steps[i] then
                    maxStep = steps[i]
                    maxIdx = i
                end
                break
            end
            j -= 1
        end
    end
    res = [ 0 ] * maxStep
    while maxStep != 0 do
        maxStep -= 1
        res[maxStep] = nums[maxIdx]
        maxIdx = idx[maxIdx]
    end
    return res
end
