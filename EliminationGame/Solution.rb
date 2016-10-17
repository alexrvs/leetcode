# @param {Integer} n
# @return {Integer}
def last_remaining(n)
    start = 1
    diff = 1
    time = 1
    while n > 1 do
        if time % 2 == 1 || n % 2 == 1 then
            start += diff
        end
        time += 1
        n -= (n + 1) >> 1
        diff <<= 1
    end
    return start;
end