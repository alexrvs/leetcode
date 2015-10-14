# @param {Integer} n
# @return {Boolean}
def is_power_of_two(n)
    cnt = 0
    while n > 0 do
        cnt += 1 if n & 0x0001 != 0
        n >>= 1
    end
    return true if cnt == 1 else return false
end
