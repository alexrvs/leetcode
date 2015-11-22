# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def range_bitwise_and(m, n)
    i = 0
    while m != n do
        m = m >> 1
        n = n >> 1
        i += 1
    end
    return n << i
end
