# @param {Integer} num
# @return {Integer[]}
def count_bits(num)
    res = [ 0 ]
    n = 1
    1.upto(num) do | i |
        n <<= 1 if i - n >= n
        res << 1 + res[i - n]
    end
    return res
end
