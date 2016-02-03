# @param {Integer} x
# @return {Integer}
def my_sqrt(x)
    return x if x < 2
    l = 0
    r = x
    while l < r do
        m = l + (r - l) / 2
        if m <= x / m then
            l = m + 1
        else
            r = m
        end
    end
    return l - 1
end
