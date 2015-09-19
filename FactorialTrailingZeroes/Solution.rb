# @param {Integer} n
# @return {Integer}
def trailing_zeroes(n)
    zeroes = 0
    while n > 0
        n = n/5
        zeroes += n
    end
    return zeroes
end
