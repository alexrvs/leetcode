def helper(k, path, idx, sum, res)
    return if k < 0 || sum < 0
    if k == 0 && sum == 0 then
        res << Array.new(path)
        return
    end
    idx.upto(9) do | i |
        path << i
        helper(k - 1, path, i + 1, sum - i, res)
        path.pop
    end
end

# @param {Integer} k
# @param {Integer} n
# @return {Integer[][]}
def combination_sum3(k, n)
    res = []
    path = []
    helper(k, path, 1, n, res)
    return res
end
