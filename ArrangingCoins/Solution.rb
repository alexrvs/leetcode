# @param {Integer} n
# @return {Integer}
def arrange_coins(n)
    l = 1
    while n >= l do
        n -= l
        l += 1
    end
    return l - 1
end