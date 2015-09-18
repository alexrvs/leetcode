# @param {Integer} n
# @return {Boolean}
def is_happy(n)
    used = []
    while n > 100 || (not used.include? n)
        used << n if n <= 100
        sum = 0
        while n > 0
            d = n % 10
            sum += d * d
            n /= 10
        end
        return true if sum == 1
        n = sum
    end
    return false
end
