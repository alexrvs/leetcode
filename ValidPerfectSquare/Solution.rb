# @param {Integer} num
# @return {Boolean}
def is_perfect_square(num)
    return true if num <= 1
    l = 0
    r = num / 2
    while l < r do
        m = l + (r - l) / 2
        if m < num / m then
            l = m + 1
        else
            r = m
        end
    end
    return (l == num / l && 0 == num % l)
end
