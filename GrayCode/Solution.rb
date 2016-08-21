# @param {Integer} n
# @return {Integer[]}
def gray_code(n)
    res = []
    if n == 0 then
        res << 0
        return res
    end
    num = 1
    n -= 1
    while n > 0 do
        num <<= 1
        num |= 0x1
        n -= 1
    end
    mask = 1
    idx = 0
    0.upto(num) do | i |
        if i < 2 then
            res << i
        else
            if mask << 1 == i then
                mask <<= 1
                idx = i - 1
            end
            res << (mask | res[idx])
            idx -= 1
        end
    end
    return res
end
