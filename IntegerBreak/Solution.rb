def my_pow(x, n)
    return 1 if n == 0
    remain = 1
    cur = x
    while n > 1 do
        remain *= cur if n % 2 == 1
        cur *= cur
        n >>= 1
    end
    return cur * remain
end

# @param {Integer} n
# @return {Integer}
def integer_break(n)
    return 1 if n == 2
    return 2 if n == 3
    return my_pow(3, n / 3) if n % 3 == 0
    return my_pow(3, n / 3 - 1) * 4 if n % 3 == 1
    return my_pow(3, n / 3) * 2 if n % 3 == 2
end
