def helper(candidates, path, index, sum, res)
    return if sum < 0
    if sum == 0 then
        res << Array.new(path)
        return
    end
    prev = 0
    index.upto(candidates.length - 1) do | i |
        next if candidates[i] == prev
        path << candidates[i]
        helper(candidates, path, i + 1, sum - candidates[i], res)
        path.pop
        prev = candidates[i]
    end
end

# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum2(candidates, target)
    res = []
    path = []
    candidates.sort!
    helper(candidates, path, 0, target, res)
    return res
end
