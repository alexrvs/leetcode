# @param {Integer[]} a
# @return {Integer}
def max_rotate_function(a)
    sum = 0
    total = 0
    a.each_with_index do | n, i |
        total += n
        sum += i * n
    end
    size = a.length
    max = sum
    1.upto(size - 1) do | i |
        sum += total - size * a[size - i]
        max = sum if max < sum
    end
    return max
end
