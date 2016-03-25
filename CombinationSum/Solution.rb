def helper(candidates, path, index, sum, res)
    return if sum < 0
    if sum == 0 then
        res << Array.new(path)
        return
    end
    index.upto(candidates.length - 1) do | i |
        path << candidates[i]
        helper(candidates, path, i, sum - candidates[i], res)
        path.pop
    end
end

# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum(candidates, target)
    res = []
    path = []
    candidates.sort!
    helper(candidates, path, 0, target, res)
    return res
end
