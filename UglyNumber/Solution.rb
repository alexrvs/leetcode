# @param {Integer} num
# @return {Boolean}
def is_ugly(num)
    return false if num <= 0
    [2, 3, 5].each do |x| while num % x == 0 do num /= x end end
    return true if num < 7 else return false
end
