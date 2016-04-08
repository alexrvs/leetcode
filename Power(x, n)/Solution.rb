# @param {Float} x
# @param {Integer} n
# @return {Float}
def my_pow(x, n)
    return 1.0 if n == 0
    remain = 1.0
    cur = x
    if n < 0 then
        n = -n
        cur = 1.0 / cur
    end
    while n > 1 do
        remain *= cur if n % 2 == 1
        cur *= cur
        n >>= 1
    end
    return cur * remain
end
