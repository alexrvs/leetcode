# @param {Integer} n, a positive integer
# @return {Integer}
def hamming_weight(n)
    mask = 0x0001
    num = 0
    i = 0
    while i < 32
        num += 1 if (n & mask) != 0
        mask = mask << 1
        i += 1
    end
    return num
end
