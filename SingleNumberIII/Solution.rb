# @param {Integer[]} nums
# @return {Integer[]}
def single_number(nums)
    x = 0
    nums.each do | n |
        x ^= n
    end
    x &= -x
    res = [0, 0]
    nums.each do | n |
        if (x & n) == 0 then
            res[0] ^= n
        else
            res[1] ^= n
        end
    end
    return res
end
