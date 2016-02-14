# @param {Integer} n
# @return {Integer}
def num_trees(n)
    nums = Array.new(n + 1, 0)
    nums[0] = 1
    1.upto(n) do | i |
        1.upto(i) do | j |
            nums[i] += nums[j - 1] * nums[i - j]
        end
    end
    return nums[n]
end
